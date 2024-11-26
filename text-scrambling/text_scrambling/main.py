"""Detect the text in the diagram and replace it with random technobabble."""

import argparse
import dataclasses
import pathlib
import random
import sys
from typing import List, Sequence, Optional, Tuple

import cv2
import keras_ocr
import numpy as np
import networkx.utils.union_find
from icontract import ensure, require

WORDS_LIST = [
    'API', 'CPU', 'RAM', 'SSD', 'HDD', 'GPU', 'IDE', 'CLI', 'GUI', 'DNS',
    'TCP', 'UDP', 'FTP', 'SSH', 'IPV', 'LAN', 'WAN', 'USB', 'WWW', 'MAC',
    'OSX', 'IOS', 'DOS', 'XML', 'PDF', 'PNG', 'GIF', 'CSV', 'SQL', 'DNS',
    'NFS', 'HTML', 'CSS', 'SDK', 'DPI', 'EEP', 'ROM', 'BIOS', 'TCP', 'SAS',
    'PHP', 'API', 'JVM', 'SSH', 'JSON', 'YML', 'CPL', 'ASP', 'VMX', 'AIX',
    'ICQ', 'OOP', 'IOT', 'DOS', 'WWW', 'VPN', 'SSH', 'JDK', 'KVM', 'SIP',
    'NAT', 'RDP', 'CDN', 'CMS', 'IIS', 'VPS', 'ACL', 'NOC', 'SDK', 'CPU',
    'RDS', 'PIP', 'LVM', 'IAM', 'DVR', 'AES', 'CRT', 'RSA', 'NLP', 'SQL',
    'MLB', 'DNN', 'AIK', 'WAF', 'EDI', 'XSS', 'VNC', 'EHR', 'ERP', 'IVR',
    'NTP', 'DNS', 'MFA', 'DRM', 'LTE', 'IoT', 'MIM', 'ATM', 'PPT', 'PPP',
    'DAC', 'SLA', 'TLD', 'WAP', 'IPX', 'EXE'
]


def select_random_words(count: int) -> List[str]:
    """Pick a random selection of words from a pre-defined list."""
    shuffled = WORDS_LIST[:]
    random.shuffle(shuffled)
    return shuffled[:count]


@dataclasses.dataclass
class Box:
    xmin: int
    ymin: int
    xmax: int
    ymax: int


def compute_box_with_padding(box: Box, percentage: float) -> Box:
    """Add padding to the box."""
    width = box.xmax - box.xmin + 1
    new_xmin = box.xmin - int(round(percentage * width))
    new_xmax = box.xmax + int(round(percentage * width))

    height = box.ymax - box.ymin + 1
    new_ymin = box.ymin - int(round(percentage * height))
    new_ymax = box.ymax + int(round(percentage * height))

    return Box(
        xmin=new_xmin,
        xmax=new_xmax,
        ymin=new_ymin,
        ymax=new_ymax
    )


def boxes_intersect(that: Box, other: Box) -> bool:
    """Check whether two rectangles intersect without any padding."""
    return (
            (that.xmin <= other.xmax)
            and (other.xmin <= that.xmax)
            and (that.ymin <= other.ymax)
            and (other.ymin <= that.ymax)
    )


def boxes_intersect_with_padding(that: Box, other: Box) -> bool:
    """
    Check whether two rectangles intersect with some padding.

    This is useful so that we can join detected words across underscores and whitespace.

    >>> boxes_intersect_with_padding(
    ...     Box(xmin=834, ymin=197, xmax=968, ymax=219),
    ...     Box(xmin=332, ymin=211, xmax=787, ymax=268)
    ... )
    False
    """
    that_box_with_padding = compute_box_with_padding(that, percentage=0.05)
    other_box_with_padding = compute_box_with_padding(other, percentage=0.05)

    return (
            (that_box_with_padding.xmin <= other_box_with_padding.xmax)
            and (other_box_with_padding.xmin <= that_box_with_padding.xmax)
            and (that_box_with_padding.ymin <= other_box_with_padding.ymax)
            and (other_box_with_padding.ymin <= that_box_with_padding.ymax)
    )


def join_boxes(that: Box, other: Box) -> Box:
    """Join two rectangles so that the union covers all the area."""
    return Box(
        xmin=min(that.xmin, other.xmin),
        ymin=min(that.ymin, other.ymin),
        xmax=max(that.xmax, other.xmax),
        ymax=max(that.ymax, other.ymax),
    )


# fmt: off
@require(
    lambda boxes, predicted_texts: len(boxes) == len(predicted_texts)
)
@ensure(
    lambda result:
    all(
        not boxes_intersect(box, another_box)
        for i, box in enumerate(result)
        for j, another_box in enumerate(result)
        if i != j
    ),
    "The resulting boxes should not have any intersections."
)
# fmt: on
def suppress(
        boxes: Sequence[Box],
        predicted_texts: Sequence[str]
) -> List[Box]:
    """Join all the overlapping text boxes together."""
    groups = []  # type: List[Tuple[int, int]]
    for i, box in enumerate(boxes):
        groups.append((i, i))

        predicted_text = predicted_texts[i]

        character_width = round((box.xmax - box.xmin) / len(predicted_text))
        assert character_width >= 0

        box_with_padding = Box(
            xmin=box.xmin,
            # NOTE (mristin):
            # We add one character to the right to account for underscores
            # and whitespace.
            xmax=box.xmax + character_width,
            ymin=box.ymin,
            # NOTE (mristin):
            # We add some extension below to account for multiple lines.
            ymax=round(1.02 * box.ymax)
        )

        # NOTE (mristin):
        # We need to compare all boxes against each other as the expansion is not
        # commutative.
        for j in range(0, len(boxes)):
            if i == j:
                continue

            another_box = boxes[j]

            # NOTE (mristin):
            # We add this check to facilitate future debugging.
            if boxes_intersect(that=box, other=another_box):
                assert boxes_intersect(box_with_padding, another_box)

            if boxes_intersect(that=box_with_padding, other=another_box):
                groups.append((i, j))

    union_find = networkx.utils.UnionFind()
    for group in groups:
        union_find.union(group[0], group[1])

    result = []  # type: List[Box]

    for box_set in union_find.to_sets():
        merged_box = None  # type: Optional[Box]
        for box_i in box_set:
            if merged_box is None:
                merged_box = boxes[box_i]
            else:
                merged_box = join_boxes(
                    that=merged_box,
                    other=boxes[box_i]
                )

        assert merged_box is not None

        for another_merged_box in result:
            if boxes_intersect(another_merged_box, merged_box):
                raise AssertionError(
                    "Something went wrong. Two merged boxes intersect: "
                    f"{merged_box=}, {another_merged_box=}"
                )

        result.append(merged_box)

    return result


def detect_and_replace_text(
        image_path: pathlib.Path, output_path: pathlib.Path
) -> None:
    """Detect the texts in the image and replace them with some random labels."""
    print(f"Converting: {image_path} -> {output_path}...")
    image = keras_ocr.tools.read(str(image_path))

    pipeline = keras_ocr.pipeline.Pipeline()
    prediction_groups = pipeline.recognize([image])

    image_bgr = cv2.cvtColor(image, cv2.COLOR_RGB2BGR)

    bounding_boxes = []  # type: List[Box]
    predicted_texts = []  # type: List[str]
    for prediction in prediction_groups[0]:
        predicted_text = prediction[0]

        predicted_texts.append(predicted_text)

        box_as_array = prediction[1]

        assert isinstance(box_as_array, np.ndarray)
        assert box_as_array.shape == (4, 2)
        assert box_as_array.dtype == np.float32
        top_left = box_as_array[0]
        bottom_right = box_as_array[2]

        xmin = int(top_left[0])
        ymin = int(top_left[1])
        xmax = int(bottom_right[0])
        ymax = int(bottom_right[1])

        height = ymax - ymin

        box = Box(
            xmin=xmin,
            # NOTE (mristin):
            # We extend a little bit to the top so that we account for missed
            # text pixels in the prediction.
            ymin=max(0, round(ymin - 0.05 * height)),
            xmax=xmax,
            ymax=ymax
        )

        bounding_boxes.append(box)

    bounding_boxes = suppress(
        boxes=bounding_boxes,
        predicted_texts=predicted_texts
    )

    for i, box in enumerate(bounding_boxes):
        colour_histogram = dict()  # type: MutableMapping[Tuple[int, int, int], int]
        for y in range(box.ymin, box.ymax + 1):
            for x in range(box.xmin, box.xmax + 1):
                pixel = image_bgr[y, x]
                colour = (int(pixel[0]), int(pixel[1]), int(pixel[2]))

                if colour not in colour_histogram:
                    colour_histogram[colour] = 1
                else:
                    colour_histogram[colour] += 1

        max_colour = None  # type: Optional[Tuple[int, int, int]]
        max_count = None  # type: Optional[int]
        for colour, count in colour_histogram.items():
            if max_count is None:
                max_colour = colour
                max_count = count
            else:
                if max_count < count:
                    max_count = count
                    max_colour = colour

        assert max_colour is not None, f"Unexpected no colour for bounding box {box}"

        # Draw the polygon on the mask
        cv2.rectangle(
            image_bgr,
            (box.xmin, box.ymin),
            (box.xmax, box.ymax),
            max_colour,
            -1
        )

    random_labels = select_random_words(count=len(bounding_boxes))

    for box, random_label in zip(bounding_boxes, random_labels):
        width = box.xmax - box.xmin + 1
        height = box.ymax - box.ymin + 1

        text_width = None
        text_height = None

        while True:
            # Choose font and scale based on the bounding box height
            font_scale = height / 25
            font = cv2.FONT_HERSHEY_SIMPLEX
            thickness = 1

            # Get the text size (width and height)
            text_size = cv2.getTextSize(
                text=random_label,
                fontFace=font,
                fontScale=font_scale,
                thickness=thickness
            )[0]
            text_width, text_height = text_size

            if text_width < width:
                break

            if len(random_label) == 1:
                break

            random_label = random_label[:-1]

        assert text_width is not None
        assert text_height is not None

        # Calculate the position to centralize the text
        text_x = box.xmin + (width - text_width) // 2  # Center horizontally
        text_y = box.ymin + (height + text_height) // 2  # Center vertically

        # Add random text to the image (black color)
        cv2.putText(
            img=image_bgr,
            text=random_label,
            org=(text_x, text_y),
            fontFace=font,
            fontScale=font_scale,
            color=(0, 0, 0),
            thickness=thickness,
            lineType=cv2.LINE_AA,
        )

    output_path.parent.mkdir(exist_ok=True)
    cv2.imwrite(str(output_path), image_bgr)


def main() -> int:
    """Execute the main routine."""
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "--input_dir",
        help="Path to the directory containing the original diagrams",
        required=True,
    )
    parser.add_argument(
        "--output_dir", help="Path to the scrambled diagrams", required=True
    )
    args = parser.parse_args()

    input_dir = pathlib.Path(args.input_dir)
    output_dir = pathlib.Path(args.output_dir)

    for pth in sorted(pth for pth in input_dir.iterdir() if pth.is_file()):
        output_path = output_dir / pth.name

        if output_path.exists():
            print(f"File exists, skipping: {output_path}")
        else:
            detect_and_replace_text(image_path=pth, output_path=output_dir / pth.name)

    return 0


if __name__ == "__main__":
    sys.exit(main())

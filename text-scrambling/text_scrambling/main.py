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



def boxes_intersect(that: Box, other: Box) -> bool:
    """Check whether two rectangles intersect."""
    return (
            (that.xmin <= other.xmin <= that.xmax)
            and (
                    that.ymin <= other.ymin <= that.ymax)
    )


def join_boxes(that: Box, other: Box) -> Box:
    """Join two rectangles so that the union covers all the area."""
    return Box(
        xmin=min(that.xmin, other.xmin),
        ymin=min(that.ymin, other.ymin),
        xmax=max(that.xmax, other.xmax),
        ymax=max(that.ymax, other.ymax),
    )

def suppress(boxes: Sequence[Box]) -> List[Box]:
    """Join all the overlapping boxes together."""
    groups = []  # type: List[Tuple[int, int]]
    for i, box in enumerate(boxes):
        groups.append((i, i))

        for j in range(i + 1, len(boxes)):
            another_box = boxes[j]

            if boxes_intersect(that=box, other=another_box):
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
    for prediction in prediction_groups[0]:
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

        # NOTE (mristin):
        # We widen the box a little bit to account for underscores.
        width = xmax - xmin + 1
        xmin -= int(round(0.2 * width))
        xmax += int(round(0.2 * width))

        box = Box(
            xmin=xmin,
            ymin=ymin,
            xmax=xmax,
            ymax=ymax
        )

        bounding_boxes.append(box)

    bounding_boxes = suppress(bounding_boxes)

    for box in bounding_boxes:
        # Draw the polygon on the mask
        cv2.rectangle(
            image_bgr,
            (box.xmin, box.ymin),
            (box.xmax, box.ymax),
            (255, 255, 255),
            -1
        )

    random_labels = select_random_words(count=len(bounding_boxes))

    assert len(random_labels) == len(bounding_boxes)

    for box, random_label in zip(bounding_boxes, random_labels):
        width = box.xmax - box.xmin + 1
        height = box.ymax - box.ymin + 1

        # Choose font and scale based on the bounding box height
        font_scale = height / 25
        font = cv2.FONT_HERSHEY_SIMPLEX
        thickness = 1

        # Get the text size (width and height)
        text_size = cv2.getTextSize(
            text=random_label, fontFace=font, fontScale=font_scale, thickness=thickness
        )[0]
        text_width, text_height = text_size

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
        detect_and_replace_text(image_path=pth, output_path=output_dir / pth.name)

    return 0


if __name__ == "__main__":
    sys.exit(main())

"""Evaluate the inference against the ground-truth."""
import argparse
import collections
import pathlib
import re
import sys
from typing import MutableMapping, List

EDGE_RE = re.compile("^\s*([a-zA-Z_0-9-]+)\s*-+\s*>\s*([a-zA-Z_0-9-]+)\s*$")

def make_uniform(diagram_text: str) -> str:
    """Make the diagram edges into a uniform representation."""
    uniform_lines = []  # type: List[str]

    for i, line in enumerate(diagram_text.splitlines()):
        match = EDGE_RE.match(line)
        if match is None:
            raise ValueError(f"Invalid line {i+1}: {line!r}")

        source = match.group(1)
        target = match.group(2)

        uniform_lines.append(f"{source} -> {target}")

    return "\n".join(uniform_lines)



def main()->int:
    """Execute the main routine."""
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--ground_truth_dir", help="Directory containing ground truth files.", required=True)
    parser.add_argument("--inference_dir", help="Directory containing inference files.", required=True)
    parser.add_argument("--evaluation_dir", help="Directory containing evaluation report.", required=True)
    args = parser.parse_args()

    ground_truth_dir = pathlib.Path(args.ground_truth_dir)
    inference_dir = pathlib.Path(args.inference_dir)
    evaluation_dir = pathlib.Path(args.evaluation_dir)

    # Map diagram ID --> ground-truth edges
    ground_truth = collections.OrderedDict()  # type: MutableMapping[str, str]

    # Map diagram ID --> inferred edges
    inference = collections.OrderedDict()  # type: MutableMapping[str, str]

    for ground_truth_file in sorted(ground_truth_dir.iterdir()):
        ground_truth_text = ground_truth_file.read_text(encoding="utf-8")

        try:
            ground_truth_text = make_uniform(ground_truth_text)
        except ValueError as error:
            print(f"Invalid diagram {ground_truth_file}: {error}", file=sys.stderr)
            return 1

        ground_truth[ground_truth_file.stem] = ground_truth_text

    for inference_file in sorted(inference_dir.iterdir()):
        inference_text = inference_file.read_text(encoding="utf-8")

        try:
            inference_text = make_uniform(inference_text)
        except ValueError as error:
            print(f"Invalid diagram {inference_file}: {error}", file=sys.stderr)
            return 1

        inference[inference_file.stem] = inference_text

    hits = 0
    total_count = 0

    missed_diagrams = []  # type: List[str]

    for diagram_id in ground_truth:
        ground_truth_text = ground_truth[diagram_id]
        inference_text = inference[diagram_id]

        if ground_truth_text == inference_text:
            hits += 1
        else:
            missed_diagrams.append(diagram_id)

        total_count += 1

    evaluation_dir.mkdir(exist_ok=True, parents=True)
    (evaluation_dir / "hit_rate.txt").write_text(str(round(hits/total_count, 2)), encoding="utf-8")
    (evaluation_dir / "missed_diagrams.txt").write_text("\n".join(missed_diagrams), encoding="utf-8")


if __name__ == '__main__':
    sys.exit(main())
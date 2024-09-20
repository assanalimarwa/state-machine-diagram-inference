import os
import pathlib
import subprocess
import sys


def main() -> int:
    """Execute the main routine."""
    this_path = pathlib.Path(os.path.realpath(__file__))
    this_dir = this_path.parent

    size = "tiny"
    llm = "chatgpt"

    diagrams_dir = this_dir.parent / f"data.{size}/images"
    inference_dir = this_dir.parent / f"inferred.{size}/{llm}"
    ground_truth_dir = this_dir.parent / f"data.{size}/ground-truth"
    evaluation_dir = this_dir.parent / f"evaluation.{size}.{llm}"

    subprocess.call(
        [
            sys.executable,
            str(this_dir / f"run_{llm}.py"),
            "--diagrams_dir",
            str(diagrams_dir),
            "--inference_dir",
            str(inference_dir),
        ]
    )

    subprocess.call(
        [
            sys.executable,
            str(this_dir / f"evaluate.py"),
            "--ground_truth_dir",
            str(ground_truth_dir),
            "--inference_dir",
            str(inference_dir),
            "--evaluation_dir",
            str(evaluation_dir),
        ]
    )

    return 0


if __name__ == "__main__":
    sys.exit(main())
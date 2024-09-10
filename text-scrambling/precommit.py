"""Run the pre-commit on all the files."""

import argparse
import os
import pathlib
import subprocess
import sys


def main() -> int:
    """Execute the main routine."""
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "--overwrite", help="Auto-heal, where possible", action="store_true"
    )
    args = parser.parse_args()

    overwrite = bool(args.overwrite)

    this_path = pathlib.Path(os.path.realpath(__file__))

    python_files = [str(pth) for pth in sorted(this_path.parent.glob("*.py"))]

    subprocess.check_call(
        ["black", "--check"] + python_files
        if not overwrite
        else ["black"] + python_files
    )

    subprocess.check_call(["mypy"] + python_files)

    subprocess.check_call(["pylint"] + python_files)

    return 0


if __name__ == "__main__":
    sys.exit(main())

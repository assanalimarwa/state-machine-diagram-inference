"""Infer the graphs using ChatGPT."""

import argparse
import base64
import pathlib
import sys

def main() -> int:
    """Execute the main routine."""
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--diagrams_dir", help="Directory containing diagrams.", required=True)
    parser.add_argument("--inference_dir", help="Directory containing inferences.", required=True)
    parser.add_argument("--api_key_path", help="File containing the ChatGPT API key.", required=True)
    args = parser.parse_args()

    diagrams_dir = pathlib.Path(args.diagrams_dir)
    inference_dir = pathlib.Path(args.inference_dir)
    api_key_path = pathlib.Path(args.api_key_path)

    api_key = api_key_path.read_text(encoding="utf-8")

    for diagram_pth in sorted(diagrams_dir.iterdir()):
        inference_pth = inference_dir / f"{diagram_pth.stem}.txt"

        if inference_pth.exists():
            print(f"File exists: {inference_pth}; skipping.")
            continue

        prompt = (
            f"Infer the nodes and edges of the given graph. The output should contain no text, but only edges, "
            f"in the form 'node1 -> node2'.\n"
            f"\n"
            f"For example: "
            f"node1 -> node2\n"
            f"node1 -> node1\n"
            f"node2 -> node1"
        )

        diagram_bytes = diagram_pth.read_bytes()
        diagram_base64_str = base64.b64encode(diagram_bytes).decode(encoding='ascii')

        # TODO: call ChatGPT with the given prompt

        answer = "TODO"

        inference_pth.write_text(answer, encoding='utf-8')

    return 0

if __name__ == '__main__':
    sys.exit(main())
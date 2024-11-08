"""Infer edges of a state diagram."""

import argparse
import base64
import pathlib
import sys

import openai

from infer_edges_and_generate_test_code.common import extract_edges


def main() -> int:
    """Execute the main routine."""
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--image_path", help="Path to the diagram image", required=True)
    parser.add_argument(
        "--chatgpt_api_key_path",
        help="Path to the file containing ChatGPT API key",
        required=True
    )
    parser.add_argument(
        "--output_path",
        help="Path to the file to store the results; if '-', write to STDOUT",
        default='-'
    )
    args = parser.parse_args()

    image_path = pathlib.Path(args.image_path)
    chatgpt_api_key_path = pathlib.Path(args.chatgpt_api_key_path)
    output_path = pathlib.Path(args.output_path) if args.output_path != '-' else None

    if not image_path.exists():
        print(
            f"File --image_path does not exist: {image_path}",
            file=sys.stderr
        )
        return 1

    if not image_path.is_file():
        print(
            f"Path --image_path is not a file: {image_path}",
            file=sys.stderr
        )
        return 1

    if not chatgpt_api_key_path.exists():
        print(
            f"File --chatgpt_api_key_path does not exist: {chatgpt_api_key_path}",
            file=sys.stderr
        )
        return 1

    if not chatgpt_api_key_path.is_file():
        print(
            f"Path --chatgpt_api_key_path is not a file: {chatgpt_api_key_path}",
            file=sys.stderr
        )
        return 1

    api_key = chatgpt_api_key_path.read_text(encoding='utf-8').strip()

    client = openai.OpenAI(api_key=api_key)

    # Encode the image
    base64_image = base64.b64encode(image_path.read_bytes()).decode('utf-8')
    assert isinstance(base64_image, str)

    try:
        response = client.chat.completions.create(
            model="gpt-4o-2024-08-06",
            messages=[
                {
                    "role": "user",
                    "content": [
                        {
                            "type": "text",
                            "text": (
                                "Infer the nodes and edges of the given graph. "
                                "The output should contain no text, but only edges "
                                "in the form 'node1 -> node2'. "
                                "For example:\n"
                                "node1 -> node2\n"
                                "node1 -> node1\n"
                                "\n"
                                "Only use directed arrows: ->"
                            )
                        },
                        {
                            "type": "image_url",
                            "image_url": {
                                "url": f"data:image/png;base64,{base64_image}"
                            }
                        }
                    ]
                }
            ],
            max_tokens=300
        )

        chatgpt_content = response.choices[0].message.content

    except Exception as e:
        print(
            f"Something went wrong when calling ChatGPT: {str(e)}",
            file=sys.stderr
        )
        return 1

    edges = extract_edges(chatgpt_content)

    if len(edges) == 0:
        print("There were no edges inferred.", file=sys.stderr)
        return 0

    if output_path is None:
        output = sys.stdout
        fid = None
    else:
        output_path.parent.mkdir(exist_ok=True, parents=True)
        fid = output_path.open("wt")
        output = fid

    try:
        for node, neighbors in edges.items():
            for neighbor in neighbors:
                print(f"{node} -> {neighbor}", file=output)
    finally:
        if fid is not None:
            fid.close()

    return 0


if __name__ == "__main__":
    sys.exit(main())

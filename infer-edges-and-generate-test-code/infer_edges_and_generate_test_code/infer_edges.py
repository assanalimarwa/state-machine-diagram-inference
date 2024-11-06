"""Infer edges of a state diagram."""

import argparse
import os
import base64
import re
from typing import List

import requests
import pathlib
import sys

import openai
from openai import OpenAI

EDGE_RE = re.compile(r'^\s*(?P<source>.+)\s*-+>\s*(?P<target>.+)\s*$')


def extract_edges(text: str) -> List[str]:
    result = []  # type: List[str]

    for line in text.splitlines():
        stripped = line.strip()
        if len(stripped) == 0:
            continue

        match = EDGE_RE.match(stripped)
        if match is None:
            continue

        source = match.group("source")
        target = match.group("target")

        result.append(f"{source} -> {target}")

    return result


def main() -> int:
    """Execute the main routine."""
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--image_path", help="Path to the diagram image", required=True)
    parser.add_argument(
        "--chatgpt_api_key_path",
        help="Path to the file containing ChatGPT API key",
        required=True
    )
    args = parser.parse_args()

    image_path = pathlib.Path(args.image_path)
    chatgpt_api_key_path = pathlib.Path(args.chatgpt_api_key_path)

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

    for edge in edges:
        print(edge)

    return 0


if __name__ == "__main__":
    sys.exit(main())

#! /usr/bin/env python3

"""Generate the source code based on the edges."""

import argparse
import pathlib
import sys

from infer_edges_and_generate_test_code.common import AdjacencyMat, extract_edges


def generate_code(mat: AdjacencyMat) -> None:
    all_nodes = set(mat.keys())
    for neighbors in mat.values():
        for neighbor in neighbors:
            all_nodes.add(neighbor)
    initial_state = next(iter(mat.keys()))

    print("#include <stdexcept>")
    print()

    print("enum class State")
    print("{")
    for node in all_nodes:
        print(f"  {node},")
    print("};")
    print()

    print("std::string format_state(State const state)")
    print("{")
    print(f"  switch(state)")
    print("  {")
    for node in all_nodes:
        print(f"    case State::{node}:")
        print(f'      return "{node}";')
    print("  }")
    print('  return "?";')
    print("}")
    print()

    for node, neighbors in mat.items():
        print(f"State handle_{node}(State const new_state)")
        print("{")
        print("  switch(new_state)")
        print("  {")
        for neighbor in neighbors:
            print(f"  case State::{neighbor}:")
            print("      // TODO")
            print(f"      return State::{node};")
        print("  default:")
        print(f'    throw std::runtime_error("Unknown state transition {node} -> " + format_state(new_state));')
        print("  }")
        print("}")
        print()

    print("State handle_state(State const last_state, State const new_state)")
    print("{")
    print("  switch(last_state)")
    print("  {")
    for node in all_nodes:
        print(f"  case State::{node}:")
        print(f"      return handle_{node}(new_state);")
    print("  default:")
    print('    throw std::runtime_error("Unknown state " + format_state(last_state));')
    print("  }")
    print("}")
    print()

    print("int main()")
    print("{")
    print(f"  State last_state = State::{initial_state};")
    print("  for(;;)")
    print("   {")
    print(f"      auto new_state = State::{initial_state}; // TODO")
    print("      last_state = handle_state(last_state, new_state);")
    print("   }")
    print("}")


def main() -> int:
    """Execute the main routine."""
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "--input_path",
        help="Path to the file containing the edges; if '-', read from STDIN",
        required=True
    )
    args = parser.parse_args()

    input_path = (
        pathlib.Path(args.input_path)
        if args.input_path != '-'
        else None
    )

    if input_path is None:
        text = sys.stdin.read()
    else:
        text = input_path.read_text(encoding='utf-8')

    adjacency_matrix = extract_edges(text)
    if len(adjacency_matrix) == 0:
        return 0

    generate_code(adjacency_matrix)

    return 0


if __name__ == "__main__":
    sys.exit(main())

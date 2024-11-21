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
    print("struct Event")
    print("{")
    print("};")
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
        print(f"State handle_{node}(Event const & event)")
        print("{")
        print("  // Check the event and return one of the following states:")
        for neighbor in neighbors:
            print(f"  // - {neighbor}")
        print(f"  return State::{node};")
        print("}")
        print()

    print("State handle_event(State const last_state, Event const & event)")
    print("{")
    print("  switch(last_state)")
    print("  {")
    for node in all_nodes:
        print(f"  case State::{node}:")
        print(f"    return handle_{node}(event);")
    print("  default:")
    print('    throw std::runtime_error("Unknown state " + format_state(last_state));')
    print("  }")
    print("}")
    print()

    print("Event wait_for_event()")
    print("{")
    print("  // TODO fetch next event")
    print(f"  return Event();")
    print("}")
    print()

    print("int main()")
    print("{")
    print(f"  State state = State::{initial_state};")
    print("  for(;;)")
    print("  {")
    print(f"    auto event = wait_for_event();")
    print("    state = handle_event(state, event);")
    print("  }")
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

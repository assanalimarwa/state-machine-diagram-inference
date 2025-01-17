#! /usr/bin/env python3

"""Generate the source code based on the edges."""

import argparse
import pathlib
import sys
from typing import List

from infer_edges_and_generate_test_code.common import AdjacencyMat, extract_edges, analyze


def generate_code(mat: AdjacencyMat) -> List[str]:
    initial_state, all_nodes = analyze(mat)
    ret = []

    ret.append("#include <stdexcept>")
    ret.append("struct Event")
    ret.append("{")
    ret.append("};")
    ret.append("")

    ret.append("enum class State")
    ret.append("{")
    for node in all_nodes:
        ret.append(f"  {node},")
    ret.append("};")
    ret.append("")

    ret.append("std::string format_state(State const state)")
    ret.append("{")
    ret.append(f"  switch(state)")
    ret.append("  {")
    for node in all_nodes:
        ret.append(f"    case State::{node}:")
        ret.append(f'      return "{node}";')
    ret.append("  }")
    ret.append('  return "?";')
    ret.append("}")
    ret.append("")

    for node, neighbors in mat.items():
        ret.append(f"State handle_{node}(Event const & event)")
        ret.append("{")
        ret.append("  // Check the event and return one of the following states:")
        for neighbor in neighbors:
            ret.append(f"  // - {neighbor}")
        ret.append(f"  return State::{node};")
        ret.append("}")
        ret.append("")

    ret.append("State handle_event(State const last_state, Event const & event)")
    ret.append("{")
    ret.append("  switch(last_state)")
    ret.append("  {")
    for node in all_nodes:
        ret.append(f"  case State::{node}:")
        ret.append(f"    return handle_{node}(event);")
    ret.append("  default:")
    ret.append('    throw std::runtime_error("Unknown state " + format_state(last_state));')
    ret.append("  }")
    ret.append("}")
    ret.append("")

    ret.append("Event wait_for_event()")
    ret.append("{")
    ret.append("  // TODO fetch next event")
    ret.append(f"  return Event();")
    ret.append("}")
    ret.append("")

    ret.append("int main()")
    ret.append("{")
    ret.append(f"  State state = State::{initial_state};")
    ret.append("  for(;;)")
    ret.append("  {")
    ret.append(f"    auto event = wait_for_event();")
    ret.append("    state = handle_event(state, event);")
    ret.append("  }")
    ret.append("}")

    return ret


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

    lines = generate_code(adjacency_matrix)
    for line in lines:
        print(line)

    return 0


if __name__ == "__main__":
    sys.exit(main())

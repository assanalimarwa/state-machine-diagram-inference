#! /usr/bin/env python3

"""Generate the tests based on the edges."""
import argparse
import pathlib
import sys
from typing import List, Iterator

import networkx as nx

from infer_edges_and_generate_test_code.common import AdjacencyMat, extract_edges, analyze
Path = List[str]


def generate_paths(mat: AdjacencyMat) -> Iterator[Path]:
    graph = nx.DiGraph()
    for node, neighbors in mat.items():
        graph.add_node(node)
        for neighbor in neighbors:
            graph.add_edge(node, neighbor)
    start_node = next(iter(mat.keys()))
    for node in graph.nodes:
        try:
            yield (
                node,
                nx.shortest_path(graph, start_node, node) +
                nx.shortest_path(graph, node, start_node)[1:]
            )
        except nx.NetworkXNoPath:
            continue


def print_test(initial_state: str, target: str, path: Path):
    print(f"TEST(App, {target})")
    print("{")
    print(f"  // CHeck path {path}")
    print("  Event event;")
    print(f"  auto state = State::{initial_state};")
    for node in path:
        print("  // TODO: fill event appropriately")
        print("  state = handle_event(state, event);")
        print(f"  ASSERT_EQ(state, State::{node});")
    print("}")
    print()


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

    initial_state, all_nodes = analyze(adjacency_matrix)

    print("#include <gtest/gtest.h>")
    print("struct Event{};")
    print("enum class State")
    print("{")
    for node in all_nodes:
        print(f"  {node},")
    print("};")
    print("State handle_event(State const state, Event const & evnet);")
    print()

    for target, path in generate_paths(adjacency_matrix):
        print_test(initial_state, target, path)

    return 0


if __name__ == "__main__":
    sys.exit(main())

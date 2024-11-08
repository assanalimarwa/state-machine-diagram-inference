#! /usr/bin/env python3

"""Generate the tests based on the edges."""
import argparse
import pathlib
import sys

import networkx as nx

from infer_edges_and_generate_test_code.common import AdjacencyMat, extract_edges


def generate_tests(mat: AdjacencyMat):
    graph = nx.DiGraph()
    for node, neighbors in mat.items():
        graph.add_node(node)
        for neighbor in neighbors:
            graph.add_edge(node, neighbor)
    start_node = next(iter(mat.keys()))
    for node in graph.nodes:
        yield (
            node,
            nx.shortest_path(graph, start_node, node) +
            nx.shortest_path(graph, node, start_node)[1:]
        )


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

    if len(adjacency_matrix) == 1:
        for source, targets in adjacency_matrix.items():
            for target in targets:
                print(f"{target}: {source} -> {target}")

        return 1

    for target, path in generate_tests(adjacency_matrix):
        print(f"{target}: {path}")

    return 0


if __name__ == "__main__":
    sys.exit(main())

#! /usr/bin/env python3

from typing import Dict, List
import networkx as nx


AdjacencyMat = Dict[str, List[str]]


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


if __name__ == "__main__":
    example = {
        'JVM': ['ERP'],
        'ERP': ['ERP', 'CDN'],
        'CDN': ['ERP', 'CDN', 'USB', 'WWW'],
        'USB': ['USB', 'LTE', 'ERP', 'WWW'],
        'LTE': ['LTE', 'WWW', 'ERP', 'CDN'],
        'WWW': ['WWW', 'ERP', 'CDN', 'JVM'],
    }
    for target, path in generate_tests(example):
        print(f"{target}: {path}")

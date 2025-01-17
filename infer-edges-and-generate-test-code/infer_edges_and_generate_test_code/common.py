import re
from collections import defaultdict
from typing import Dict, List, Tuple

AdjacencyMat = Dict[str, List[str]]

EDGE_RE = re.compile(r'^\s*(?P<source>.+)\s*-+>\s*(?P<target>.+)\s*$')


def extract_edges(text: str) -> AdjacencyMat:
    """
    Extract the edges from the text as retrieved from ChatGPT.

    >>> dict(extract_edges(''))
    {}

    >>> dict(extract_edges('AAS -> VWS'))
    {'AAS': ['VWS']}

    >>> dict(extract_edges('AAS -> VWS\\nVWS -> AAS'))
    {'AAS': ['VWS'], 'VWS': ['AAS']}
    """
    result = defaultdict(list)

    for line in text.splitlines():
        stripped = line.strip()
        if len(stripped) == 0:
            continue

        match = EDGE_RE.match(stripped)
        if match is None:
            continue

        source = match.group("source").strip()
        target = match.group("target").split(",")[0].strip()

        result[source].append(target)

    return result


def analyze(mat: AdjacencyMat) -> Tuple[str, List[str]]:
    """
    Analyze an adjaciency matrix to obtain:
    - the initial state
    - a list of all nodes

    >>> analyze({'a': ['b', 'c']})
    ('a', ['a', 'b', 'c'])
    """
    all_nodes = set(mat.keys())
    for neighbors in mat.values():
        for neighbor in neighbors:
            all_nodes.add(neighbor)
    initial_state = next(iter(mat.keys()))
    return initial_state, all_nodes

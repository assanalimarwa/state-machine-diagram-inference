#! /usr/bin/env python3

from typing import Dict, List

AdjacencyMat = Dict[str, List[str]]


def generate_code(mat: AdjacencyMat):
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


# Try out using  ./generate_code.py  > sample.cpp && g++ sample.cpp
if __name__ == "__main__":
    example = {
        'JVM': ['ERP'],
        'ERP': ['ERP', 'CDN'],
        'CDN': ['ERP', 'CDN', 'USB', 'WWW'],
        'USB': ['USB', 'LTE', 'ERP', 'WWW'],
        'LTE': ['LTE', 'WWW', 'ERP', 'CDN'],
        'WWW': ['WWW', 'ERP', 'CDN'],
    }
    generate_code(example)


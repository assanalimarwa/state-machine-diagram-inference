#! /usr/bin/env python3

import sys
import os
from infer_edges_and_generate_test_code.common import extract_edges
from infer_edges_and_generate_test_code.generate_code import generate_code
from infer_edges_and_generate_test_code.generate_tests import generate_tests


def generate(root_dir: str):
    input_dir = os.path.join(root_dir, "ground-truth")
    code_dir = os.path.join(root_dir, "code")
    tests_dir = os.path.join(root_dir, "tests")
    lines_tests = 0
    lines_code = 0
    for filename in os.listdir(input_dir):
        if filename.endswith('.txt'):
            in_file = os.path.join(input_dir, filename)
            cppname = os.path.splitext(filename)[0] + ".cpp"
            test_file = os.path.join(tests_dir, cppname)
            code_file = os.path.join(code_dir, cppname)
            print(f"Processing file: {in_file}")
            print(f"            code: {code_file}")
            print(f"           tests: {test_file}")
            # Open and process the file
            with open(in_file, 'r') as file:
                content = file.read()
                mat = extract_edges(content)
            lines = generate_code(mat)
            with open(code_file, "w") as file:
                for line in lines:
                    file.write(line + "\n")
                    lines_code += 1
            lines = generate_tests(mat)
            with open(test_file, "w") as file:
                for line in lines:
                    file.write(line + "\n")
                    lines_tests += 1
    return lines_code, lines_tests

def main():
    script_path = os.path.dirname(os.path.realpath(__file__))
    opcua_path = os.path.join(script_path, "..", "..", "data", "opcua-scrambled")
    lines_code_opcua, lines_tests_opcua = generate(opcua_path)
    profinet_path = os.path.join(script_path, "..", "..", "data", "profinet-scrambled")
    lines_code_profinet, lines_tests_profinet = generate(profinet_path)
    print("         LoC Code  | LoC Tests")
    print(f"OpcUa:    {lines_code_opcua:>8} | {lines_tests_opcua:>8}")
    print(f"Profinet: {lines_code_profinet:>8} | {lines_tests_profinet:>8}")


if __name__ == "__main__":
    sys.exit(main())

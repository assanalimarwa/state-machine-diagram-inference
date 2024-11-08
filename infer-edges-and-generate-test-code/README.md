# Infer Edges and Generate Test Code for a State Diagram

## Installation

Create a virtual environment:

```
python -m venv venv
```

Activate it (on Windows):

```
venv/bin/Activate.bat
```

... or on Linux/Mac:

```
source venv/bin/activate
```

Install:

```
pip3 install -e .
```

## Run

Make sure you activated the virtual environment (see above).

There are two commands which you can execute:

* `infer-edges`, which outputs the edges inferred from an image,
* `generate-code`, which generates the source code for the state machine from the inferred edges,
* `generate-tests`, which generates the test cases based on the inferred edges.

Simply run these commands on the command-line.

The help is available with the `--help` argument, *e.g.*, `infer-edges --help`.

# text-scrambling

Detect the text in the diagram and replace it with random technobabble.

This is necessary so we can work on the proprietary diagrams.

## Installation

Install with pip:

```
pip install .
```

Run from the console:

```
scramble-text --help
```

## Development

To install the dependencies:

```
pip install -e .[dev]
```

To run the pre-commit checks:

```
python precommit.py
```

If you want to re-format:

```
python precommit.py --overwrite
```

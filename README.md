# algoritmi

A personal collection of algorithm implementations in C, written for learning and reference. Each algorithm lives in its own source file and (where useful) comes with an explanation of the approach, complexity, and a worked example.

This repo is a work in progress — more algorithms will be added over time.

## Contents

| Algorithm | File | Category | Time Complexity | Space Complexity |
|---|---|---|---|---|
| 0/1 Knapsack | [`knapsack.c`](./knapsack.c) | Dynamic Programming | O(n × W) | O(n × W) |

## Structure

Each algorithm is a standalone `.c` file that can be compiled and run independently. As the collection grows, related algorithms may be grouped into subfolders by category (e.g. `dp/`, `graphs/`, `sorting/`).

## Building and running

Each file can be compiled individually with `gcc`:

```bash
gcc -o knapsack knapsack.c
./knapsack
```

## Roadmap

Algorithms planned or in progress will be tracked here as they're added — categories of interest include sorting, searching, graph algorithms, and more dynamic programming problems.

## License

No license specified yet — all rights reserved by default until one is added.


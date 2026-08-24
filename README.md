# Algorithms

A collection of algorithm implementations in C, written for learning and reference.</br>
Each algorithm lives in its own source file and (where useful) comes with an explanation of the approach, complexity, and a worked example.


## Contents

| Algorithm | File | Category | Time Complexity | Space Complexity |
|---|---|---|---|---|
| 0/1 Knapsack | [`dynamic_programming/knapsack.c`](dynamic_programming/knapsack.c) | Dynamic Programming | O(n × W) | O(n × W)</br>O(W) - optimized version
|

## Structure

Each algorithm is a standalone `.c` file that can be compiled and run independently. 
-- subfolders by category (e.g. `dp/`, `graphs/`, `sorting/`).

## Building and running

Each file can be compiled individually with `gcc`:

```bash
gcc -o knapsack knapsack.c
./knapsack
```

## Roadmap

Algorithms planned or in progress will be tracked here as they're added — categories of interest include sorting, searching, graph algorithms, and more dynamic programming problems.

## Explanation

### 0/1 Knapsack
<img width="1343" height="575" alt="image" src="https://github.com/user-attachments/assets/a4c210b6-e9a8-4fa7-8cb0-6fde133406db" />




## License

No license specified yet — all rights reserved by default until one is added.


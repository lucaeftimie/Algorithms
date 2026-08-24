# Algorithms

This is a collection of algorithms which helps me learn about how to think logically and how to write code in C.  
Below you can see a contents table with the algorithms studied by me.
I used Clion as a development tool, and compiled the code using the CMake build tool.

## Contents

| Algorithm | File | Category | Time Complexity | Space Complexity |
|---|---|---|---|---|
| 0/1 Knapsack | [`dynamic_programming/knapsack.c`](dynamic_programming/knapsack.c) | Dynamic Programming | O(n × W) | O(n × W)</br>O(W) - optimized version
|

## Structure

Each algorithm is a standalone `.c` file that can be compiled and run independently.  
The algorithms are organized in folders, based on programming techniques.
```text
Algorithms/
├── dynamic_programming/
│   └── knapsack.c
│
├── greddy_algorithms/
│   └──
│
├── encoding_algorithms/
│    └── huffman_encoding.c
│
└── README.md
```
## Building and running

Each file can be compiled individually with `gcc`:

```bash
gcc -o knapsack knapsack.c
./knapsack
```

Or it can be built using CMake.
```bash
cmake commands that i don't yet know
```

## Roadmap

Algorithms planned or in progress will be tracked here as they're added — categories of interest include sorting, searching, graph algorithms, and more dynamic programming problems.

## Explanation

### 0/1 Knapsack
<img width="1343" height="575" alt="image" src="https://github.com/user-attachments/assets/a4c210b6-e9a8-4fa7-8cb0-6fde133406db" />




## License

No license specified yet — all rights reserved by default until one is added.


# Algorithms

This is a collection of algorithms which helps me learn about how to think logically and how to write code in C.  
Below you can see a contents table with the algorithms studied by me.
I used Clion as a development tool, and compiled the code using the CMake build tool.

## Contents

| Algorithm        | File                                                           | Category            | Time Complexity                                                   | Space Complexity                      |
|------------------|----------------------------------------------------------------|---------------------|-------------------------------------------------------------------|---------------------------------------|
| 0/1 Knapsack     | [`knapsack.c`](dynamic_programming/knapsack.c)                 | Dynamic Programming | O(n × W)                                                          | O(n × W)</br>O(W) - optimized version |
| Huffman Encoding | [`huffman_encoding.c`](encoding_algorithms/huffman_encoding.c) | Encoding Algorithms | O(n × logn) - create tree<br/>O(n) - encoding<br/>O(n) - decoding | O(1) - encoding<br/> O(1) - decoding  |
|

## Structure

Each algorithm is a standalone `.c` file that can be compiled and run independently.  
The algorithms are organized in folders, based on programming techniques and usage of algorithm.
```text
Algorithms/
├── dynamic_programming/
│   └── knapsack.c
│
├── encoding_algorithms/
│    └── huffman_encoding.c
│
└── README.md
```

[//]: # (├── greddy_algorithms/)

[//]: # (│   └──)
## Building and running

Each file can be compiled individually with `gcc`:

```bash
gcc -o knapsack knapsack.c
./knapsack
```

[//]: # (Or it can be built using CMake.)

[//]: # (```bash)
[//]: # (cmake commands that i don't yet know)

[//]: # (```)

## Roadmap

Algorithms planned or in progress will be tracked here as they're added — categories of interest include sorting, searching, graph algorithms, and more dynamic programming problems.

## Explanation

### 0/1 Knapsack
<img width="1343" height="575" alt="image" src="https://github.com/user-attachments/assets/a4c210b6-e9a8-4fa7-8cb0-6fde133406db" />



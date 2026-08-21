# 0/1 Knapsack Problem - Dynamic Programming

## Overview
The 0/1 Knapsack problem is a classic algorithmic problem in computer science. Given a set of items, each with a weight and a value, the objective is to determine which items to include in a knapsack so that the total weight is less than or equal to a given limit (capacity $W$), and the total value is maximized. The "0/1" property means that you cannot break an item into pieces; you must either take the whole item (1) or leave it (0).

## Dynamic Programming Approach
We solve this problem using Dynamic Programming (DP) by building a 2D table `K` bottom-up. 

### State Definition
Let `K[i][j]` represent the maximum value that can be obtained by selecting a subset of the first `i` items such that their total weight does not exceed capacity `j`.

### Base Cases
* `K[0][j] = 0` for all `0 <= j <= W` (0 items mean 0 value)
* `K[i][0] = 0` for all `0 <= i <= n` (0 capacity means we can't take any items)

### Recurrence Relation (The Formula)
For each item `i` (from 1 to `n`) and for each capacity `j` (from 1 to `W`):
1. **If the item's weight is greater than the current capacity ($w_i > j$):**
   We cannot include the item. The maximum value is the same as if we didn't have this item.
   `K[i][j] = K[i-1][j]`
2. **If the item's weight is less than or equal to the current capacity ($w_i \le j$):**
   We have a choice:
   * **Exclude the item:** The value is `K[i-1][j]`
   * **Include the item:** The value is `v_i` plus the maximum value we could get with the remaining capacity `j - w_i` using the previous items `K[i-1][j - w_i]`.
   We take the maximum of these two choices:
   `K[i][j] = max(K[i-1][j], K[i-1][j-w_i] + v_i)`

## Example Walkthrough
Consider the example discussed previously:
* **Items ($n$):** 3
* **Max Capacity ($W$):** 5
* **Weights ($wt$):** `[1, 2, 3]`
* **Values ($val$):** `[6, 10, 12]`

### The DP Table
Using the recurrence relation, we can fill out the DP table `K[i][j]`:

| `K[i][j]` | j=0 | j=1 | j=2 | j=3 | j=4 | j=5 |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **i=0** | 0 | 0 | 0 | 0 | 0 | 0 |
| **i=1** *(wt: 1, val: 6)* | 0 | 6 | 6 | 6 | 6 | 6 |
| **i=2** *(wt: 2, val: 10)*| 0 | 6 | 10 | 16 | 16 | 16 |
| **i=3** *(wt: 3, val: 12)*| 0 | 6 | 10 | 16 | 18 | 22 |

### Calculation Examples
Let's look at how specific cells are calculated to understand the logic, specifically highlighting the common pitfalls:

**Calculating `K[2][2]`:**
* We are considering item 2 (weight = 2, value = 10) at capacity 2.
* Since $w_2 \le 2$, we evaluate both choices:
  * Exclude: `K[1][2] = 6`
  * Include: `K[1][2-2] + 10 = K[1][0] + 10 = 0 + 10 = 10`
* `max(6, 10) = 10`. So, `K[2][2] = 10`.

**Calculating `K[3][5]`:**
* We are considering item 3 (weight = 3, value = 12) at capacity 5.
* Since $w_3 \le 5$, we evaluate both choices:
  * Exclude: `K[2][5] = 16`
  * Include: `K[2][5-3] + 12 = K[2][2] + 12 = 10 + 12 = 22` *(Note how this relies on the previously calculated K[2][2])*
* `max(16, 22) = 22`. So, `K[3][5] = 22`.

## Complexity
* **Time Complexity:** $\mathcal{O}(n 	imes W)$ where $n$ is the number of items and $W$ is the maximum capacity. We fill a table of size $(n+1) 	imes (W+1)$.
* **Space Complexity:** $\mathcal{O}(n 	imes W)$ to store the 2D table. *(Note: Space can be optimized to $\mathcal{O}(W)$ by only keeping the previous row in memory during iteration).*

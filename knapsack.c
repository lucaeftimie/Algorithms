#include<stdio.h>
#include<malloc.h>


// knapsack with maximum weight capacity of: W
// n items with a weight wt[i] and value val[i]
// task: determine the maximum total value you can carry in the knapsack, subject to the following rules:
//      - 0/1 constraint: you can't break an item into fractions, include the entire item or leave it behind
//      - single use: you can only use each item a maximum of one time
//      - capacity limit: sum of weights of the selected items must be less than or equal to the knapsack's capacity W

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int wt[], int val[], int n) {
    int i, w;

    int K[n + 1][W + 1];

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {

            if (i == 0 || w == 0) {
                K[i][w] = 0;

            }else if (wt[i - 1] <= w) {

                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            }

            else {
                K[i][w] = K[i - 1][w];
            }

        }
    }

    return K[n][W];
}

int main() {
    int val[] = {6, 10, 12};
    int wt[] = {1, 2, 3};
    int W = 5;

    int n = sizeof(val) / sizeof(val[0]);

    printf("Maximum value in Knapsack = %d\n", knapsack(W, wt, val ,n));

    return 0;
}
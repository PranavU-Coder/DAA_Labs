#include <stdio.h>

int knapsack(int W, int wt[], int val[], int n) {
    if (n == 0 || W == 0) return 0;
    if (wt[n-1] > W) return knapsack(W, wt, val, n-1);

    int include = val[n-1] + knapsack(W - wt[n-1], wt, val, n-1);
    int exclude = knapsack(W, wt, val, n-1);
    return (include > exclude) ? include : exclude;
}

int main() {
    int n, W;
    printf("enter number of items: ");
    scanf("%d", &n);

    int val[n], wt[n];

    printf("enter values of items:\n");
    for (int i = 0; i < n; i++) scanf("%d", &val[i]);

    printf("enter weights of items:\n");
    for (int i = 0; i < n; i++) scanf("%d", &wt[i]);

    printf("enter capacity of knapsack: ");
    scanf("%d", &W);
    int maxValue = knapsack(W, wt, val, n);
    printf("max value in knapsack = %d\n", maxValue);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int value;
    float ratio; 
} Item;

typedef struct {
    int level;
    int profit;
    int weight;
    float bound;
} Node;

int cmp(const void *a, const void *b) {
    Item *i1 = (Item *)a;
    Item *i2 = (Item *)b;
    if (i2->ratio > i1->ratio) return 1;
    else if (i2->ratio < i1->ratio) return -1;
    else return 0;
}

float bound(Node u, int n, int W, Item items[]) {
    if (u.weight >= W) return 0;

    float profit_bound = u.profit;
    int j = u.level + 1;
    int totweight = u.weight;
    while (j < n && totweight + items[j].weight <= W) {
        totweight += items[j].weight;
        profit_bound += items[j].value;
        j++;
    }
    if (j < n) {
        profit_bound += (W - totweight) * items[j].ratio;
    }

    return profit_bound;
}

int knapsack(int W, Item items[], int n) {
    qsort(items, n, sizeof(Item), cmp);

    Node u, v;
    u.level = -1;
    u.profit = 0;
    u.weight = 0;
    u.bound = bound(u, n, W, items);
    int maxProfit = 0;
    Node queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = u;

    while (front < rear) {
        u = queue[front++];
        if (u.level == n - 1) continue;
        v.level = u.level + 1;
        v.weight = u.weight + items[v.level].weight;
        v.profit = u.profit + items[v.level].value;
        if (v.weight <= W && v.profit > maxProfit)
            maxProfit = v.profit;
        v.bound = bound(v, n, W, items);
        if (v.bound > maxProfit)
            queue[rear++] = v;
        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = bound(v, n, W, items);
        if (v.bound > maxProfit)
            queue[rear++] = v;
    }

    return maxProfit;
}

int main() {
    int n, W;
    printf("Enter number of items: ");
    scanf("%d", &n);

    Item items[n];
    printf("Enter weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].weight, &items[i].value);
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    int maxProfit = knapsack(W, items, n);
    printf("Maximum profit possible = %d\n", maxProfit);

    return 0;
}

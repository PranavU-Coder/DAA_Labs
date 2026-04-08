#include <stdio.h>

#define MAX 100

int set[] = {1, 2, 5, 6, 8};
int n = 5;  
int d = 9;   

void print(int subset[], int size) {
    printf("{ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("}\n");
}
void subsetSum(int index, int currentSum, int subset[], int size) {
    if (currentSum == d) {
        print(subset, size);
        return;
    }

    if (index >= n || currentSum > d) {
        return;
    }
    subset[size] = set[index];
    subsetSum(index + 1, currentSum + set[index], subset, size + 1);
    subsetSum(index + 1, currentSum, subset, size);
}

int main() {
    int subset[MAX];
    printf("Set: {1, 2, 5, 6, 8}\n");
    printf("Target sum (d): %d\n", d);
    printf("Subsets with sum %d:\n", d);

    subsetSum(0, 0, subset, 0);

    return 0;
}

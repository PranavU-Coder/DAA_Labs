#include <stdio.h>

int main() {
    int maxWeight;
    printf("Enter the maximum weight: ");
    scanf("%d", &maxWeight);

    int nItems;
    printf("Enter the number of items: ");
    scanf("%d", &nItems);

    int values[nItems][maxWeight + 1];
    int weights[nItems][maxWeight + 1];

    for (int i = 0; i < nItems; i++) {
        for (int j = 0; j <= maxWeight; j++) {
            values[i][j] = 0;
            weights[i][j] = 0;
        }
    }

    for (int i = 0; i < nItems; i++) {
        printf("Enter the weight of item %d: ", i + 1);
        scanf("%d", &weights[i][nItems]);

        printf("Enter the value of item %d: ", i + 1);
        scanf("%d", &values[i][nItems]);
    }

    for (int j = 1; j <= maxWeight; j++) {
        for (int i = 0; i < nItems; i++) {
            if (weights[i][j] > 0) {
                values[i][j] = values[i - 1][j - weights[i][j]] + values[i][nItems];
            } else {
                values[i][j] = values[i - 1][j];
            }
        }
    }

    printf("Optimal values:\n");
    for (int j = 0; j <= maxWeight; j++) {
        printf("%d ", values[nItems - 1][j]);
    }

    return 0;
}

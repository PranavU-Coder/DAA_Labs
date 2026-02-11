#include <stdio.h>
#include <stdlib.h>

// this code was directly taken from the manual and is a bit broken and retarded, proceed at your own caution.
void insertionSort(int *a, unsigned int n) {
    int i, j, v;
    for (i = 1; i < n; i++) {
        v = a[i];
        j = i - 1;
        int opcount = 0;  
        while (j >= 0 && a[j] > v) {
            a[j + 1] = a[j];
            j = j - 1;
            opcount++;  
        }
        a[j + 1] = v;
        printf("operation count for pass %d: %d\n", i, opcount);
    }
}

int main() {
    int *a;
    int i, n = 5;
    for (int j = 0; j < 4; j++) {
        a = (int *)malloc(sizeof(int) * n);
        for (int k = 0; k < n; k++) a[k] = n - k;
        printf("elements are: ");
        for (i = 0; i < n; i++) printf("%d ", a[i]);
        printf("\n");

        insertionSort(a, n);

        printf("elements after insertion sort: ");
        for (i = 0; i < n; i++) printf("%d ", a[i]);
        printf("\n");

        free(a);  
    }
    return 0;
}

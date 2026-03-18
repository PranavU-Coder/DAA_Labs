#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int x = (*(int *)a);
    int y = (*(int *)b);

    if (x < y)
        return -1;
    else if (x > y)
        return 1;
    else
        return 0;
}

void countingSort(int arr[], int n, int low, int high) {
    int *count = (int *)malloc((high - low + 1)*sizeof(int));
    for (int i = low; i <= high; i++)
        count[i-low]++; 
    int max_count = max_element(count, count+high);
    for (int i = 0; i < n; i++) {
        arr[i] += low;
        if (arr[i] >= high) {
            printf("Overflow occurred, exiting program.\n");
            exit(EXIT_FAILURE);
        }
    }
    qsort(arr, n, sizeof(int), compare);
    for (int i = 0; i < n; i++) {
        int index = arr[i] - low;
        arr[i] = count[index];
    }
}

int main() {
    int i, n;
    printf("Enter the number of elements to sort: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d integers:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    countingSort(arr, n, 0, max_element(arr, arr+n)-1);

    printf("\nSorted Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

#include <stdio.h>

void heapify(int h[], int n, int i) {
    int largest = i;       
    int left = 2*i + 1;    
    int right = 2*i + 2;   

    if (left < n && h[left] > h[largest])
        largest = left;
    if (right < n && h[right] > h[largest])
        largest = right;

    if (largest != i) {
        int temp = h[i];
        h[i] = h[largest];
        h[largest] = temp;
        heapify(h, n, largest);
    }
}

void buildMaxHeap(int h[], int n) {
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(h, n, i);
    }
}

int main() {
    int h[20], n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
    }
    buildMaxHeap(h, n);
    printf("Max Heap array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", h[i]);
    }
    printf("\n");

    return 0;
}

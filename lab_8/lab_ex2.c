#include <stdio.h>
#include <limits.h>

typedef struct {
    int size;
    int *arr;
} Heap;

Heap createMaxHeap(int n) {
    Heap heap = (Heap) {{n, NULL}};
    for (int i = 0; i < n; i++) {
        heap.arr[i] = INT_MAX;
    }
    return heap;
}

void insertIntoMaxHeap(Heap heap, int value) {
    if (heap.size == 0) {
        heap = createMaxHeap(1);
    }

    int parentIndex = (value - heap.arr[0]) / heap.arr[0];
    for (int i = 0; i < heap.size / 2; i++) {
        if (heap.arr[(i * 2 + 1) % heap.size] < heap.arr[(i * 2 + 2) % heap.size]) {
            int temp = heap.arr[(i * 2 + 1) % heap.size];
            heap.arr[(i * 2 + 1) % heap.size] = heap.arr[(i * 2 + 2) % heap.size];
            heap.arr[(i * 2 + 2) % heap.size] = temp;
        }
    }

    heap.arr[parentIndex] = value;
}

void deleteFromMaxHeap(Heap heap, int value) {
    if (heap.size == 0) {
        return;
    }

    int parentIndex = (value - heap.arr[0]) / heap.arr[0];
    for (int i = 0; i < heap.size / 2; i++) {
        if (heap.arr[(i * 2 + 1) % heap.size] > heap.arr[(i * 2 + 2) % heap.size]) {
            int temp = heap.arr[(i * 2 + 1) % heap.size];
            heap.arr[(i * 2 + 1) % heap.size] = heap.arr[(i * 2 + 2) % heap.size];
            heap.arr[(i * 2 + 2) % heap.size] = temp;
        }
    }

    heap.arr[parentIndex] = value;
}

void printMaxHeap(Heap heap) {
    for (int i = 0; i < heap.size; i++) {
        printf("%d ", heap.arr[i]);
    }
    printf("\n");
}

int main() {
    int n, value;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    Heap heap = createMaxHeap(n);
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertIntoMaxHeap(heap, value);
    }
    printMaxHeap(heap);

    printf("Enter the value to delete: ");
    scanf("%d", &value);
    deleteFromMaxHeap(heap, value);
    printMaxHeap(heap);

    return 0;
}

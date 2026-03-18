#include <stdio.h>
#include <stdlib.h>

typedef struct Heap {
    int size;
    int* arr;
} Heap;

Heap create_heap(int n) {
    Heap heap = (Heap) {
        .size = n,
        .arr = (int*) malloc(n * sizeof(int))
    };
    for (int i = 0; i < n; i++) {
        heap.arr[i] = i;
    }
    heapify(heap, 0);
    return heap;
}

void heapify(Heap heap, int parent) {
    int left_child = 2 * parent + 1;
    int right_child = 2 * parent + 2;
    int largest_child = parent;

    if (left_child < heap.size && heap.arr[left_child] > heap.arr[largest_child]) {
        largest_child = left_child;
    }

    if (right_child < heap.size && heap.arr[right_child] > heap.arr[largest_child]) {
        largest_child = right_child;
    }

    if (largest_child != parent) {
        int temp = heap.arr[parent];
        heap.arr[parent] = heap.arr[largest_child];
        heap.arr[largest_child] = temp;

        heapify(heap, largest_child);
    }
}

void insert_element(Heap heap, int value) {
    if (heap.size == 0) {
        heap = create_heap(1);
    }

    heap.arr[heap.size++] = value;

    for (int i = (heap.size - 1) / 2; i >= 0; i--) {
        if (heap.arr[i] < heap.arr[2 * i + 1]) {
            int temp = heap.arr[i];
            heap.arr[i] = heap.arr[2 * i + 1];
            heap.arr[2 * i + 1] = temp;
        }
    }

    heapify(heap, 0);
}

void delete_element(Heap heap, int value) {
    for (int i = 0; i < heap.size; i++) {
        if (heap.arr[i] == value) {
            int temp = heap.arr[i];
            heap.arr[i] = heap.arr[heap.size - 1];
            heap.arr[heap.size - 1] = temp;

            heap.size--;
            heapify(heap, i);
        }
    }
}

void print_heap(Heap heap) {
    for (int i = 0; i < heap.size; i++) {
        printf("%d ", heap.arr[i]);
    }
    printf("\n");
}

int main() {
    int n, value;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    Heap heap = create_heap(n);
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insert_element(heap, value);
    }
    printf("Heap: ");
    print_heap(heap);

    printf("Enter the value to delete: ");
    scanf("%d", &value);
    delete_element(heap, value);
    printf("Heap after deleting %d: ", value);
    print_heap(heap);

    return 0;
}

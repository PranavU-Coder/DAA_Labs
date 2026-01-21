#include <stdio.h>
#include <stdlib.h>

// bubble-sort 

void bubSort(int *arr,int num){
    for(int i=0;i<num;i++){
        for(int j=i+1;j<num;j++){
            if(arr[i]>arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


// merge-sort

void merge(int *arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int *arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);       
        mergeSort(arr, mid + 1, right); 

        merge(arr, left, mid, right);    
    }
}


// display func

void display(int *arr,int num){
    for (int i=0;i<num;i++){
        printf("%d ",arr[i]);
    }
}

// main program

int main(void){
    int num;
    printf("enter number of elements to be in a set: ");
    scanf("%d",&num);
    int *arr = malloc(sizeof(int)* num);
    printf("enter any set of numbers: ");
    for(int i=0;i<num;i++){
        scanf("%d",&arr[i]);
    }
    /*
    printf("\n--- BUBBLE-SORT ---\n");
    bubSort(arr,num);
    */

    
    /*
    printf("\n--- MERGE-SORT ---\n");
    mergeSort(arr, 0, num - 1);
    */
    
    display(arr,num);
    free(arr);
}

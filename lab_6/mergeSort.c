#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r){
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;

    int *L = (int *)malloc(n1*sizeof(int));
    int *R = (int *)malloc(n2*sizeof(int));

    for(i=0;i<n1;i++) L[i] = arr[l+i];
    for(j=0;j<n2;j++) R[i] = arr[m+1+j];

    i=0;j=0;k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k] = L[i++];
        }
        k++;
    }
    while(i<n1) arr[k++] = L[i++];
    while(j<n2) arr[k++] = R[j++];
    free(L); free(R);
}

void mergeSort(int arr[], int l, int r){
    if(l<r){
        int m = l + (r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+l,r);
        merge(arr,l,m,r);
    }
}

int main(){
    int n;
    printf("enter number of elements in array: ");
    scanf("%d",&n);
    int *arr = (int *)malloc(sizeof(int)*n);
    printf("enter elements:");
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    mergeSort(arr,0,n-1);
    printf("sorted array: ");
    for(int i =0;i<n;i++) printf("%d",arr[i]);
    printf("\n");
    free(arr);
    return 0;
}

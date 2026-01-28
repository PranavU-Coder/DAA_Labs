#include <stdio.h>

void bubbleSort(int arr[], int n){
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int n,i;
    printf("enter number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("enter %d elements: \n",n);
    for(i=0;i<n;i++){
        printf("element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("\noriginal array: ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    bubbleSort(arr,n);

    printf("sorted array: ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}

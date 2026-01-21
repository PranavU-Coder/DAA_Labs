#include <stdio.h>
#include <stdlib.h>

// the actual func

int linSearch(int *arr,int number, int num){
    for(int i=0; i<num;i++){
        if(number == arr[i]){
            return 1;
            break;
        }
    }
    return 0;
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
    int key;
    printf("enter number to find: ");
    scanf("%d",&key);
    if(linSearch(arr,key,num)){
        printf("element found!");
    } else printf("element not found!");
    free(arr);
    return 0;
}

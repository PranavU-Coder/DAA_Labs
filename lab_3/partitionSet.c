#include <stdio.h>

int partition(int arr[], int n){
    int total_sum = 0;
    int i,j;
    for(i=0;i<n;i++) total_sum += arr[i];
    if(total_sum%2!=0){
        printf("partition is not possible\n");
        return 0;
    }
    int target = total_sum/2;
    int total_subsets = 1 << n;
    printf("total sum: %d\n",total_sum);
    printf("target: %d\n",target);
    
    for(i=1;i<total_subsets-1;i++){
        int sum=0;
        for(j=0;j<n;j++){
            if(i & (1<<j)) sum+=arr[j];
        }
        if(sum==target){
            printf("partition found\n");
            printf("set 1: { ");
            for(j=0;j<n;j++){
                if(i & (1<<j)) printf("%d ",arr[j]);
            }
            printf("}\n");
            printf("set 2: { ");
            for(j=0;j<n;j++){
                if(!(i & (1<<j))) printf("%d ",arr[j]);
            }
            printf("}\n");
            return 1;
        }
    }
}

int main(){
    int n,i;
    printf("enter number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("enter %d numbers:\n",n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");

    partition(arr,n);
    return 0;
}

#include <stdio.h>
#include <limits.h>

#define MAX 10

int n;
int cost[MAX][MAX];
int assignment[MAX];
int bestAssignment[MAX];
int minCost = INT_MAX;

int calculateCost(){
    int totalCost = 0;
    for(int i = 0; i<n; i++) totalCost += cost[i][assignment[i]];
    return totalCost;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void generatePermutations(int size){
    if(size==1){
        int currentCost = calculateCost();
        if(currentCost<minCost){
            minCost = currentCost;
            for(int i=0;i<n;i++) bestAssignment[i] = assignment[i];
        }
        return;
    }
    for(int i=0;i<size;i++){
        generatePermutations(size-1);
        if(size%2 ==1) swap(&assignment[0],&assignment[size-1]);
        else swap(&assignment[i], &assignment[size-1]);
    }
}

int main(){
    printf("enter number of workers/jobs: ");
    scanf("%d",&n);

    printf("enter cost-matrix\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&cost[i][j]);
        }
    }
    for(int i=0;i<n;i++) assignment[i] = i;
    generatePermutations(n);
    printf("\nminimum cost: %d\n",minCost);
    printf("\noptimal assignment:\n");
    for(int i=0;i<n;i++) printf("worker %d -> job %d (cost %d)\n",i+1,bestAssignment[i]+1,cost[i][bestAssignment[i]]);
    return 0;
}

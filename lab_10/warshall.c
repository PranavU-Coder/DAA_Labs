#include <stdio.h>

#define MAX 100

void print(int matrix[MAX][MAX], int V){
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

void compute(int graph[MAX][MAX], int V){
    int reach [MAX][MAX];
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            reach[i][j] = graph[i][j];
        }
    }
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                reach [i][j] = reach [i][j] || reach[i][k] && reach[k][j];
            }
        }
    }
    printf("\nTransitive Closure Matrix:\n");
    print(reach,V);
}

int main(){
    int V;
    int graph[MAX][MAX];

    printf("Enter the number of vertices in graph: ");
    if(scanf("%d",&V)!=1 || V<0 || V>MAX){
        printf("Invalid input\n");
        return 1;
    }

    printf("Enter adjacency matrix: \n");
    printf("Enter values row by row: \n");

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    compute(graph,V);
}

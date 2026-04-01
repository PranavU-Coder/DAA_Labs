#include <stdio.h>

#define MAX 100
#define INF 99999

void print(int matrix[MAX][MAX], int V){
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(matrix[i][j]==INF){
                printf("%7s","INF");
            } else {
                printf("%7d",matrix[i][j]);
            }
        }
        printf("\n");
    }
}

void floyd(int graph[MAX][MAX], int V){
    int dist[MAX][MAX];

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            dist[i][j] = graph [i][j];
        }
    }

    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(dist[i][k]!=INF && dist[k][j]!=INF && dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    printf("all pairs shortest path matrix: \n");
    print(dist,V);
}

int main(){
    int V;
    int graph[MAX][MAX];
    printf("enter the number of vertices in the graph: ");
    if(scanf("%d",&V)!=1 || V<=0 || V>MAX){
        printf("invalid input\n");
        return 1;
    }

    printf("enter the adjacency matrix representing edge wt:");
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    floyd(graph,V);
    return 0;
}

#include <stdio.h>

#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int n;

void DFS(int vertex){
    printf("push: vertex %d\n",vertex);
    visited[vertex] = 1;
    printf("visited %d\n", vertex);
    for(int i=0;i<n;i++){
        if(graph[vertex][i] == 1 && !visited[i]) DFS(i);
    }
    printf("pop: vertex %d\n", vertex);
}

int main(){
    int startVertex;
    printf("enter number of vertices: ");
    scanf("%d", &n);
    printf("enter adjacency matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &graph[i][j]);
        }
    }
    printf("enter starting vertex from 0 to %d\n",n-1);
    scanf("%d",&startVertex);
    for(int i=0;i<n;i++) visited[i] = 0;
    DFS(startVertex);
    return 0;
}

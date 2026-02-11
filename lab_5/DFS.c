#include <stdio.h>

int adj[10][10], visited[10], stack[10];
int top = -1, n;

void DFS(int v){
    visited[v] = 1;
    for(int i=0; i<n;i++){
        if(adj[v][i] && !visited[i]) DFS(i);
    }
    stack[++top] = v;
}

int main(){
    printf("enter number of vertices: ");
    scanf("%d",&n);
    printf("enter adjacency matrix: \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) scanf("%d",&adj[i][j]);
    }
    for(int i=0;i<n;i++) visited[i] = 0;
    for(int i=0;i<n;i++){
        if(!visited[i]) DFS(i);
    }
    printf("topological sort: ");
    while(top>=0) printf("%d ",stack[top--]);
    return 0;
}

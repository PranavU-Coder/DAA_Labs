#include <stdio.h>

int main(){
    int n, adj[10][10], indegree[10], sorted[10];
    int count = 0;
    printf("enter number of vertices: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++) indegree[i] = 0;
    printf("enter adjacency matrix: \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &adj[i][j]);
            if(adj[i][j] == 1) indegree[j] ++;
        }
    }    

    int processed[10] = {0};
    while(count<n){
        int v=-1;
        for(int i=0;i<n;i++){
            if(indegree[i]==0 && !processed[i]) { v = i; break;}
        }
        if(v==-1){ printf("\ncycle detected, not a DAG"); return 0;}
        processed[v]=1;
        sorted[count++] = v;
        for(int i=0;i<n;i++){
            if(adj[v][i] == 1) indegree[i]--;
        }
    }
    
    printf("topological sort: ");
    for(int i=0;i<n;i++) printf("%d ",sorted[i]);
    return 0;
}

#include<stdio.h>

#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int n;
int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int vertex){
    queue[++rear] = vertex;
    printf("enqueue: vertex %d\n", vertex);
}

int dequeue(){
    int vertex = queue[front+1];
    front++;
    printf("dequeue: vertex %d\n", vertex);
    return vertex;
}

int isEmpty() { return front == rear; }

void BFS(int startVertex){
    enqueue(startVertex);
    visited[startVertex] = 1;
    printf("visited: %d\n",startVertex);
    while(!isEmpty()){
        int current = dequeue();
        for(int i=0;i<n;i++){
            if(graph[current][i] == 1 && !visited[i]){
                enqueue(i);
                visited[i] = 1;
                printf("visited: %d\n",i);
            }
        }
    }
}

int main(){
    int startVertex;
    printf("enter number of vertices: ");
    scanf("%d",&n);
    printf("enter adjacency matrix\n");
    for(int i=0;i<n;i++) {
         for(int j=0;j<n;j++) scanf("%d",&graph[i][j]) ;
    }
    printf("enter starting vertex from 0 to %d: ",n-1);
    scanf("%d", &startVertex);
    for(int i=0;i<n;i++) visited[i] = 0;
    BFS(startVertex);
    return 0;
}

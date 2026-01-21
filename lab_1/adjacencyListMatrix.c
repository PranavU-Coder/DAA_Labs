#include <stdio.h>
#include <stdlib.h>

#define MAX 20

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    int isDirected;
    struct Node** adjList;  
    int adjMatrix[MAX][MAX];
};

struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices, int isDirected) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->isDirected = isDirected;

    graph->adjList = (struct Node**)malloc(vertices * sizeof(struct Node*));
    
    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
    }
    
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
    
    return graph;
}

void addEdgeList(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
    
    if (!graph->isDirected) {
        newNode = createNode(src);
        newNode->next = graph->adjList[dest];
        graph->adjList[dest] = newNode;
    }
}

void addEdgeMatrix(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
  
    if (!graph->isDirected) {
        graph->adjMatrix[dest][src] = 1;
    }
}

void addEdge(struct Graph* graph, int src, int dest) {
    addEdgeList(graph, src, dest);
    addEdgeMatrix(graph, src, dest);
}

void displayAdjacencyList(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjList[i];
        printf("vertex %d: ", i);
        
        while (temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void displayAdjacencyMatrix(struct Graph* graph) {
    printf("   ");
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%2d ", i);
    }
    printf("\n");
    
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%2d ", i);
        for (int j = 0; j < graph->numVertices; j++) {
            printf("%2d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void display(struct Graph* graph) {
    displayAdjacencyList(graph);
    displayAdjacencyMatrix(graph);
}

int main() {
    int vertices, edges, graphType;
    int src, dest, choice;
    
    printf("enter the number of vertices: ");
    scanf("%d", &vertices);
    
    if (vertices > MAX) {
        printf("max %d vertices allowed!\n", MAX);
        return 1;
    }
    
    printf("enter graph type (0 for Undirected, 1 for Directed): ");
    scanf("%d", &graphType);
    
    struct Graph* graph = createGraph(vertices, graphType);
    
    printf("\ngraph created with %d vertices (%s)\n", 
           vertices, graphType ? "Directed" : "Undirected");
    
    while (1) {
        printf("\n\nMenu:\n");
        printf("1. Add edge\n");
        printf("2. Display Adjacency List\n");
        printf("3. Display Adjacency Matrix\n");
        printf("4. Display both representations\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("enter source vertex (0 to %d): ", vertices - 1);
                scanf("%d", &src);
                printf("enter destination vertex (0 to %d): ", vertices - 1);
                scanf("%d", &dest);
                
                if (src >= 0 && src < vertices && dest >= 0 && dest < vertices) {
                    addEdge(graph, src, dest);
                    printf("edge added: %d -> %d\n", src, dest);
                    if (!graphType) {
                        printf("added reverse edge for undirected graph\n");
                    }
                } else {
                    printf("invalid vertices\n");
                }
                break;
            
            case 2:
                displayAdjacencyList(graph);
                break;
            
            case 3:
                displayAdjacencyMatrix(graph);
                break;
            
            case 4:
                display(graph);
                break;
            
            case 5:
                free(graph->adjList);
                free(graph);
                exit(0);
            
            default:
                printf("invalid choice\n");
        }
    }    
    return 0;
}

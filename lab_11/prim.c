#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
};

struct Node* createNode(int vertex, int weight) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->vertex = vertex;
    temp->weight = weight;
    temp->next = NULL;
    return temp;
}

void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct Node* newNode = createNode(dest, weight);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src, weight);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

struct Graph* initializeGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->adjLists = (struct Node**)malloc(sizeof(struct Node*) * numVertices);
    for (int i = 0; i < numVertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

void prim(struct Graph* graph, int startVertex) {
    int numVertices = graph->numVertices;
    int parent[numVertices];   
    int key[numVertices];      
    bool inMST[numVertices];   

    for (int i = 0; i < numVertices; i++) {
        key[i] = INT_MAX;
        inMST[i] = false;
        parent[i] = -1;
    }

    key[startVertex] = 0;

    for (int count = 0; count < numVertices - 1; count++) {
        int min = INT_MAX, u = -1;
        for (int v = 0; v < numVertices; v++) {
            if (!inMST[v] && key[v] < min) {
                min = key[v];
                u = v;
            }
        }

        inMST[u] = true;
        for (struct Node* temp = graph->adjLists[u]; temp != NULL; temp = temp->next) {
            int v = temp->vertex;
            int weight = temp->weight;
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
            }
        }
    }
    printf("Edges in MST:\n");
    int totalCost = 0;
    for (int i = 0; i < numVertices; i++) {
        if (parent[i] != -1) {
            printf("%d - %d (weight %d)\n", parent[i], i, key[i]);
            totalCost += key[i];
        }
    }
    printf("Total cost of MST = %d\n", totalCost);
}

int main() {
    int numVertices;
    scanf("%d", &numVertices);
    struct Graph* graph = initializeGraph(numVertices);
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            int weight;
            scanf("%d", &weight);
            if (weight != 0) {
                addEdge(graph, i, j, weight);
            }
        }
    }

    int startVertex;
    scanf("%d", &startVertex);
    prim(graph, startVertex);

    return 0;
}

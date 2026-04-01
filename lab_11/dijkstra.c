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

struct Node* newNode(int vertex, int weight) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->vertex = vertex;
    temp->weight = weight;
    temp->next = NULL;
    return temp;
}

void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct Node* node = newNode(dest, weight);
    node->next = graph->adjLists[src];
    graph->adjLists[src] = node;
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

void dijkstras(struct Graph* graph, int startVertex) {
    int numVertices = graph->numVertices;
    int* dist = (int*)malloc(sizeof(int) * numVertices);
    bool* processed = (bool*)malloc(sizeof(bool) * numVertices);

    for (int i = 0; i < numVertices; i++) {
        dist[i] = INT_MAX;
        processed[i] = false;
    }

    dist[startVertex] = 0;

    for (int count = 0; count < numVertices - 1; count++) {
        int minDistance = INT_MAX, currentVertex = -1;

        for (int i = 0; i < numVertices; i++) {
            if (!processed[i] && dist[i] < minDistance) {
                minDistance = dist[i];
                currentVertex = i;
            }
        }

        if (currentVertex == -1) break; 

        processed[currentVertex] = true;

        struct Node* temp = graph->adjLists[currentVertex];
        while (temp != NULL) {
            if (!processed[temp->vertex] && dist[currentVertex] != INT_MAX &&
                dist[currentVertex] + temp->weight < dist[temp->vertex]) {
                dist[temp->vertex] = dist[currentVertex] + temp->weight;
            }
            temp = temp->next;
        }
    }

    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < numVertices; i++) {
        if (dist[i] == INT_MAX)
            printf("%d\tINF\n", i);
        else
            printf("%d\t%d\n", i, dist[i]);
    }

    free(dist);
    free(processed);
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
    dijkstras(graph, startVertex);

    return 0;
}

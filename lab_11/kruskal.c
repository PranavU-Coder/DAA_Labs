#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int src, dest, weight;
};

struct Subset {
    int parent;
    int rank;
};

int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int compareEdges(const void* a, const void* b) {
    struct Edge* e1 = (struct Edge*)a;
    struct Edge* e2 = (struct Edge*)b;
    return e1->weight - e2->weight;
}

void kruskal(struct Edge edges[], int V, int E) {
    qsort(edges, E, sizeof(struct Edge), compareEdges);
    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    printf("Edges in MST:\n");
    int totalCost = 0;
    int e = 0; 

    for (int i = 0; e < V - 1 && i < E; i++) {
        struct Edge nextEdge = edges[i];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);
        if (x != y) {
            printf("%d - %d (weight %d)\n", nextEdge.src, nextEdge.dest, nextEdge.weight);
            totalCost += nextEdge.weight;
            Union(subsets, x, y);
            e++;
        }
    }

    printf("Total cost of MST = %d\n", totalCost);
    free(subsets);
}

int main() {
    int V;
    scanf("%d", &V);

    int adjMatrix[V][V];
    int E = 0;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &adjMatrix[i][j]);
            if (adjMatrix[i][j] != 0 && i < j) {
                E++;
            }
        }
    }
    struct Edge* edges = (struct Edge*)malloc(E * sizeof(struct Edge));
    int idx = 0;
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (adjMatrix[i][j] != 0) {
                edges[idx].src = i;
                edges[idx].dest = j;
                edges[idx].weight = adjMatrix[i][j];
                idx++;
            }
        }
    }
    kruskal(edges, V, E);
    free(edges);
    return 0;
}

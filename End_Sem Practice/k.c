#include <stdio.h>
#include <stdlib.h>

// Comparator function to use in sorting
int comparator(const void* p1, const void* p2) {
    const int(*x)[3] = p1;
    const int(*y)[3] = p2;
    return (*x)[2] - (*y)[2];
}

// Initialization of parent[] and rank[] arrays
void makeSet(int parent[], int rank[], int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

// Function to find the parent of a node
int findParent(int parent[], int component) {
    if (parent[component] == component)
        return component;
    return parent[component] = findParent(parent, parent[component]);
}

// Function to unite two sets
void unionSet(int u, int v, int parent[], int rank[]) {
    u = findParent(parent, u);
    v = findParent(parent, v);
    if (rank[u] < rank[v]) {
        parent[u] = v;
    } else if (rank[u] > rank[v]) {
        parent[v] = u;
    } else {
        parent[v] = u;
        rank[u]++;
    }
}

// Function to find the MST
void kruskalAlgo(int n, int edges[][3], int numEdges) {
    qsort(edges, numEdges, sizeof(edges[0]), comparator);

    int parent[n];
    int rank[n];
    makeSet(parent, rank, n);

    int minCost = 0;
    printf("Following are the edges in the constructed MST\n");
    for (int i = 0; i < numEdges; i++) {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int wt = edges[i][2];
        if (u != v) {
            unionSet(u, v, parent, rank);
            minCost += wt;
            printf("%d -- %d == %d\n", edges[i][0], edges[i][1], wt);
        }
    }

    printf("Minimum Cost Spanning Tree: %d\n", minCost);
}

// Driver code
int main() {
    int edges[][3] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };
    int numVertices = 4; // Number of vertices
    int numEdges = sizeof(edges) / sizeof(edges[0]);
    kruskalAlgo(numVertices, edges, numEdges);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define MAX 100       // Maximum number of vertices
#define INF 9999      // A large value to represent infinity (not directly used here)

int parent[MAX];      // Array to keep track of parent for Union-Find structure

// Structure to represent an edge
struct Edge {
    int u, v, weight; // u and v are the vertices, weight is the cost
};

// Comparison function for qsort: sorts edges by weight in ascending order
int compare(const void *a, const void *b) {
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}

// Find function for Union-Find (with no path compression)
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// Kruskal's algorithm to find Minimum Spanning Tree
void kruskal(int n, struct Edge edges[], int m) {
    int i, u, v, count = 0;
    int min_cost = 0;

    // Step 1: Sort edges by weight
    qsort(edges, m, sizeof(edges[0]), compare);

    // Step 2: Initialize each vertex to be its own parent
    for (i = 0; i < n; i++) 
        parent[i] = i;

    printf("Edges in the Minimum Spanning Tree:\n");

    // Step 3: Iterate over sorted edges and select the smallest non-cycling ones
    for (i = 0; i < m; i++) {
        u = find(edges[i].u); // Find parent of u
        v = find(edges[i].v); // Find parent of v

        // If they have different parents, they are in different sets (no cycle)
        if (u != v) {
            printf("%d - %d: %d\n", edges[i].u, edges[i].v, edges[i].weight);
            min_cost += edges[i].weight;

            // Union: Combine the two sets
            parent[u] = v;

            count++; // Increase count of selected edges
        }

        // Stop if we have n - 1 edges in MST
        if (count == n - 1)
            break;
    }

    // Print the total cost of MST
    printf("Minimum cost of the spanning tree: %d\n", min_cost);
}

int main() {
    // Define graph as an array of edges (undirected and weighted)
    struct Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    int n = 4; // Number of vertices
    int m = 5; // Number of edges

    // Call Kruskal’s algorithm
    kruskal(n, edges, m);

    return 0;
}

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 5  // Number of vertices in the graph

// Function to find the vertex with the minimum key value
int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v], min_index = v;
        }
    }
    return min_index;
}

// Function to print the resulting MST
int printMST(int parent[], int graph[V][V]) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
}

// Main function that constructs and prints the MST using Prim's algorithm
void primMST(int graph[V][V]) {
    int parent[V];   // Stores the MST structure
    int key[V];      // Used to pick minimum weight edge
    bool mstSet[V];  // Track vertices included in MST

    // Initialize all keys as infinite and mstSet[] as false
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Start from the first vertex
    key[0] = 0;
    parent[0] = -1;  // First node is the root of MST

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);  // Pick minimum key vertex
        mstSet[u] = true;             // Include it in MST

        // Update the key and parent of adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

// Driver code
int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);

    return 0;
}

#include <stdio.h>

#define V 4

void transitiveClosure(int graph[V][V]) {
    int tc[V][V], i, j, k;

    // Initialize the transitive closure matrix with the given graph
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            tc[i][j] = graph[i][j];
        }
    }

    // Apply Warshall's algorithm
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                tc[i][j] = tc[i][j] || (tc[i][k] && tc[k][j]);
            }
        }
    }

    // Print the transitive closure matrix
    printf("Transitive closure of the given graph:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            printf("%d ", tc[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V] = { 
        {1, 1, 0, 1},
        {0, 1, 1, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 1}
    };

    transitiveClosure(graph);
    return 0;
}

#include <stdio.h>
#include <limits.h>

#define MAX 105

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[MAX][MAX];

    // initialize graph with large value
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = INT_MAX;
        }
    }

    int u, v, w;

    // input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int key[MAX];
    int mstSet[MAX];

    // initialize
    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[1] = 0; // start from node 1

    int totalWeight = 0;

    for (int count = 1; count <= n; count++) {
        int min = INT_MAX, u = -1;

        // pick minimum key vertex not in MST
        for (int i = 1; i <= n; i++) {
            if (!mstSet[i] && key[i] < min) {
                min = key[i];
                u = i;
            }
        }

        mstSet[u] = 1;
        totalWeight += key[u];

        // update adjacent vertices
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] != INT_MAX && !mstSet[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    printf("%d\n", totalWeight);

    return 0;
}
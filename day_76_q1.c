#include <stdio.h>
#include <stdlib.h>

void dfs(int node, int* visited, int** adj, int* adjSize) {
    visited[node] = 1;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];
        if (!visited[neighbor]) {
            dfs(neighbor, visited, adj, adjSize);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // adjacency list
    int** adj = (int**)malloc((n + 1) * sizeof(int*));
    int* adjSize = (int*)calloc(n + 1, sizeof(int));

    // first count degree
    int u, v;
    int edges[m][2];

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        edges[i][0] = u;
        edges[i][1] = v;
        adjSize[u]++;
        adjSize[v]++;
    }

    // allocate memory
    for (int i = 1; i <= n; i++) {
        adj[i] = (int*)malloc(adjSize[i] * sizeof(int));
        adjSize[i] = 0;
    }

    // fill adjacency list
    for (int i = 0; i < m; i++) {
        u = edges[i][0];
        v = edges[i][1];

        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }

    int* visited = (int*)calloc(n + 1, sizeof(int));

    int components = 0;

    // check each node
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, visited, adj, adjSize);
            components++;
        }
    }

    printf("%d\n", components);

    return 0;
}
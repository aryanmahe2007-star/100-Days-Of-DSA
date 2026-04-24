#include <stdio.h>
#include <limits.h>

#define MAXN 1005
#define MAXM 2005
#define INF 1000000000

typedef struct {
    int to, weight, next;
} Edge;

Edge edges[MAXM];
int head[MAXN], edgeCount = 0;

int dist[MAXN], visited[MAXN];

void addEdge(int u, int v, int w) {
    edges[edgeCount].to = v;
    edges[edgeCount].weight = w;
    edges[edgeCount].next = head[u];
    head[u] = edgeCount++;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        head[i] = -1;
        dist[i] = INF;
        visited[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        addEdge(u, v, w);
        addEdge(v, u, w);   // remove this line if graph is directed
    }

    int source;
    scanf("%d", &source);

    dist[source] = 0;

    // Dijkstra without priority queue, O(n^2)
    for (int i = 1; i <= n; i++) {
        int u = -1;

        for (int j = 1; j <= n; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        if (dist[u] == INF) break;

        visited[u] = 1;

        for (int e = head[u]; e != -1; e = edges[e].next) {
            int v = edges[e].to;
            int w = edges[e].weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF)
            printf("INF ");
        else
            printf("%d ", dist[i]);
    }

    return 0;
}
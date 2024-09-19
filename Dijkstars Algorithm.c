#include<stdio.h>
#define infinity 999

void dij(int n, int v, int cost[10][10], int dist[]) {
    int i, u, count, w, flag[10], min;
    for (i = 1; i <= n; i++) {
        flag[i] = 0;
        dist[i] = cost[v][i];
    }

    flag[v] = 1;
    dist[v] = 0;

    for (count = 2; count <= n; count++) {
        min = infinity;
        for (w = 1; w <= n; w++) {
            if (!flag[w] && dist[w] < min) {
                min = dist[w];
                u = w;
            }
        }

        flag[u] = 1;

        for (w = 1; w <= n; w++) {
            if (!flag[w] && (dist[u] + cost[u][w]) < dist[w]) {
                dist[w] = dist[u] + cost[u][w];
            }
        }
    }

    printf("Shortest distances from vertex %d:\n", v);
    for (i = 1; i <= n; i++) {
        printf("Vertex %d: %d\n", i, dist[i]);
    }
}

int main() {
    int n, v, cost[10][10], dist[10];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &v);

    dij(n, v, cost, dist);

    return 0;
}
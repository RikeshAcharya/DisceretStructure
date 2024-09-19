//program to implement kriskal alorithm
#include<stdio.h>

#define V 5

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int find(int parent[], int i) {
    if (parent[i] == i) {
        return i;
    }
    return find(parent, parent[i]);
}

void unionFunc(int parent[], int rank[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    if (rank[xroot] < rank[yroot]) {
        parent[xroot] = yroot;
    } else if (rank[xroot] > rank[yroot]) {
        parent[yroot] = xroot;
    } else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

void kruskalMST(int cost[][V]) {
    int parent[V];
    int rank[V];

    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int edgeCount = 0;
    int mincost = 0;
    int edges[V * V][2];

    int k = 0;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (cost[i][j] != 0) {
                edges[k][0] = cost[i][j];
                edges[k][1] = i * V + j;
                k++;
            }
        }
    }

    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            if (edges[i][0] > edges[j][0]) {
                int temp = edges[i][0];
                edges[i][0] = edges[j][0];
                edges[j][0] = temp;

                temp = edges[i][1];
                edges[i][1] = edges[j][1];
                edges[j][1] = temp;
            }
        }
    }

    for (int i = 0; i < k; i++) {
        int x = edges[i][1] / V;
        int y = edges[i][1] % V;

        int xroot = find(parent, x);
        int yroot = find(parent, y);

        if (xroot != yroot) {
            unionFunc(parent, rank, xroot, yroot);
            printf("Edge %d:(%d, %d) cost: %d \n", edgeCount++, x, y, edges[i][0]);
            mincost += edges[i][0];
        }
    }

    printf("Minimum cost: %d\n", mincost);
}

int main() {
    int cost[][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    kruskalMST(cost);

    return 0;
}
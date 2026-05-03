#include <stdio.h>
#define MAX 100
#define INF 1000000000

int minKey(int key[], int mstSet[], int n) {
    int min = INF, min_index = -1;
    for (int i = 1; i <= n; i++) {
        if (!mstSet[i] && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int adj[MAX][MAX];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            adj[i][j] = 0;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w;
    }

    int key[MAX], mstSet[MAX];

    for (int i = 1; i <= n; i++) {
        key[i] = INF;
        mstSet[i] = 0;
    }

    key[1] = 0;

    int total = 0;

    for (int count = 1; count <= n; count++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = 1;
        total += key[u];

        for (int v = 1; v <= n; v++) {
            if (adj[u][v] && !mstSet[v] && adj[u][v] < key[v]) {
                key[v] = adj[u][v];
            }
        }
    }

    printf("%d", total);
    return 0;
}
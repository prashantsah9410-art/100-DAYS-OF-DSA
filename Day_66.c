#include <stdio.h>
#define MAX 100

int visited[MAX], recStack[MAX];

int dfs(int adj[MAX][MAX], int n, int u) {
    visited[u] = 1;
    recStack[u] = 1;

    for (int v = 0; v < n; v++) {
        if (adj[u][v]) {
            if (!visited[v] && dfs(adj, n, v))
                return 1;
            else if (recStack[v])
                return 1;
        }
    }

    recStack[u] = 0;
    return 0;
}

int hasCycle(int adj[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(adj, n, i))
                return 1;
        }
    }
    return 0;
}

int main() {
    int n, adj[MAX][MAX];
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    if (hasCycle(adj, n))
        printf("YES");
    else
        printf("NO");

    return 0;
}
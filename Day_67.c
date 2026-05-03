#include <stdio.h>
#define MAX 100

int visited[MAX], stack[MAX], top = -1;

void dfs(int adj[MAX][MAX], int n, int u) {
    visited[u] = 1;
    for (int v = 0; v < n; v++) {
        if (adj[u][v] && !visited[v]) {
            dfs(adj, n, v);
        }
    }
    stack[++top] = u;
}

int main() {
    int n, adj[MAX][MAX];
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    for (int i = 0; i < n; i++) visited[i] = 0;

    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs(adj, n, i);

    while (top != -1)
        printf("%d ", stack[top--]);

    return 0;
}

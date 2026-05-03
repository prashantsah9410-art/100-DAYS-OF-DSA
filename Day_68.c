#include <stdio.h>
#define MAX 100

int queue[MAX], front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int main() {
    int n, adj[MAX][MAX], indegree[MAX] = {0};

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (adj[i][j])
                indegree[j]++;

    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            enqueue(i);

    int count = 0;

    while (front <= rear) {
        int u = dequeue();
        printf("%d ", u);
        count++;

        for (int v = 0; v < n; v++) {
            if (adj[u][v]) {
                indegree[v]--;
                if (indegree[v] == 0)
                    enqueue(v);
            }
        }
    }

    if (count != n)
        printf("CYCLE");

    return 0;
}
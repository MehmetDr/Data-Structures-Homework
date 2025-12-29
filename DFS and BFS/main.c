
#include <stdio.h>
#include <stdbool.h>

#define V 4
void BFS(int adj[V][V], int start) {
    bool visited[V] = {false};
    int queue[V], front = 0, rear = 0;
    visited[start] = true;
    queue[rear++] = start;

    printf("BFS Traversal: ");
    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);
        int i;
        for (i = 0; i < V; i++) {
            if (adj[v][i] && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

int main() {
    int adj[V][V] = {{0, 1, 1, 0}, {1, 0, 1, 0}, {1, 1, 0, 1}, {0, 0, 1, 0}};
    BFS(adj, 0);
    return 0;
}

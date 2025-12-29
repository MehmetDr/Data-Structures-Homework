
#include <stdio.h>
#include <stdbool.h>

#define V 5
void DFS(int adj[V][V], bool visited[], int v) {
    int i;
	visited[v] = true;
    printf("%d ", v);
    for (i = 0; i < V; i++)
        if (adj[v][i] && !visited[i])
            DFS(adj, visited, i);
}

void findClusters(int adj[V][V]) {
    int v;
	bool visited[V] = {false};
    int clusterCount = 0;
    for (v = 0; v < V; v++) {
        if (!visited[v]) {
            printf("Cluster %d: ", ++clusterCount);
            DFS(adj, visited, v);
            printf("\n");
        }
    }
}

int main() {
    int adj[V][V] = { {0, 1, 0, 0, 0}, {1, 0, 0, 0, 0}, {0, 0, 0, 1, 1}, {0, 0, 1, 0, 0}, {0, 0, 1, 0, 0} };
    findClusters(adj);
    return 0;
}

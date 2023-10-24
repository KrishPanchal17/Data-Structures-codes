#include <stdio.h>
int numVertices;
int adjacencyList[100][100];

void initializeGraph() {
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            adjacencyList[i][j] = 0;
        }
    }
}
void addEdge(int vertex1, int vertex2) {
    adjacencyList[vertex1][vertex2] = 1;
    adjacencyList[vertex2][vertex1] = 1;
}

void dfs(int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < numVertices; i++) {
        if (adjacencyList[vertex][i] == 1 && !visited[i]) {
            dfs(i, visited);
        }
    }
}

int main() {
    numVertices = 7;
    initializeGraph();
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 4);
    addEdge(3, 5);
    addEdge(4, 5);

    int visited[numVertices];
    for (int i = 0; i < numVertices; i++) {
        visited[i] = 0;
    }

    printf("Depth First Search traversal of the graph: ");
    dfs(0, visited);
    printf("\n");

    return 0;
}
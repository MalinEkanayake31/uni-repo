#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

void displayDegrees(int graph[MAX_VERTICES][MAX_VERTICES], int v);
bool isRegular(int graph[MAX_VERTICES][MAX_VERTICES], int v);
void generateRegularGraph(int v, int degree);

int main() {
    int v, degree;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &v);

    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    displayDegrees(graph, v);

    if (isRegular(graph, v)) {
        printf("The given graph is regular.\n");
    } else {
        printf("The given graph is not regular.\n");
    }

    printf("\nEnter the number of vertices for the regular graph: ");
    scanf("%d", &v);

    printf("Enter the degree for each vertex: ");
    scanf("%d", &degree);

    generateRegularGraph(v, degree);

    return 0;
}

void displayDegrees(int graph[MAX_VERTICES][MAX_VERTICES], int v) {
    printf("Degrees of vertices:\n");
    for (int i = 0; i < v; i++) {
        int degree = 0;
        for (int j = 0; j < v; j++) {
            degree += graph[i][j];
        }
        printf("Vertex %d: %d\n", i + 1, degree);
    }
}

bool isRegular(int graph[MAX_VERTICES][MAX_VERTICES], int v) {
    int degree = 0;
    for (int i = 0; i < v; i++) {
        int vertexDegree = 0;
        for (int j = 0; j < v; j++) {
            vertexDegree += graph[i][j];
        }

        if (i == 0) {
            degree = vertexDegree;
        } else if (degree != vertexDegree) {
            return false;
        }
    }
    return true;
}

void generateRegularGraph(int v, int degree) {
    // Generate and display the regular graph (you need to implement this part)
    // This function is a placeholder and needs to be implemented
    // You can use any algorithm or approach for generating a regular graph
    // You may consider using adjacency matrix or adjacency list representation
    // and ensure that each vertex has the specified degree
}

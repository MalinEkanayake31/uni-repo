#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

void displayGraph(int graph[MAX_VERTICES][MAX_VERTICES], int v);
bool isCompleteGraph(int graph[MAX_VERTICES][MAX_VERTICES], int v);
void generateCompleteGraph(int v);

int main() {
    int v;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &v);

    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Given Graph:\n");
    displayGraph(graph, v);

    if (isCompleteGraph(graph, v)) {
        printf("The given graph is a complete graph.\n");
    } else {
        printf("The given graph is not a complete graph.\n");
    }

    printf("\nEnter the number of vertices for the complete graph: ");
    scanf("%d", &v);

    generateCompleteGraph(v);

    return 0;
}

void displayGraph(int graph[MAX_VERTICES][MAX_VERTICES], int v) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

bool isCompleteGraph(int graph[MAX_VERTICES][MAX_VERTICES], int v) {
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (i != j && graph[i][j] != 1) {
                return false;
            }
        }
    }
    return true;
}

void generateCompleteGraph(int v) {
    int completeGraph[MAX_VERTICES][MAX_VERTICES];
    
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (i != j) {
                completeGraph[i][j] = 1;
            } else {
                completeGraph[i][j] = 0;
            }
        }
    }

    printf("\nGenerated Complete Graph:\n");
    displayGraph(completeGraph, v);
}

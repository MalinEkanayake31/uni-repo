#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

bool hasHamiltonianPath(int graph[MAX_VERTICES][MAX_VERTICES], int v, int path[MAX_VERTICES]);
bool findHamiltonianCycle(int graph[MAX_VERTICES][MAX_VERTICES], int v, int path[MAX_VERTICES], int pos);

int main() {
    int v;

    int graph1[MAX_VERTICES][MAX_VERTICES] = {{0, 1, 1, 0}, {1, 0, 1, 1}, {1, 1, 0, 1}, {0, 1, 1, 0}};
    int graph2[MAX_VERTICES][MAX_VERTICES] = {{0, 1, 0, 1}, {1, 0, 1, 1}, {0, 1, 0, 1}, {1, 1, 1, 0}};
    int graph3[MAX_VERTICES][MAX_VERTICES] = {{0, 1, 1, 1}, {1, 0, 1, 1}, {1, 1, 0, 0}, {1, 1, 0, 0}};
    int graph4[MAX_VERTICES][MAX_VERTICES] = {{0, 1, 0, 1}, {1, 0, 1, 0}, {0, 1, 0, 1}, {1, 0, 1, 0}};

    
    int path[MAX_VERTICES];
    
    printf("Graph 1: %s\n", hasHamiltonianPath(graph1, 4, path) ? "Has Hamiltonian Path" : "No Hamiltonian Path");
    if (findHamiltonianCycle(graph1, 4, path, 0)) {
        printf("Hamiltonian Cycle: ");
        for (int i = 0; i < 4; i++) {
            printf("%d ", path[i]);
        }
        printf("%d\n", path[0]);
    } else {
        printf("No Hamiltonian Cycle\n");
    }

    printf("\nGraph 2: %s\n", hasHamiltonianPath(graph2, 4, path) ? "Has Hamiltonian Path" : "No Hamiltonian Path");
    if (findHamiltonianCycle(graph2, 4, path, 0)) {
        printf("Hamiltonian Cycle: ");
        for (int i = 0; i < 4; i++) {
            printf("%d ", path[i]);
        }
        printf("%d\n", path[0]);
    } else {
        printf("No Hamiltonian Cycle\n");
    }

    printf("\nGraph 3: %s\n", hasHamiltonianPath(graph3, 4, path) ? "Has Hamiltonian Path" : "No Hamiltonian Path");
    if (findHamiltonianCycle(graph3, 4, path, 0)) {
        printf("Hamiltonian Cycle: ");
        for (int i = 0; i < 4; i++) {
            printf("%d ", path[i]);
        }
        printf("%d\n", path[0]);
    } else {
        printf("No Hamiltonian Cycle\n");
    }

    printf("\nGraph 4: %s\n", hasHamiltonianPath(graph4, 4, path) ? "Has Hamiltonian Path" : "No Hamiltonian Path");
    if (findHamiltonianCycle(graph4, 4, path, 0)) {
        printf("Hamiltonian Cycle: ");
        for (int i = 0; i < 4; i++) {
            printf("%d ", path[i]);
        }
        printf("%d\n", path[0]);
    } else {
        printf("No Hamiltonian Cycle\n");
    }

    return 0;
}

bool hasHamiltonianPath(int graph[MAX_VERTICES][MAX_VERTICES], int v, int path[MAX_VERTICES]) {
    // Implement the logic to check if a Hamiltonian path exists
    // This function is a placeholder and needs to be implemented
    return false;
}

bool findHamiltonianCycle(int graph[MAX_VERTICES][MAX_VERTICES], int v, int path[MAX_VERTICES], int pos) {
    // Implement the logic to find a Hamiltonian cycle
    // This function is a placeholder and needs to be implemented
    return false;
}

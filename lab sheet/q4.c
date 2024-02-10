#include <stdio.h>

#define MAX_VERTICES 100

int isEulerian(int graph[MAX_VERTICES][MAX_VERTICES], int v);
void findEulerianCircuit(int graph[MAX_VERTICES][MAX_VERTICES], int v, int circuit[MAX_VERTICES]);

int main() {
    int v;

    int graph1[MAX_VERTICES][MAX_VERTICES] = {{0, 1, 1, 0}, {1, 0, 1, 1}, {1, 1, 0, 1}, {0, 1, 1, 0}};
    int graph2[MAX_VERTICES][MAX_VERTICES] = {{0, 1, 0, 1}, {1, 0, 1, 1}, {0, 1, 0, 1}, {1, 1, 1, 0}};
    int graph3[MAX_VERTICES][MAX_VERTICES] = {{0, 1, 1, 1}, {1, 0, 1, 1}, {1, 1, 0, 0}, {1, 1, 0, 0}};
    int graph4[MAX_VERTICES][MAX_VERTICES] = {{0, 1, 0, 1}, {1, 0, 1, 0}, {0, 1, 0, 1}, {1, 0, 1, 0}};

    printf("Graph 1: %s\n", isEulerian(graph1, 4) ? "Eulerian" : "Not Eulerian");
    printf("Graph 2: %s\n", isEulerian(graph2, 4) ? "Eulerian" : "Not Eulerian");
    printf("Graph 3: %s\n", isEulerian(graph3, 4) ? "Eulerian" : "Not Eulerian");
    printf("Graph 4: %s\n", isEulerian(graph4, 4) ? "Eulerian" : "Not Eulerian");

    return 0;
}

int isEulerian(int graph[MAX_VERTICES][MAX_VERTICES], int v) {
    int oddDegreeCount = 0;
    for (int i = 0; i < v; i++) {
        int degree = 0;
        for (int j = 0; j < v; j++) {
            degree += graph[i][j];
        }
        if (degree % 2 != 0) {
            oddDegreeCount++;
        }
    }

    if (oddDegreeCount == 0) {
        return 2; // Eulerian circuit
    } else if (oddDegreeCount == 2) {
        return 1; // Eulerian path
    } else {
        return 0; // Not Eulerian
    }
}

void findEulerianCircuit(int graph[MAX_VERTICES][MAX_VERTICES], int v, int circuit[MAX_VERTICES]) {
    // Add your logic to find an Eulerian circuit here
    // This function is a placeholder and needs to be implemented
}

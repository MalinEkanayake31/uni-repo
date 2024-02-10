#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

bool isBipartite(int graph[MAX_VERTICES][MAX_VERTICES], int v, int color[MAX_VERTICES]);
bool findBipartiteSets(int graph[MAX_VERTICES][MAX_VERTICES], int v, int sets[MAX_VERTICES], int color[MAX_VERTICES], int currentVertex, int currentSet);

int main() {
    int v;

    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &v);

    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int color[MAX_VERTICES];
    if (isBipartite(graph, v, color)) {
        printf("The given graph is bipartite.\n");

        int sets[MAX_VERTICES];
        if (findBipartiteSets(graph, v, sets, color, 0, 1)) {
            printf("Set 1: ");
            for (int i = 0; i < v; i++) {
                if (sets[i] == 1) {
                    printf("%d ", i + 1);
                }
            }
            printf("\nSet 2: ");
            for (int i = 0; i < v; i++) {
                if (sets[i] == 2) {
                    printf("%d ", i + 1);
                }
            }
            printf("\n");
        } else {
            printf("Unable to determine bipartite sets.\n");
        }
    } else {
        printf("The given graph is not bipartite.\n");
    }

    return 0;
}

bool isBipartite(int graph[MAX_VERTICES][MAX_VERTICES], int v, int color[MAX_VERTICES]) {
    for (int i = 0; i < v; i++) {
        color[i] = 0; // 0 represents uncolored
    }

    for (int i = 0; i < v; i++) {
        if (color[i] == 0) {
            if (!findBipartiteSets(graph, v, color, color, i, 1)) {
                return false;
            }
        }
    }

    return true;
}

bool findBipartiteSets(int graph[MAX_VERTICES][MAX_VERTICES], int v, int sets[MAX_VERTICES], int color[MAX_VERTICES], int currentVertex, int currentSet) {
    sets[currentVertex] = currentSet;

    for (int i = 0; i < v; i++) {
        if (graph[currentVertex][i]) {
            if (color[i] == 0) {
                if (!findBipartiteSets(graph, v, sets, color, i, 3 - currentSet)) {
                    return false;
                }
            } else if (color[i] == currentSet) {
                return false;
            }
        }
    }

    return true;
}

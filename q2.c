#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Node to represent an edge in the graph
struct Node {
    int dest;
    struct Node* next;
};

// Structure to represent an adjacency list
struct AdjList {
    struct Node* head;
};

// Structure to represent the graph
struct Graph {
    int V; // Number of vertices
    struct AdjList* array;
};

// Function to create a new node
struct Node* createNode(int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    // Allocate memory for an array of adjacency lists
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));

    // Initialize each adjacency list as empty by making head as NULL
    for (int i = 0; i < V; ++i) {
        graph->array[i].head = NULL;
    }

    return graph;
}

// Function to add an edge to a directed graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

// Recursive function to perform DFS traversal and check for cycles
int isCyclicUtil(struct Graph* graph, int v, int visited[], int recStack[]) {
    if (visited[v] == 0) {
        visited[v] = 1;
        recStack[v] = 1;

        struct Node* temp = graph->array[v].head;
        while (temp != NULL) {
            int adjVertex = temp->dest;
            if (!visited[adjVertex] && isCyclicUtil(graph, adjVertex, visited, recStack)) {
                return 1;
            } else if (recStack[adjVertex]) {
                return 1;
            }
            temp = temp->next;
        }
    }
    recStack[v] = 0; // Remove the vertex from recursion stack when done
    return 0;
}

// Function to check if the directed graph contains a cycle
int isCyclic(struct Graph* graph) {
    int* visited = (int*)malloc(graph->V * sizeof(int));
    int* recStack = (int*)malloc(graph->V * sizeof(int));

    for (int i = 0; i < graph->V; ++i) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    // Check for cycles in the graph using DFS traversal
    for (int i = 0; i < graph->V; ++i) {
        if (isCyclicUtil(graph, i, visited, recStack)) {
            free(visited);
            free(recStack);
            return 1;
        }
    }

    free(visited);
    free(recStack);
    return 0;
}

// Test for cyclic existence in the graph
int main() {
    int V = 4; // Number of vertices
    struct Graph* graph = createGraph(V);

    // Adding edges to the graph (directed)
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);

    // Check if the graph contains a cycle
    if (isCyclic(graph)) {
        printf("The directed graph contains a cycle.\n");
    } else {
        printf("The directed graph does not contain a cycle.\n");
    }

    return 0;
}

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

// Recursive function to count paths between two vertices
int countPathsUtil(struct Graph* graph, int src, int dest, int visited[]) {
    if (src == dest) {
        return 1; // Found a path from src to dest
    }

    visited[src] = 1; // Mark the current vertex as visited

    int count = 0;
    struct Node* temp = graph->array[src].head;
    while (temp != NULL) {
        int adjVertex = temp->dest;
        if (!visited[adjVertex]) {
            // Recursively count paths from adjacent vertices to the destination
            count += countPathsUtil(graph, adjVertex, dest, visited);
        }
        temp = temp->next;
    }

    visited[src] = 0; // Mark the current vertex as unvisited for other paths
    return count;
}

// Function to count total paths between two vertices in the graph
int countPaths(struct Graph* graph, int src, int dest) {
    int* visited = (int*)malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; ++i) {
        visited[i] = 0; // Initialize all vertices as not visited
    }

    // Use DFS to count paths from src to dest
    int totalPaths = countPathsUtil(graph, src, dest, visited);

    free(visited);
    return totalPaths;
}

// Test the count of paths between vertices in the graph
int main() {
    int V = 5; // Number of vertices
    struct Graph* graph = createGraph(V);

    // Adding edges to the graph (directed)
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    int src = 0; // Source vertex
    int dest = 4; // Destination vertex

    // Count the total number of paths from src to dest
    int totalPaths = countPaths(graph, src, dest);
    printf("Total paths between vertex %d and vertex %d: %d\n", src, dest, totalPaths);

    return 0;
}

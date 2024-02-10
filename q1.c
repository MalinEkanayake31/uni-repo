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

// Depth-First Search (DFS) function
int isReachable(struct Graph* graph, int src, int dest, int visited[]) {
    if (src == dest) {
        return 1; // If source and destination are the same, a path exists
    }

    visited[src] = 1; // Mark the current vertex as visited

    struct Node* temp = graph->array[src].head;
    while (temp != NULL) {
        if (!visited[temp->dest]) {
            // Recursively check if destination can be reached from adjacent vertices
            if (isReachable(graph, temp->dest, dest, visited)) {
                return 1;
            }
        }
        temp = temp->next;
    }

    return 0; // If no path is found
}

// Function to check if a path exists from src to dest in the graph
int doesPathExist(struct Graph* graph, int src, int dest) {
    int* visited = (int*)malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; ++i) {
        visited[i] = 0; // Initialize all vertices as not visited
    }

    // Use DFS to check if there is a path from src to dest
    int result = isReachable(graph, src, dest, visited);

    free(visited);
    return result;
}

// Test the path existence in the graph
int main() {
    int V = 5; // Number of vertices
    struct Graph* graph = createGraph(V);

    // Adding edges to the graph (directed)
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    int src = 0; // Source vertex
    int dest = 3; // Destination vertex

    // Check if a path exists from src to dest
    if (doesPathExist(graph, src, dest)) {
        printf("There is a path from vertex %d to vertex %d.\n", src, dest);
    } else {
        printf("There is no path from vertex %d to vertex %d.\n", src, dest);
    }

    return 0;
}

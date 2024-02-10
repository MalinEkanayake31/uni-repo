#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent the adjacency list
struct AdjList {
    struct Node* head;
};

#define MAX_NODES 100

// Function to initialize the adjacency list
void initializeGraph(struct AdjList adjacencyList[MAX_NODES], int nodes) {
    for (int i = 0; i < nodes; i++) {
        adjacencyList[i].head = NULL; // Initializing all heads to NULL
    }
}

// Function to add an edge to the graph
void addEdge(struct AdjList adjacencyList[MAX_NODES], int source, int destination) {
    // Adding the edge from source to destination
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = destination;
    newNode->next = adjacencyList[source].head;
    adjacencyList[source].head = newNode;
}

// Function to print the adjacency list
void printGraph(struct AdjList adjacencyList[MAX_NODES], int nodes) {
    printf("Adjacency List:\n");
    for (int i = 0; i < nodes; i++) {
        printf("Node %d:", i);
        struct Node* current = adjacencyList[i].head;
        while (current != NULL) {
            printf(" -> %d", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

// Function to free the allocated memory for the adjacency list
void freeGraph(struct AdjList adjacencyList[MAX_NODES], int nodes) {
    for (int i = 0; i < nodes; i++) {
        struct Node* current = adjacencyList[i].head;
        while (current != NULL) {
            struct Node* nextNode = current->next;
            free(current);
            current = nextNode;
        }
    }
}

int main() {
    int nodes, edges;

    printf("Enter the number of nodes and edges: ");
    scanf("%d %d", &nodes, &edges);

    struct AdjList adjacencyList[MAX_NODES];

    initializeGraph(adjacencyList, nodes);

    printf("Enter edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        int source, destination;
        scanf("%d %d", &source, &destination);
        addEdge(adjacencyList, source, destination);
    }

    printGraph(adjacencyList, nodes);

    // Free allocated memory for the adjacency list
    freeGraph(adjacencyList, nodes);

    return 0;
}

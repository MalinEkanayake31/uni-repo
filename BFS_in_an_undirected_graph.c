#include<stdio.h>
#include<stdlib.h>

// Structure to represent a node
struct Node {
    int dest;
    struct Node* next;
};

// Structure to represent an adjacency list
struct AdjList {
    struct Node* head;
};

// Structure to create a graph
struct Graph {
    int V;   // Number of vertices
    struct AdjList* array;
};

// Function to create a new node
struct Node* createNode(int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;

    return newNode;
}

// Function to create a graph
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    // Allocate memory for an array of adjacency list
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));

    for (int i = 0; i < V; i++) {
        graph->array[i].head = NULL;
    }

    return graph;
}

// Function to add an edge to the undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since this is an undirected graph
    newNode = createNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Function to perform Breadth First Search (BFS)
void BFS(struct Graph* graph, int startVertex) {
    int* visited = (int*)malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; i++) {
        visited[i] = 0;
    }

    struct Node* queue = (struct Node*)malloc(graph->V * sizeof(struct Node));
    int front = 0, rear = 0;

    visited[startVertex] = 1;
    queue[rear].dest = startVertex;
    queue[rear].next = NULL;
    rear++;

    while (front < rear) {
        int currentVertex = queue[front].dest;
        printf("Visited %d\n", currentVertex);
        front++;

        struct Node* temp = graph->array[currentVertex].head;
        while (temp) {
            int adjVertex = temp->dest;
            if (visited[adjVertex] == 0) {
                visited[adjVertex] = 1;
                queue[rear].dest = adjVertex;
                queue[rear].next = NULL;
                rear++;
            }
            temp = temp->next;
        }
    }

    free(visited);
    free(queue);
}

// Function to print the adjacency list
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        struct Node* temp = graph->array[i].head;
        printf("\nAdjacency list of vertex %d\n", i);
        printf("Head");
        while (temp) {
            printf(" -> %d", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int V = 5; // Number of vertices
    struct Graph* graph = createGraph(V);

    // Adding edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Print the adjacency list representation of the graph
    printGraph(graph);

    // Perform BFS starting from vertex 2
    printf("\nBFS traversal starting from vertex 2:\n");
    BFS(graph, 2);

    return 0;
}

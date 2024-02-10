#include<stdio.h>
#include<stdlib.h>

//structure to represent a node
struct Node {
    int dest;
    struct Node* next;
};

//structure to represent an adjacency list
struct AdjList {
    struct Node* head;
};

//structure to create a graph
struct Graph {
    int V;   //no of vertices
    struct AdjList* array;
};

//function to create a new node
struct Node* createNode(int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

//function to create a graph
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    //allocate memory for an array of adjacency list
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));

    for (int i = 0; i < V; i++) {
        graph->array[i].head = NULL;
    }

    return graph;
}

//function to add an edge to the undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    //since this is an undirected graph
    newNode = createNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

//recursive function for DFS traversal
void DFSUtil(struct Graph* graph, int vertex, int* visited) {
    visited[vertex] = 1; // mark the current vertex as visited
    printf("%d ", vertex); // print the current vertex

    // explore all adjacent vertices
    struct Node* temp = graph->array[vertex].head;
    while (temp != NULL) {
        int adjVertex = temp->dest;
        if (!visited[adjVertex]) {
            DFSUtil(graph, adjVertex, visited); // recursively visit adjacent vertices
        }
        temp = temp->next;
    }
}

//function to perform DFS traversal starting from a given vertex
void DFS(struct Graph* graph, int startVertex) {
    int* visited = (int*)malloc(graph->V * sizeof(int)); // array to keep track of visited vertices

    for (int i = 0; i < graph->V; i++) {
        visited[i] = 0; // mark all vertices as not visited initially
    }

    printf("DFS traversal starting from vertex %d:\n", startVertex);
    DFSUtil(graph, startVertex, visited); // call recursive DFS function

    free(visited);
}

//function to print the adjacency list
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        struct Node* temp = graph->array[i].head;
        printf("\nadjacency list of vertex %d\n", i);
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

    // Perform DFS traversal starting from vertex 0
    DFS(graph, 0);

    return 0;
}

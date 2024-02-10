#include<stdio.h>
#include<stdlib.h>

struct AdjListNode
{
    int dest;
    struct AdjListNode* next;
};

struct AdjList
{
    struct AdjListNode* head;
};

struct Graph
{
    int V;
    struct AdjList* array;
};

//creating a new adjasency list node
struct AdjListNode* newAdjListNode(int dest)
{
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest=dest;
    newNode->next=NULL;
    return newNode;
}

struct Graph* createGraph(int V)
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V=V;

    graph->array = (struct AdjList*)malloc(V*sizeof(struct AdjList));

    for(int i=0;i<V;i++){
        graph->array[i].head = NULL;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->V; ++v) {
        struct AdjListNode* temp = graph->array[v].head;
        printf("Adjacency list of vertex %d\nhead ", v);
        while (temp) {
            printf("-> %d ", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int V, E;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    struct Graph* graph = createGraph(V);

    printf("Enter the details of each edge (src dest):\n");
    for (int i = 0; i < E; ++i) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("Adjacency list representation of the graph:\n");
    printGraph(graph);

    return 0;
}
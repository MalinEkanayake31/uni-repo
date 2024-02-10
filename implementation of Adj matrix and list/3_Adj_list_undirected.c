#include<stdio.h>
#include<stdlib.h>

#define MAX_NODES 100

struct Node
{
    int data;
    struct Node* next;
};

struct AdjList
{
    struct Node* head;
};

void initializeGraph(struct AdjList AdjacencyList[MAX_NODES],int nodes)
{
    for (int i = 0; i < nodes; i++)
    {
        AdjacencyList[i].head = NULL;
    }
}

void addEdge(struct AdjList AdjacencyList[MAX_NODES],int src,int dest)
{
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode ->data = dest;
    newnode ->next = AdjacencyList[src].head;
    AdjacencyList[src].head = newnode;

    newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode ->data = src;
    newnode ->next = AdjacencyList[dest].head;
    AdjacencyList[dest].head = newnode;

}

void printGraph(struct AdjList AdjacencyList[MAX_NODES],int nodes)
{
    printf("ADJACENCY LIST : \n");
    for (int i = 0; i < nodes; i++)
    {
        printf("Node %d ",i);
        struct Node* current = AdjacencyList[i].head;
        while (current != NULL)
        {
            printf(" -> %d ",current ->data);
            current = current ->next;
        }
        printf("\n");
    }
}

void freeGraph(struct AdjList AdjacencyList[MAX_NODES],int nodes)
{
    for (int i = 0; i < nodes; i++)
    {
        struct Node* current = AdjacencyList[i].head;
        while (current != NULL)
        {
            struct Node* nextnode = current ->next;
            free(current);
            current = nextnode;
        }
    }  
}

int main()
{
    int nodes,edges;

    printf("Enter the no of nodes and edges : ");
    scanf("%d %d ",&nodes,&edges);

    struct AdjList AdjacencyList[MAX_NODES];

    initializeGraph(AdjacencyList,nodes);

    for (int i = 0; i < edges; i++)
    {
        int src,dest;
        printf("Enter src and dest : \n");
        scanf("%d %d ",&src,&dest);
        addEdge(AdjacencyList,src,dest);
    }

    printGraph(AdjacencyList,nodes);

    freeGraph(AdjacencyList,nodes);

    return 0;
    
}
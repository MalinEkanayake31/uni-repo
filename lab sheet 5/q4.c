#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int vertex;
    struct Node *next;
};

struct Graph
{
    int numVertices;
    struct Node **adjList;
};

struct Node *createNode(int vertex)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

struct Graph *createGraph(int numVertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->adjList = (struct Node **)malloc(numVertices * sizeof(struct Node *));

    for (int i = 0; i < numVertices; ++i)
    {
        graph->adjList[i] = NULL;
    }

    for (int i = 0; i < numVertices; ++i)
    {
        for (int j = 0; j < numVertices; ++j)
        {
            if (i != j)
            {
                struct Node *newNode = createNode(j);
                newNode->next = graph->adjList[i];
                graph->adjList[i] = newNode;
            }
        }
    }

    return graph;
}

void printGraph(struct Graph *graph)
{
    for (int i = 0; i < graph->numVertices; ++i)
    {
        struct Node *temp = graph->adjList[i];
        printf("Friends of user %d: ", i);
        while (temp)
        {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

void freeGraph(struct Graph *graph)
{
    for (int i = 0; i < graph->numVertices; ++i)
    {
        struct Node *temp = graph->adjList[i];
        while (temp)
        {
            struct Node *toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjList);
    free(graph);
}

int main()
{
    struct Graph *socialNetwork = createGraph(3);

    printf("Social Network Representation:\n");
    printGraph(socialNetwork);

    freeGraph(socialNetwork);

    return 0;
}
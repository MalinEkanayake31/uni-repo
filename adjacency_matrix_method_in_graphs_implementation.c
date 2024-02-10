//this is for an undirected graph

#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 100

typedef struct 
{
    int vertices;
    int matrix[MAX_VERTICES][MAX_VERTICES];
}Graph;

void initialize_graph(Graph* g,int vertices)
{
    g ->vertices = vertices;

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            g ->matrix[i][j]=0;
        }
    }  
}

void addEdge(Graph* g,int src,int dest)
{
    g ->matrix[src][dest]=1;
    g ->matrix[dest][src]=1;
}

void printGraph(Graph* g)
{
    printf("Undirected graph in adjacency matrix :\n");
    for (int i = 0; i < g ->vertices; i++)
    {
        for (int j = 0; j < g ->vertices; j++)
        {
            printf("%d \n", g ->matrix[i][j]);
        }
    }
}

int main()
{
    Graph graph;
    int vertices,edges,src,dest;

    printf("Enter the no of vertices :");
    scanf("%d",&vertices);
    printf("\n");

    initialize_graph(&graph,vertices);

    printf("Enter the no of edges :");
    scanf("%d",&edges);
    printf("\n");

    printf("enter edges\n");
    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d", &src, &dest);
        addEdge(&graph,src,dest);
    }
    
    printGraph(&graph);

    return 0;

}
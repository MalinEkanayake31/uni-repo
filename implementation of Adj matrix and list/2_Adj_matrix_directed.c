#include<stdio.h>
#include<stdlib.h>

#define Max_nodes 100

void InitializeGraph(int AdjMatrix[Max_nodes][Max_nodes],int nodes)
{
    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0;j < nodes; j++)
        {
            AdjMatrix[i][j] = 0;
        }
    }
}

void AddEdge(int AdjMatrix[Max_nodes][Max_nodes],int src,int dest)
{
    AdjMatrix[src][dest] = 1;
}

void PrintGraph(int AdjMatrix[Max_nodes][Max_nodes],int nodes)
{
    printf("Adjacency Matrix : \n");

    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < nodes; j++)
        {
            printf("%d ", AdjMatrix[i][j]);
        }   
        printf("\n");
    }
}

int main()
{
    int nodes;
    int edges;

    printf("Enter no of nodes and edges : ");
    scanf("%d %d",&nodes,&edges);

    int AdjMatrix[Max_nodes][Max_nodes];

    InitializeGraph(AdjMatrix,nodes);

    for (int i = 0; i < edges; i++)
    {
        int src,dest;
        printf("Enter the src and dest : ");
        scanf("%d %d",&src,&dest);

        AddEdge(AdjMatrix,src,dest);
    }
    
    PrintGraph(AdjMatrix,nodes);

    return 0;
    
}
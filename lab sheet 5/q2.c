#include <stdio.h>
#include <stdlib.h>

int **createAdjMatrix(int numVertices)
{
    int **matrix = (int **)malloc(numVertices * sizeof(int *));

    for (int i = 0; i < numVertices; ++i)
    {
        matrix[i] = (int *)malloc(numVertices * sizeof(int));
        for (int j = 0; j < numVertices; ++j)
        {
            matrix[i][j] = 0; 
        }
    }

    return matrix;
}

void addEdge(int **matrix, int src, int dest)
{
    matrix[src][dest] = 1;
    matrix[dest][src] = 1; 
}

void printAdjMatrix(int **matrix, int numVertices)
{
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < numVertices; ++i)
    {
        for (int j = 0; j < numVertices; ++j)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int numVertices, numEdges;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    int **adjMatrix = createAdjMatrix(numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    for (int i = 0; i < numEdges; ++i)
    {
        int src, dest;
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(adjMatrix, src, dest);
    }

    printAdjMatrix(adjMatrix, numVertices);

    printf("\nTotal number of vertices: %d\n", numVertices);
    printf("Total number of edges: %d\n", numEdges);

    for (int i = 0; i < numVertices; ++i)
    {
        free(adjMatrix[i]);
    }
    free(adjMatrix);

    return 0;
}
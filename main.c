#include <stdio.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));

    int size, count = 0, i, j, graph_size = 0, ways = 0;
    int **graph;

    printf("\t# Graphs #\n\n");
    printf("Enter the number of graph vertices: ");
    scanf("%d", &size);

    // <---------- Task 1. Creating the graph ---------->
    // Memory allocation
    graph = (int **)(malloc(sizeof(int *) * (size + 1)));
    for(i = 0; i < size; i++)
        graph[i] = (int *)(malloc(sizeof(int *) * size));

    graph[i + 1] = malloc(sizeof(int));
    graph[i + 1] = NULL;

    // Filling the matrix
    for(i = 0; i < size; i++)
        for(j = i; j < size; j++)
        {
            graph[i][j] = rand() % 2;
            graph[j][i] = graph[i][j];
            if(i == j) graph[i][j] = 0;
            if(graph[i][j] == 1) ways++;
        }

    // Printing the matrix
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }

    // Finding size of the graph
    int **pointer = graph;  // Saving original pointer
    while(*graph != NULL)
    {
        graph++;
        graph_size++;
    }
    graph = pointer;

    printf("Size of the graph: %d\n", graph_size);

    // Finding isolated vertices
    for(i = 0; i < size; i++)
    {
        count = 0;
        for(j = 0; j < size; j++)
            if(graph[i][j] == 0) count++;

        if(count == size) printf("Isolated vertex: %d\n", i+1);
    }

    // Finding end vertices
    for(i = 0; i < size; i++)
    {
        count = 0;
        for(j = 0; j < size; j++)
        {
            if(graph[i][j] == 1) count++;
        }
        if(count == 1) printf("End vertex: %d\n", i+1);
        else if(count == (size - 1)) printf("Dominant vertex: %d\n", i+1);
    }

    //free(graph);


    // <---------- Task 2. Creating the graph ---------->

    int **Graph;
    int **vert;
    int k = 0;

    vert = (int **)malloc(sizeof(int *) * ways);  // array for vertices
        for(i = 0; i < ways; i++)
            vert[i] = (int *)malloc(sizeof(int *) * 2);

    Graph = (int **)(malloc(sizeof(int *) * ways));
    for(i = 0; i < size; i++)
        Graph[i] = (int *)(malloc(sizeof(int *) * size));

    printf("\nWays: %d\n", ways);

        for(i = 0; i < size; i++)
        {
            for(j = i; j < size; j++)
            {
                if(graph[i][j] == 1)
                {
                    vert[0][k] = i;
                    vert[1][k] = j;
                    k++;
                }
            }
        }


    for(j = 0; j < k; j++)
    {
        i = vert[0][j];
        Graph[i][j] = 1;
        i = vert[1][j];
        Graph[i][j] = 1;
        i = 0;
    }

    for(i = 0; i < size; i++)
    {
        for(j = 0; j < k; j++)
            printf("%d", Graph[i][j]);
        printf("\n");
    }



    return 0;
}

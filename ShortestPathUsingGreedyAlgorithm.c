#include <stdio.h>
#define INFINTE 9999
#define MAX 10

void dijkstra(int G[MAX][MAX], int k, int startnode);

int main()
{
    int G[MAX][MAX], i, j, k, u;
    printf("Enter no. of vertices:");
    scanf("%d", &k);
    printf("\nEnter the adjacency matrix:\n");
    for (i = 0; i < k; i++)
        for (j = 0; j < k; j++)
            scanf("%d", &G[i][j]);
    printf("\nEnter the starting node:");
    scanf("%d", &u);
    dijkstra(G, k, u);
    return 0;
}

void dijkstra(int G[MAX][MAX], int k, int startnode)
{
    int travel_cost[MAX][MAX], path_distance[MAX], pre[MAX];
    int visited[MAX], count, min_path_dist, nextnode, i, j;

    for (i = 0; i < k; i++)
        for (j = 0; j < k; j++)
            if (G[i][j] == 0)
                travel_cost[i][j] = INFINTE;
            else
                travel_cost[i][j] = G[i][j];

    for (i = 0; i < k; i++)
    {
        path_distance[i] = travel_cost[startnode][i];
        pre[i] = startnode;
        visited[i] = 0;
    }
    path_distance[startnode] = 0;
    visited[startnode] = 1;
    count = 1;
    while (count < k - 1)
    {
        min_path_dist = INFINTE;
        // nextnode = the node at minimum distance
        for (i = 0; i < k; i++)
            if (path_distance[i] < min_path_dist && !visited[i])
            {
                min_path_dist = path_distance[i];
                nextnode = i;
            }

        // checking if a better path exists through nextnode
        visited[nextnode] = 1;
        for (i = 0; i < k; i++)
            if (!visited[i])
                if (min_path_dist + travel_cost[nextnode][i] < path_distance[i])
                {
                    path_distance[i] = min_path_dist + travel_cost[nextnode][i];
                    pre[i] = nextnode;
                }
        count++;
    }

    // printing path and distance of all nodes
    for (i = 0; i < k; i++)
        if (i != startnode)
        {
            printf("\nDistance of node%d=%d", i, path_distance[i]);
            printf("\nPath=%d", i);
            j = i;
            do
            {
                j = pre[j];
                printf("<---%d", j);
            } while (j != startnode);
        }
}
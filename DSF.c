// this is just a simple implementation of the DSF ( Depth First Seacrh )
// DSf uses stack, here we fill use functions cause they are also in stack when we call them
#include <stdio.h>
#include <stdlib.h>

int visited[7] = {0, 0, 0, 0, 0, 0, 0}; // variable decleration
int A[7][7] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0}};

void dfs(int i) // function for DFS
{
    printf("% d ", i);          // printing the node
    visited[i] = 1;             // marking that node as visited
    for (int j = 0; j < 7; j++) // loop to check for the nodes connected to it
    {
        if (A[i][j] == 1 && visited[j] == 0)
        {
            dfs(j); // calling DFS function for the nodes which are not yet visited
        }
    }
}

int main(int argc, char const *argv[])
{
    dfs(0);
    return 0;
}

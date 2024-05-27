#include <stdio.h>

int floydWarshall(int arr[4][4], int v)
{
    int k, i, j;
    for(k = 0; k < v; k++)
    {
        for(i = 0; i < v; i++)
        {
            for(j = 0; j < v; j++)
            {
                if(arr[i][j] > arr[i][k] + arr[k][j])
                {
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }
    for(k = 0; k < v; k++)
    {
        for(i = 0; i < v; i++)
            printf("%d | ", arr[k][i]);
        printf("\n");
    }
}

int main()
{
    int v = 4;
    int ent[v][v];
    for(int i = 0; i < v; i++)
    {
        for(int j = 0; j < v; j++)
        {
            printf("Enter for (%d%d): ", i, j);
            scanf("%d", &ent[i][j]);
        }
    }
    printf("----------------------\n");
    floydWarshall(ent, v);
    return 0;
}
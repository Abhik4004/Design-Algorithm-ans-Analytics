#include <stdio.h>
#include <stdlib.h>

void bfs(int **ptr, int n, int start)
{
    int *visited, *queue, front, rear;
    front = 0;
    rear = -1;
    visited = (int*)calloc(n,sizeof(int));
    queue = (int*)calloc(n,sizeof(int));

    visited[start] = 1;
    queue[++rear] = start;
    printf("\n\nBFS: \n\n");

    while(front <= rear)
    {
        start = queue[front++];
        printf("%d\t", start);
        for(int i = 0; i < n; i++)
        {
            if(ptr[start][i] == 1 && visited[i] != 1)
            {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}


int main()
{
    int n;
    printf("Enter n: \n");
    scanf("%d", &n);

    int **arr = (int**)calloc(n, sizeof(int*));
    for(int j = 0; j<n; j++)
        arr[j] = (int*)calloc(n,sizeof(int));
    
    printf("Enter value: \n");
    for(int j = 0; j<n; j++)
        for(int k = 0; k<n; k++)
            scanf("%d", &arr[j][k]);

    bfs(arr, n, 0);
    return 0;
}
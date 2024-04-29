#include <stdio.h>
#include <stdlib.h>

int dfs(int **ptr, int n, int *visited, int start)
{
    printf("%d\t", start);
    visited[start] = 1;
    for(int i = 0; i < n; i++)
    {
        if(visited[i] != 1 && ptr[start][i] == 1)
            dfs(ptr, n, visited, i);
    }
}
int main() {
    int n;
    printf("Enter n: \n");
    scanf("%d", &n);
    int *visited = (int*)calloc(n,sizeof(int));
    int **arr = (int**)calloc(n, sizeof(int*));
    for(int j = 0; j<n; j++)
        arr[j] = (int*)calloc(n,sizeof(int));
    
    printf("Enter value: \n");
    for(int j = 0; j<n; j++)
        for(int k = 0; k<n; k++)
            scanf("%d", &arr[j][k]);
    
    dfs(arr, n, visited, 0);
    return 0;
}
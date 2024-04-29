#include <stdio.h>
#include <stdlib.h>

int floydWarshal(int **arr, int n)
{
    int i, j, k;
    for(i = 0; i <n; i++)
    {
        for(j = 0; j < n; j++)
        {
            for(k = 0; k < n; k ++)
            {
                if(arr[i][j] > arr[i][k] + arr[k][j])
                {
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }

    for(i = 0; i <n; i++){
        for(j = 0; j < n; j++){
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
            
}


int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("\n");
    int **arr = (int**)calloc(n, sizeof(int*));
    for(int j = 0; j<n; j++)
        arr[j] = (int*)calloc(n,sizeof(int));
    
    printf("Enter value: \n");
    for(int j = 0; j<n; j++)
        for(int k = 0; k<n; k++)
            scanf("%d", &arr[j][k]);
    
    floydWarshal(arr, n);

    return 0;
}
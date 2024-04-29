#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void take(int *prof, int *wt, int n, int M)
{
    int k[n+1][M+1];
    for(int i = 0; i<= n; i++)
    {
        for(int j =0; j <= M; j++)
        {
            if(i == 0 || j == 0 )
                k[i][j] = 0;
            else if(wt[i - 1] <= j)
                k[i][j] = max(prof[i - 1] + k[i - 1][j - wt[i - 1]], k[i - 1][j]);
            else 
                k[i][j] = k[i - 1][j];
        }
    }

    printf("The total profit is %d", k[n][M]);
}

int main()
{
    int n = 3;
    int *prof = (int*)calloc(n,sizeof(int));
    int *wt = (int*)calloc(n,sizeof(int));
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &prof[i]);
        scanf("%d", &wt[i]);
    }

    take(prof, wt, n, 50);

    return 0;
}
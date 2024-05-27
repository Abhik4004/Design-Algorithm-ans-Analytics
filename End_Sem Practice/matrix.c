#include <stdio.h>
#include <limits.h>
void matrix(int arr[], int n)
{
    int m[n][n];
    int l, i, j, k, q;

    for(i = 0; i < n; i++)
        m[i][i] = 0;

    for(l = 2; l < n; l++)
    {
        for(i = 1; i< n - l + 1; i++)
        {
            j = i + l - 1;
            m[i][j] = __INT_MAX__;
            for(k = i ;k <= j; k++)
            {
                q = m[i][k] + m[k+1][j] + arr[i-1]*arr[k]*arr[j];
                if(q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    printf("Min ---> %d\n", m[1][n-1]);
}

int main() {
    int n;
    printf("Enter n: \n");
    scanf("%d", &n);
    int dimension [n];
    for(int i = 0; i < n; i++)
    {
        printf("Enter dimension: \n");
        scanf("%d", &dimension[i]);
    }

    matrix(dimension, n);
    return 0;
}
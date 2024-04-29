#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int matrix(int arr[], int n)
{
    int mul[n][n];

    for(int i = 0; i < n; i++)
        mul[i][i] = 0;

    for(int L = 2; L < n; L++)
    {
        for(int i = 0; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            mul[i][j] = __INT_MAX__;
            for(int k = i ; k <= j - 1; k++)
            {
                int q = mul[i][k] + mul[k + 1][j] + (arr[i - 1] * arr[k] * arr[j]);
                if( q < mul[i][j])
                    mul[i][j] = q;
            }
        }
    }

    return mul[1][n - 1];
}


int main()
{
    int n = 5;
    int arr[5] = {2, 3, 4, 5, 7};
    printf("%d", matrix(arr, n));
    return 0;
}
#include<stdio.h>
#include<string.h>
int max(int a, int b)
{
    return (a>b)?a:b;
}

int zeroorone(int p[], int wt[], int M, int n)
{
    int arr[n+1][M+1];
    for(int i = 0; i <= n; i++)
    {
        for(int w = 0; w <= M; w++)
        {
            if(i ==0 || w==0)
                arr[i][w] = 0;

            else if(wt[i-1] <= w)
            {
                arr[i][w] = max(p[i-1] + arr[i-1][w-wt[i-1]], arr[i-1][w]);
            }else{
                arr[i][w] = arr[i-1][w];
            }
        }
    }

    printf("Total profit is %d\n", arr[n][M]);

    int k = M;
    int selected[n];
    memset(selected, 0, sizeof(selected));
    for(int i =n; i > 0 && k > 0; i--)
    {
        if(arr[i][k] != arr[i - 1][k])
        {
            selected[i - 1] = 1;
            k -= wt[i - 1];
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d", selected[i]);
    }
}

int main() {
    int n;
    printf("Enter no of items: \n");
    scanf("%d", &n);
    int p[n], w[n];

    for(int i = 0; i<n; i++)
    {
        printf("Enter profit: ");
        scanf("%d", &p[i]);
        printf("Enter weight: ");
        scanf("%d", &w[i]);
    }

    zeroorone(p,w, 50, n);
    return 0;
}
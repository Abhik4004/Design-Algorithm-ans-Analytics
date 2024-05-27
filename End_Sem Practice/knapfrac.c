#include <stdio.h>
#include <stdlib.h>

typedef struct sack {
    float profit;
    float wt;
    float pw;
}knap;

void bubbleSort(knap arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j <n - i - 1; j++)
        {
            if(arr[j].pw < arr[j+1].pw)
            {
                knap temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int knapSack(knap arr[], int n, int W)
{
    int current, total;
    current = total = 0;
    for(int i = 0; i < n; i++)
    {
        if(current + arr[i].wt <= W)
        {
            current += arr[i].wt;
            total += arr[i].profit;
        } else {
            int rem = W - arr[i].wt;
            total += arr[i].pw * rem;
            break;
        }
    }
    printf("Total profit is %d\n", total);
}

int main() {
    int n, M;
    printf("Enter no of items: \n");
    scanf("%d", &n);
    knap sack[n];

    for(int i = 0; i < n; i++)
    {
        printf("Enter profit: ");
        scanf("%f", &sack[i].profit);
        printf("Enter weight: ");
        scanf("%f", &sack[i].wt);
        sack[i].pw = sack[i].profit / sack[i].wt;
    }

    bubbleSort(sack, n);
    for(int i = 0; i < n; i++)
    {
        printf("%f | %f | %f\n", sack[i].profit, sack[i].wt, sack[i].pw);
    }

    printf("Enter maximum capacity: \n");
    scanf("%d", &M);

    knapSack(sack, n, M);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct sack {
    float p;
    float w;
    float r;
};

void bubble(struct sack sack[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(sack[j].r < sack[j+1].r)
            {
                struct sack temp = sack[j];
                sack[j] = sack[j + 1];
                sack[j + 1] = temp;
            }
        }
    }
}

void frac(struct sack sack[], int n, int M)
{
    float total, current;
    total = current = 0;

    for(int i = 0; i < n; i++)
    {
        if(current + sack[i].w <= M)
        {
            current += sack[i].w;
            total += sack[i].p;
        } else {
            int rem = M - current;
            total += sack[i].r * rem;
        }
    }

    printf("Total profit is %f\n", total);
}

int main()
{
    int n = 3;
    struct sack sack[] = {{60, 10, 0}, {100, 20, 0}, {120, 30, 0}};
    int M = 40;

    for(int i = 0; i < n; i++)
        sack[i].r = sack[i].p / sack[i].w;
    bubble(sack, n);
    frac(sack, n, M);
    return 0;
}
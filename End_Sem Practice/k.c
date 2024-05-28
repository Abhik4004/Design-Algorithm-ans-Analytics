#include <stdio.h>
#include <stdlib.h>

int compare(const void *p1, const void *p2)
{
    return(((int(*)[3])p1)[0][2] - ((int(*)[3])p2)[0][2]);
}

int makesSet(int p[], int r[], int n)
{
    for(int i = 0; i < n; i++)
    {
        p[i] = i;
        r[i] = 0;
    }
}

int findP(int p[], int c)
{
    if(p[c] == c)
        return c;
    return findP(p, p[c]);
}

int Uset(int p[], int r[], int u, int v, int n)
{
    u = findP(p, u);
    v = findP(p, v);
    if(r[u] < r[v])
        p[u] = v;
    else if(r[v] < r[u])
        p[v] = u;
    else {
        p[v] = u;
        r[u]++;
    }
}

int k(int edge[][3], int n)
{
    int p[n], r[n], u, v, min = 0, wt;
    makesSet(p, r, n);
    qsort(edge, n, sizeof(edge[0]),compare);
    printf("MST: \n\n");
    for(int i = 0; i < n; i++)
    {
        u = findP(p, edge[i][0]);
        v = findP(p, edge[i][1]);
        wt = edge[i][1];
        if(u != v)
        {
            Uset(p, r, u, v, n);
            min += wt;
            printf("%d-------------%d | %d\n", edge[i][0], edge[i][1], wt);
        }
    }

    printf("%d is min cost.", min);

}

int main()
{
    int edge[][3] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };
    int n = sizeof(edge) / sizeof(edge[0]);
    k(edge, n);
    return 0;
}

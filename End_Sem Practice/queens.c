#include<stdio.h>
#include<stdlib.h>

int board[10];

int print(int n)
{
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            if(board[i] == j)
            {
                printf("Q ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
}


int place(int row, int col)
{
    for(int i = 1; i <= row - 1; ++i)
    {
        if(board[i] == col)
            return 0;
        else if (abs(board[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}

int nQueens(int row, int n)
{
    for(int col = 1; col <= n; ++col)
    {
        if(place(row, col))
        {
            board[row] = col;
            if(row == n)
                print(n);
            else 
                nQueens(row+1, n);
        }
    }
}
int main()
{
    int n;
    printf("Enter no of queens: \n");
    scanf("%d", &n);
    nQueens(1, n);
    return 0;
}
#include <stdio.h>
int N,M;
char board[51][51];

int solv(int r, int c){
    int cnt = 0;
    int min;

    for(int i=r;i<r+8;i++)
    {
        for(int j=c;j<c+8;j++)
        {
            if(i%2==0)
            {
                if(j%2==0)
                {
                    if(board[i][j]== 'W')
                        cnt++;
                }
                else
                {
                    if(board[i][j]== 'B')
                        cnt++;
                }
            }
            else
            {
                if(j%2==0)
                {
                    if(board[i][j]== 'B')
                        cnt++;
                }
                else
                {
                    if(board[i][j]== 'W')
                        cnt++;
                }
            }

        }
    }

    min = cnt;
    cnt = 0;
    for(int i=r;i<r+8;i++)
    {
        for(int j=c;j<c+8;j++)
        {
            if(i%2==0)
            {
                if(j%2==0)
                {
                    if(board[i][j]== 'B')
                        cnt++;
                }
                else
                {
                    if(board[i][j]== 'W')
                        cnt++;
                }
            }
            else
            {
                if(j%2==0)
                {
                    if(board[i][j]== 'W')
                        cnt++;
                }
                else
                {
                    if(board[i][j]== 'B')
                        cnt++;
                }
            }

        }
    }

    if(min > cnt)
        min = cnt;
    return min;

}

int main()
{
    int min = 2147483647;
    int sol;
    scanf("%d %d", &N, &M);
    for(int i=0;i<N;i++)
    {
        getchar();
        for(int j=0;j<M;j++) {
            scanf("%c", &board[i][j]);
        }
    }

//    printf("*************************************\n");
//    for(int i=0;i<N;i++)
//    {
//        for(int j=0;j<M;j++) {
//            printf("%c", board[i][j]);
//        }
//        printf("\n");
//    }

    for(int i=0;i<N-7;i++)
    {
        for(int j=0;j<M-7;j++)
        {
            sol = solv(i,j);
            if(sol < min)
                min = sol;
        }
    }
    printf("%d", min);
}
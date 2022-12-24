#include <stdio.h>
int T;
int wh[50][3];

int main()
{
    scanf("%d", &T);
    for(int i = 0; i<T;i++)
    {
        scanf("%d %d", &wh[i][0], &wh[i][1]);
    }

    for(int i =0;i<T;i++)
    {
        wh[i][2] = 1;
        for(int j=0;j<T;j++)
        {
            if(wh[i][0] < wh[j][0] && wh[i][1] < wh[j][1])
            {
                //printf("check: %d > %d\n", i , j);
                wh[i][2]++;
            }

        }
    }

    for(int i =0;i<T;i++)
        printf("%d ", wh[i][2]);



}
#include <stdio.h>

int num[100001];
int N;
int sum[100001];
int min[100001];

int main()
{
    int max=-1987654;
    int ret,minnum;
    scanf("%d", &N);
    for(int i=0;i<N;i++)
    {
        scanf("%d", &num[i]);
    }
    sum[0] =num[0];
    for(int i=1;i<N;i++)
        sum[i]= sum[i-1] + num[i];
    minnum = sum[0];
    for(int i=0;i<N;i++)
    {
        min[i] = minnum;
        if(sum[i] < minnum)
            minnum = sum[i];
    }
//
//    printf("\n");
//    for(int i=0;i<N;i++)
//        printf(" %d", min[i]);
    for(int i=0;i<N;i++)
    {
        if(i != 0)
            ret = sum[i]-min[i];
        else
            ret = sum[i];
       if(ret < sum[i])
           ret = sum[i];
       //printf("%d ", ret);
       if(ret > max)
           max = ret;
    }//printf("\n");
    printf("%d", max);

}
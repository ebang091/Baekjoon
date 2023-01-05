#include <stdio.h>

int main()
{
    int N,M,K;
    scanf("%d", &K);
    for(int i=0;i<K;i++)
    {
        scanf("%d %d", &N, &M);
        printf("%d\n", N+M);
    }
}
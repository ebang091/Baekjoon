#include <stdio.h>
#include <string.h>

unsigned long long answer[1000001];
int N;
void init()
{
    answer[1] = 1;
    answer[2] = 2;
    for(int i =3;i<=N;i++)
    {
        answer[i] = (answer[i-1] + answer[i-2])%15746;
        //printf("%llu ", answer[i]);
    }
}

int main()
{
    scanf("%d", &N);
    init();
    unsigned long long ret =  answer[N];
    printf("%llu", ret);

}
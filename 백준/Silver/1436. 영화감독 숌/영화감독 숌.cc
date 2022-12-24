#include <stdio.h>
int N;

/*
 * 666      0
 * 1666     1
 * 2666     2
 * ...
 * 9666     8
 * 10666    9
 * 11666    10
 * 12666    11
 * ...
 * 15666    14
 * 16660    15
 * 16661    16
 * 16662    17
 * ...
 * 16669    24
 *
 *
 */

int solv(int n)//6이 3개이상인지 확인.
{
    int cnt = 0;
    int copy = n;
    int flag = 1;
    int max = -1;
    while(copy)
    {
        if(copy%10 == 6) {
            cnt++;
            if(max < cnt)
                max = cnt;
            flag = 1;
        }
        else {
            flag = 0;
            cnt=  0;
        }
        copy/=10;
    }
    if(max >= 3)
        return 1;
    return 0;
}

long long func(int n)
{
    int cnt = 0;
    int i = 1;
    int answer;
    while(1)
    {
        if(solv(i)) {
            cnt++;
            answer = i;
        }
        if(cnt == n)
            break;
        i++;
    }
    return answer;
}

int main()
{
    scanf("%d", &N);
    printf("%d ", func(N));
}
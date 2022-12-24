#include <stdio.h>
int N;
long long num[20];
int number = 0;
#define MIN 2147483647
//num = {8, 9 , 1}
long long  solve(int  n)//분해합 구하기
{
    long long sum =(long long) n;
    int copy = n; //sum + =198 sum += 1, +=8 , +=9
    number = 0;
    while(copy)
    {
        num[number++] = copy%10;
        copy /=10;
    }
    for(int i=number-1; i>=0;i--)
    {
        //printf("num : %d,", num[i]);
        sum+=num[i];
    }
    //printf("%d - %d\n", n, sum);
    return sum;
}

int generator()
{
    int min = MIN;
    int i = N;
    while(i >= 0)
    {
        if(N== solve(i)) //i라는 수의 분해합이 n이라면 i N의 생성자.
        {
            if(min > i)
                min = i;
            //printf("%d- %d\n", solve(i), i);
        }
        i--;
    }
    if(min == MIN)
        return 0;
    else
        return min;
}

int main()
{
    scanf("%d", &N);
    printf("%d", generator());
}
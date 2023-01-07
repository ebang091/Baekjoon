#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <string.h>

using namespace std;

int number(int n)
{
    int cnt=0;
    int copy = n;
    while(copy)
    {
        cnt++;
        copy /= 10;
    }
    return cnt;
}

int  isPalindromic(int n)//양의 정수, 5자리 이하의 정수를 문자열로 만들어서 반환하는 함수
{
    char str[10];
    int cnt = number(n);
    str[cnt--] = '\0';
    int copy = n;
    while(copy)
    {
        str[cnt--] = copy % 10 + '0';
        copy /=10 ;
    }
    int c = number(n);
    for(int i=0;i<c/2;i++)
    {
        if(str[i] != str[c-i-1])
            return false;
    }
    return true;

}


void check(int n)
{
    if(isPalindromic(n))
        cout << "yes\n";
    else
        cout << "no\n";
}

int main()
{
    int N;
    while(1)
    {
        scanf("%d", &N);
        if(N == 0)
            return (0);
        check(N);

    }
}
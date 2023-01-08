#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <string.h>

using namespace std;
int N,M;

int isPrime(int n)//소수인지 판별. 소수 == 자신 제외 1보다 큰 인수를 가지는 경우
{
    if(n == 1)
        return false;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i == 0)
            return false;
    }
    return true;
}

int main()
{
    cin >> N;
    int n;
    int cnt = 0;
    for(int i=0;i<N;i++)
    {
        cin >> n;
        if(isPrime(n))
            cnt++;
    }
    cout << cnt;

}
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int M,N;

bool isPrime(int n)
{
    if(n == 1)
        return false;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

int main() {
    cin >> M >> N;
    long long sum = 0;
    int min = 1987654;
    int flag = 0;
    for (int i = M; i <= N; i++)
    {
        if(isPrime(i))
        {
            flag = 1;
            sum += i;
            if(i < min)
                min = i;
        }
    }
    if (!flag)
        cout <<"-1";

    else {
        cout << sum << "\n";
        cout << min;
    }

}
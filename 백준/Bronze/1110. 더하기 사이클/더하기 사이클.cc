#include <unistd.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 198765432

using namespace std;

int main()
{
    long long  n;
    cin >> n;
    int cnt = 0;
    long long copy;
    long long sum;
    long long newn;
    int num = n;
    while(1)
    {
        int copy = num;
        sum = 0;
        while(copy > 0)
        {
            sum += copy % 10;
            copy /= 10;
        }
        newn = num%10*10 + sum%10;
        cnt++;
        if (newn == n)
            break;
        num = newn;

    }
    cout << cnt;
}

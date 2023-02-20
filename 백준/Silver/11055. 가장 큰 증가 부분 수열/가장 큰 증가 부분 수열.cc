#include <unistd.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 198765432
#define MAX 1002
int N;
using namespace std;
long long A[MAX];
long long cache[MAX];

void input()
{
    for (int i = 0; i < N;i++)
        cin >> A[i];
}

long long  lis(int start)
{
    long long& ret = cache[start];
    if (ret != -1) return ret;
    ret = A[start];
    for (int next = start + 1; next < N; ++next)
    {
        if (A[start] < A[next])
            ret = max(ret, lis(next) + A[start]);
    }
    return ret;
}

void init()
{
    for (int i = 0; i < N; i++)
        cache[i] = -1;
}

int solve()
{
    long long ret = -1;
    for(int i = 0; i < N;i++)
        ret = max(ret, lis(i));
    return ret;
}

int main()
{
    cin >> N;
    init();
    input();
    cout << solve();
}
#include <unistd.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 198765432
#define MAX 1000001
int N;
using namespace std;
long long A[MAX];
long long cache[MAX];
vector <int> S;

void input()
{
    for (int i = 0; i < N;i++)
        cin >> A[i];
}

long long solve()
{
    S.push_back(A[0]);
    for(int i= 0;i<N;i++)
    {
        if(S.back() < A[i]) S.push_back(A[i]);
        auto that = lower_bound(S.begin(), S.end(), A[i]);
        *that = A[i];
    }
    return (long long)S.size();
}

void init()
{
    for(int i=0;i<N;i++)
        cache[i] = -INF;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    input();
    init();
    cout << solve();
}
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
vector <int> S;

void input()
{
    for (int i = 0; i < N;i++)
        cin >> A[i];
}


long long solve()
{
    //DP[i] : 길이가 i인 수열 중 가장 작은  마지막 값.

    for(int i=0; i < N;i++)
    {
        if(S.size() == 0 || S.back() < A[i]) S.push_back(A[i]);
        else
        {
            vector <int>::iterator that = lower_bound(S.begin(), S.end(), A[i]);
            *that = A[i];
        }
    }
    return (long long)S.size();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    input();
    cout << solve();
}
#include <unistd.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 2147483647
#define MAX 501
int N;
using namespace std;
long long matrix[MAX][2];
long long DP[MAX][MAX];

void input()
{
  long long a, b;
    for(int i=1;i<=N;i++)
    {
        cin >> a >> b;
        matrix[i][0] = a;
        matrix[i][1] = b;
    }
}

void solve()
{
    for(int i = 1; i < N ; i++)
    {
        for(int j = 1; i + j <= N ; j++)
        {
            DP[j][i+j] = INF;
            for(int k = j; k <= i + j ; k++)
                DP[j][i+j] = min(DP[j][i+j], DP[j][k] + DP[k+1][i+j] + matrix[j][0] * matrix[k][1] * matrix[i+j][1]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    input();
    solve();
    cout << DP[1][N];


}
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

#define R 1
#define G 2
#define B 3

using namespace std;
#define MAX 1000001
int N;
long long  DP[MAX][10];


long long findmin(long long  a, long long b)
{
    return a < b ? a : b;
}

int main()
{
    cin >> N;
    for(int i=0;i<10;i++)
    {
        if(i != 0)
            DP[1][i] = 1;
        else
            DP[i][i] = 0;
    }

    for(int j=2;j<=N;j++)
    {
        for(int i=0;i<10;i++)
        {
            if(i == 0)
                DP[j][i] = (DP[j-1][1]);
            else if(i == 9)
                DP[j][i] = (DP[j-1][8]);
            else{
                DP[j][i] = (DP[j-1][i-1])%1000000000 + (DP[j-1][i+1])%1000000000;
            }
        }
    }
    long long sum = 0;
    for(int i=0;i<10;i++)
        sum += (DP[N][i]) % 1000000000;
    cout << sum % 1000000000;

}
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <algorithm>
#include <map>
#include <stack>
#include <cstring>
#include <sstream>
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

#define NONE -1
#define INF 19876543
long long dp[1001][10];
int N,T;
int main(){
    FAST
    cin >> N;

    for(int i = 0; i < 10; i++)
        dp[1][i] = 1;

    for(int i = 0; i < 10; i++)
        dp[2][i] = 10 - i;

    for(int i = 3; i <= N; i++){
    dp[i][9] = dp[i-1][9];
        for(int j = 8; j >= 0; j--){
            dp[i][j] = (dp[i][j+1] + dp[i-1][j]) % 10007;
        }
    }
    long long ans = 0;
    for(int j = 0; j < 10; j++){
        ans = (ans + dp[N][j]) %10007;
    }
    cout << ans;
}
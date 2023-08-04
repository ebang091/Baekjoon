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
long long dp[91];
// long long ans[91];
int N,T;
int main(){
    FAST
    cin >> N;

    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    dp[4] = 3;



    for(int i = 5 ; i <= N; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
        

    cout << dp[N];
}
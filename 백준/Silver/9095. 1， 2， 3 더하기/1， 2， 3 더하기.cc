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
long long dp[12];
int N,T;
int main(){
    FAST
    cin >> T;


    for(int t = 0; t < T; t++){
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        cin >> N;
        for(int i = 4; i <= N; i++){
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        cout << dp[N] << "\n";
    }
}
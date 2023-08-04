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
#define INF 198765432
long long dp[1001];
int N;
int main(){
    FAST
    cin >> N;
    dp[1] = 1;
    dp[2] = 3;
    for(int i = 3; i <= N; i++)
        dp[i] = (dp[i-1] % 10007 + dp[i-2]*2 % 10007 ) % 10007 ;
    cout << dp[N];

    

}
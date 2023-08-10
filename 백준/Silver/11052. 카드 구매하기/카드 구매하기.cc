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
// #define SIZE (1 << 17)
long long SIZE;
vector<int> tree;
int nums[10001];
long long dp1[1001] = {0,};
int N;

/*
dp[i] = 카드를 i개 살때 최대 금액

dp[k] = max(dp[k], dp[i] + dp[k-i]) (i = 1 ... K/2)

*/

int main(){
    FAST
    cin >> N ;
    for(int i = 1; i <= N; i++)
        cin >> nums[i];
    dp1[1] = nums[1];
    for(int i = 2; i <= N; i++){
        dp1[i] = nums[i];
        for(int j = 1; j <= i/2; j++){
            dp1[i] = max(dp1[i], dp1[j] + dp1[i - j]);
        }
    }
    cout << dp1[N];
}
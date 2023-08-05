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
int nums[100001];
int dp1[100001];
int N,T;
/*
특정 위치까지의 가장 긴 증가하는 수열 +  특정 위치부터 가장 긴 감소하는 수열
dp1[i] = i 위치까지 가장 긴 증가하는 수열의 길이
dp[i] = max(dp[j] + 1, dp2[i]) j < i, aj < ai

dp2[i] = max(dp[j] + 1, dp2[i]) j > i, aj > ai

dp1[i] + dp[2] 의 합 중 가장 큰 값을 선정한다.
*/

long long max(int a, int b){
    return a > b ? a: b;
}

int main(){
    FAST
    cin >> N;
    int n;
    int maxV = -INF;
    for(int i = 0; i < N ; i++){
        cin >> nums[i];
    }

    for(int i = 0 ; i < N; i++){
        dp1[i] = nums[i];
        dp1[i] = max(dp1[i], dp1[i -1] + nums[i]);
        if(dp1[i] > maxV)
            maxV = dp1[i];
    }

    cout << maxV;



    


    
}
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
long long dp1[100001]= {0,};
int N,T;
/*
dp[k] = k라는 수를 제곱수로 표현할 떄 최소 항의 수
초깃값: k (1 k개)

dp[k] = max(dp[k], dp[k - i*i]  + 1)
i는 i*i <= k인 i. 
제곱수에 대해 그 제곱수를 빼고 남은 수를 표현하는데 필요한 항의 수 + 제곱수 1개
*/

long long max(int a, int b){
    return a > b ? a: b;
}

int main(){
    FAST
    cin >> N;
    dp1[0] = 1;
    dp1[1] = 0;
    dp1[2] = 3;
    for(int i = 3; i <= N ; ++i){
        if(i % 2 == 1) {
            continue;
        }
        for(int j = 2; j <= i ; j+=2){
            if(j == 2)
                dp1[i] += dp1[i-j]*3;
            else
                dp1[i] += dp1[i-j]*2;
        }
    }
   cout << dp1[N];
}
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
long long dp1[201][201]= {0,};
int N,K;
/*
dp1[K][N] = N을 k 개의 수로 표현할 수 있는 경우의 수. 
[i][j] 꼴일 때 숫자가 j에 해당하는 위치여야한다는 것을 잊지 말자,,,

*/

long long max(int a, int b){
    return a > b ? a: b;
}

int main(){
    FAST
    cin >> N >> K;
    long long MOD = 1000000000;

    dp1[0][0] = 1;
    for(int i = 1; i <= K; i++){
        for(int j = 0; j<= N; j++){
            for(int k = 0; k <= j; k++){
                dp1[i][j] = (dp1[i][j] + dp1[i-1][k]) % MOD;
            }
        }
    }

    // for(int i = 1; i <= N; i++){
    //     for(int j = 0; j <= N; j++){
    //         cout << dp1[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << dp1[K][N];

}
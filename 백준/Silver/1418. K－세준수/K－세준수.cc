#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define FAST std::ios::sync_with_stdio(0); std::cin.tie(0);
#define INF 2147483647
long long N, K;
long long nums[100];
int dp[100001] = {0,};

bool isPrime(int n){
   return dp[n] != 0;
}

bool isK(int n) {
    if(n == 1)
        return true;

    int prime = 1;
    for(int j = 1; j * j <= n; j++){
        
        if(n % j == 0){
            if(isPrime(j))
                prime = j;
            if(isPrime(n/j))
                prime = max(prime, n/j);
        }
        
    }
    // cout << n << "'s prime : " << prime << "\n";
    return prime <= K;
}

void setPrime(){
    /*
    1. 초기화  (0이 아닌 값으로)
    2. 특정 수의 배수에 해당하는 수는 지운다. (0으로)
    3. 인덱스가 곧 숫자이고 0이 아닌 값이라면, 소수인 것이다.
    */

   for(int i = 0; i <= N; i++){
        dp[i] = 1;
   }

   for(int i = 2; i <= N; i++){
        for(int j = i*2; j <= N; j+=i){
            if(dp[j] == 0)
                continue;
            dp[j] = 0;
        }
   }
}

int main(){
    FAST

    cin >> N>> K;
    long long count = 0;

    setPrime();
    for(int i = 1; i <= N; i++){
        if(isK(i)){
            // cout << "isK: " << i <<"\n";
            count++;
        }      
    }
    cout << count;
}
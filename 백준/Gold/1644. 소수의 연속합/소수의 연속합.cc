#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define FAST std::ios::sync_with_stdio(0); std::cin.tie(0);
#define INF 2147483647
long long N, K;
long long nums[100];
vector<int> primes;
int dp[4000001] = {0,};
int psum[4000001] = {0,};


void setPrime(){ 
    //N이하의 소수 구해두기
   for(int i = 2; i <= N; i++){
        dp[i] = 1;
   }

   for(int i = 2; i <= N; i++){
        for(int j = i*2; j <= N; j+=i){
            if(dp[j] == 0)
                continue;
            dp[j] = 0;
        }
   }

    int idx = 0;
    //소수들 누적합 계산하기, 소수만 따로 저장하기
   for(int i = 2; i <= N; i++){
        if(dp[i] != 0){
            primes.push_back(i);
            if(idx == 0)
                psum[idx] = i;
            else
                psum[idx] = psum[idx - 1] + i;
            idx++;
        }  
   }

}
//2 3 5 7 11 13 17 19
//
int getSum(int s, int e){
    // 누적합을 이용해서 부분합 구하기
    if(s == 0)
        return psum[e];
    return psum[e] - psum[s-1];
}

int countSumSameAsN(int n){
    int start = 0;
    int end = 0;
    int sum = 0;
    int count = 0;
    while(start < primes.size()){
        sum = getSum(start ,end);
        // cout << start << "s e" << end << "\n";
        // cout << "sum : " << sum  << "\n";
        if(sum >= n){
            start++;
        }
        else{
            end++;
        }
        if(sum == n){
            count++;
        }
        
    }

    return count;
}

int main(){
    FAST

    cin >> N;
    long long count = 0;
    setPrime();
    cout << countSumSameAsN(N);
    
}
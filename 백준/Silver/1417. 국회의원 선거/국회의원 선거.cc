#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define FAST std::ios::sync_with_stdio(0); std::cin.tie(0);
#define INF 2147483647
long long N, S;
long long nums[51];
vector<int> higher;
/*
5 10 7 3 8

6 9 7 3 8

7 8 7 3 8

8 7 7 3 8

9 7 7 3 7

후보와 같을 동안도 빼야하는 경우가 있고, 후보보다 작을 동안 빼야하는 경우도 있다.
- 다음 후보에서 빼면 어차피 높아질 것이라서 작다면 빼는 경우
- 더 높은 마지막 후보라서 안되는 경우

*/
int main(){
    cin >> N;
    priority_queue<long long> Q;
    for(int i = 0; i < N; i++){
        cin >> nums[i];
    }

    // sort(&nums[1], &nums[N], less<int>());
    for(int i = 1; i < N; i++){
            Q.push(nums[i]);
    }

    int dasom = nums[0];

    int count = 0;
    while(Q.empty() == false){
        long long curNum = Q.top();
        // cout << "num" << curNum << "\n";
        Q.pop();
        if(curNum >= dasom){
            dasom++;
            curNum--;
            count++;
        }
        if(curNum >= dasom){
            Q.push(curNum);
        }
    }
    
    cout << count;
}
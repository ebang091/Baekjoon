#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define FAST std::ios::sync_with_stdio(0); std::cin.tie(0);
#define INF 2147483647

int N, L, D;
int nums[10000] = {0,};

int young(int n) {
    if( n < 30)
        return 10;
    return (n / 30 + 1) * 10;
}

int min(int n){
    if (n < 60)
        return 15;
    return (n / 60 + 1) * 15;
}

int main() {
    
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> nums[i];
    
    int Y=0,M=0;
    for(int i = 0; i < N; i++){
        Y += young(nums[i]);
        M += min(nums[i]);
    }

    if(Y < M)
        cout << "Y " << Y;
    else if (M < Y)
        cout << "M " << M;
    else
        cout << "Y M " << Y;

//9 -14  (14-20) 20 - 25

    


}
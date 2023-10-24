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
#define all(v) v.begin(), v.end()
#define NONE -1
#define EMPTY ' '
#define INF 2147483647
using namespace std;
vector<string> inputs;
int scores[101];
int N, S, P;

/*

예제 1
3 90 10
100 90 80

100 90 90 80 -> 2등

예제 2
10 1 10
10 9 8 7 6 5 4 3 2 1

10 9 8 7 6 5 4 3 2 1 -> 꽉 찼는데 마지막보다 크지 않음. 
-> N == P 이고 마지막숫자보다 작거나 같을 때 -> -1


예제 3
10 1 10
10 9 8 7 6 5 4 3 3 0

10 9 8 7 6 5 4 3 3 1
-> N == P 이고 마지막 보다 커서 등수 == 10 계산.


1. 유효성 판별 
    N == P 이고 마지막숫자보다 작거나 같을 때 -> -1

2. 등수 계산
    N^2 으로, 자기보다 큰 숫자를 만났을 때 등수 up









*/

int countRank(int idx){
    int rank = 1;
    for(int j = idx-1; j >=0; j--){
        if(scores[j] > scores[idx])
            rank++;
    }
    return rank;
}


int main() {
    cin >> N >> S >> P;
/*
1. 유효성 판별 
    N == P 이고 마지막숫자보다 작거나 같을 때 -> -1

2. 등수 계산
    N^2 으로, 자기보다 큰 숫자를 만났을 때 등수 up
*/
    for(int i = 0; i < N ; i++){
        cin >> scores[i];
    }

    if(N == P && scores[N-1] >= S)
        cout << "-1";
    else{
        int idx = N;
        for(int i = 0; i < N; i++){
            if (scores[i] <= S){
                idx = i;
                break;
            }
        }
        cout << countRank(idx);
    }





    

    
   
}    
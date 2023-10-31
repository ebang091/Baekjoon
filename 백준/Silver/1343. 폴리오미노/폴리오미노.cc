#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
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
/*
폴리오미노 2개 무한개 : AAAA, BB
.와X로 이루어진 보드판에서 X를 폴리오노미노로 덮을 것임. 어떻게 덮었는지 출력하시오.
덮을 수 없으면 -1을 출력.

1. 연속된 X의 개수를 센다.
2. 연속된 X의 개수에 대해 그리디로 4개, 2개씩 만든다.
    홀수 개가 남아있다면 -1을 리턴한다.
*/
string board;
int countX(int idx){
    int count = 0;
    while (idx + count < board.length() && board[idx + count] == 'X') {
        // cout << "find " <<  board[idx + count] << "\n";
        count++;
    }
    return count;
}   

int main(){
    FAST
    const string A = "AAAA";
    const string B = "BB";
    cin >> board;
    
    int idx = 0;
    while(idx < board.length()){
        int count = countX(idx);
        if(count == 0){
            idx++;
            continue;
        }
        // cout << "count : " << count << "\n";
        while(count >= 4 && count > 0){
            board.replace(idx, A.length(), A);
            // cout << "4 : " << board <<"\n";
            idx += A.length();
            count -= 4;
        }
        while(count >= 2 && count > 0){
            board.replace(idx, B.length(), B);
            // cout << "2 : " << board <<"\n";
            idx += B.length();
            count -=2;
        }
        if(count > 0){
            cout << "-1";
            return 0;
        }
    }
    cout << board;

}
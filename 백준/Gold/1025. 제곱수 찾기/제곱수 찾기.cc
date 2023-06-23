#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <regex>
#include <cmath>
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
/*
 N X M 
 i행 ~ j행
 r열~ k열  => 이어붙인 정수가 완전 제곱수인지 확인하자. (어떤 수를 제곱한 수.)


*/

int N,M;
int board[10][10];
bool isPerfect(int n){
    //완전제곱수인지 확인
    int f = (int)sqrt(n);
    if(f * f == n)
        return true;
    return false;
}
int main(){
    char c;
    cin >> N >> M;
    int minvalue = min(N,M);
    int ans = -1;
    for(int i = 0; i  < N ; i++){
        for(int j = 0; j < M; j++)
            {
                cin >> c;
                board[i][j] = c - '0';
            }
    }
 
    string str;
    int n;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            for(int x = -N; x < N; x++){
                for(int y = -M; y < M; y++){
                    if(x == 0 && y == 0)continue;
                    int r = i, c = j;
                    n = 0;
                    while(0 <= r && r < N && 0 <= c && c < M){
                        n *= 10;
                        n += board[r][c];
                        r += x, c += y;
                        if(isPerfect(n)) ans = max(ans, n);
                    }
                }
            }
        }
    }
    cout << ans;
}
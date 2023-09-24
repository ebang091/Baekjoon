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
long long ans = 0;
#define SHARK 9
using namespace std;
int N, M;
long long board[30][30] = {0,};
long long visited[30][30] = {0,};
long long rainbowvisit[30][30] = {0,};
struct Shark{
    int eaten = 0;
    int size = 2;
    int y;
    int x;
};
Shark shark;
typedef pair<pair<int, int>, int > Data;
/*


*/

bool Cango(int r, int c){
    return 1 <= r && r <= N && 1 <= c && c <= N;
}

void update(Data &data, int r, int c, int cost){
    if(cost < data.second){
        data.first.first = r;
        data.first.second = c;
        data.second = cost;
    }
    else if(data.second == cost){
        if(r < data.first.first){
            data.first.first = r;
            data.first.second = c;
        }
        else if(r == data.first.first){
            if(c < data.first.second){
                data.first.second = c;
            }
        }
    }
   
}

Data find(){
    int dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    int visited[31][31] = {0,};

    Data ret;
    ret.first.first = INF, ret.first.second = INF, ret.second = INF;
    queue <pair<pair<int , int>, int> > Q;
    Q.push(make_pair(make_pair(shark.y, shark.x), 0));

    while (!Q.empty()){
        int curY = Q.front().first.first;
        int curX = Q.front().first.second;
        int cost = Q.front().second;
        Q.pop();

        // cout << "v " << curY << ", " << curX << "\n";
        for(int i = 0; i < 4; i++){
            int nextY = curY + dir[i][0];
            int nextX = curX + dir[i][1];
            if (Cango(nextY, nextX) && board[nextY][nextX] <= shark.size && visited[nextY][nextX] == 0 && board[nextY][nextX] != 9){
                visited[nextY][nextX] = 1;
                // cout << "next " << nextY << ", " << nextX << "\n";
                Q.push(make_pair(make_pair(nextY, nextX), cost + 1));
                if (board[nextY][nextX] < shark.size && board[nextY][nextX] != 0){
                    update(ret, nextY, nextX, cost + 1);
                }
            }
        }
    }
    
        return ret;

}

void solve(){
    //shark.first, shark.second 
    Data position;
    while(true){
        position = find(); //이동할 위치를 전달받음.
        if (position.first.first == INF)
            break;
        // cout << position.first.first << ", " << position.first.second << ", " << position.second << "\n";
        board[shark.y][shark.x] = 0;
        shark.y = position.first.first;
        shark.x = position.first.second;
        if(++shark.eaten == shark.size){
            shark.size++, shark.eaten = 0;
        }
        ans += position.second;
        board[position.first.first][position.first.second] = SHARK;
    }
    // cout << "info : " << shark.y << ", " << shark.x << position."\n";

    


}

int main() {
    //가장 가까운 먹을 수 있는 물고기를 찾자마자 먹는다.
    //찾는 순서 : 위, 왼쪽, 오른쪽, 아래
    //먹는 물고기의 수가 크기와 같다면 크기 + 1, 먹은 물고기의 수 0 초기화.

    cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> board[i][j];
            if(board[i][j] == 9){
                shark.y = i;
                shark.x = j;
            }
        }
    }

    solve();
    cout << ans << "\n";
}
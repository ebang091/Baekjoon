#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <utility>
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);
#define INF 2147483647

/*
1. 반드시 3개의 벽을 세워야 함.
2. 바이러스가 퍼질 수 없는 곳 = 안전영역 - 크기가 가장 크도록.

0 빈칸 1 벽 2 바이러스
3. 안전 영역의 크기를 잴 수 있는 방법 :
    바이러스 위치에서 BFSF를 돌리고 전체 맵에서 0의 개수를 센다 .
    -> N^2 시간 복잡도. (완전탐색)
4. 벽을 세우는 방법
    백트레킹을 이용해서 벽을 세울 곳을 모두 탐색해본다. 
    -> 3번과 함께 하려면 시간 복잡도가 너무 크게 나올 수 있다.
    -> 근데 N, M의 크기가 상당히 작으므로 해볼만하다. 

*/
using namespace std;
int N, M;
int board[10][10];
int copyBoard[10][10];
int visited[10][10] = {0,};
int selected[100] = {0,};

vector <pair<int, int> > emptyCell;
vector <pair<int , int> > newWall;
vector <pair<int , int> > virus;

int ans = 0;


bool Cango(int r, int c){
    
    return 1 <= r && r <= N &&  1 <= c && c <= M;

}

void BFS(){
    
    //r, c 바이러스 위치에서 시작.


    queue <pair<int, int> > Q;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            visited[i][j] = 0;
        }
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(copyBoard[i][j] == 2){
                Q.push(make_pair(i, j));
            }
        }
    }

    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    while (!Q.empty()){
        int curY = Q.front().first;
        int curX = Q.front().second;
        Q.pop();
        if(visited[curY][curX] == 1)
            continue;
        visited[curY][curX]= 1;
        // cout << "visit " <<  curY << " " << curX << "\n";
        for(int i = 0; i < 4; i++){
            int nextY = curY + dir[i][0];
            int nextX = curX + dir[i][1];
            
            if (Cango(nextY, nextX) && visited[nextY][nextX] == 0){
                if(copyBoard[nextY][nextX] == 0){
                    copyBoard[nextY][nextX] = 2;
                    Q.push(make_pair(nextY, nextX));
                }
            }
        }
    }

}

void make_comb(int s, int d, int idx){
    if(s == d){
      
    //맵 복사
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            copyBoard[i][j] = board[i][j];
        }
    }
    
    //벽세우기
    for(int i = 0; i < newWall.size(); i++){
        // cout << newWall[i].second << " " << newWall[i].first << "\n";
        copyBoard[newWall[i].first][newWall[i].second] = 1;
    }

    //바이러스 퍼지게 하기.
    BFS();

    int count = 0;

    for(int i = 0; i < emptyCell.size(); i++){    
        // cout << "look for "  << emptyCell[i].second << " " << emptyCell[i].first << "\n";

        if(copyBoard[emptyCell[i].first][emptyCell[i].second] == 0)
        {
            count++;    
        }
    }

    if(count > ans)
    {
        // cout << "Find! " << count << " \n";
        ans = count;
    }



        return;
    }
    

    for(int i  = idx + 1; i < emptyCell.size(); i++){
        int y = emptyCell[i].first;
        int x = emptyCell[i].second;
        
        if(selected[i] == 0){
            selected[i] = 1;
            newWall.push_back(make_pair(y,x));
            make_comb(s + 1, d, i);
            newWall.pop_back();
            selected[i] = 0;
        }
    }
}

int main(){
    FAST
    int n;
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> n;
            board[i][j] = n;
            if(n == 0) {
                emptyCell.push_back(make_pair(i,j)); 
            }
            else if(n== 2) 
                virus.push_back(make_pair(i, j));
        }
    }
    // cout << "empty cells : " << emptyCell.size( ) << "\n";
    // for(int i = 0; i < emptyCell.size(); i++){
    //     cout << emptyCell[i].first << " " << emptyCell[i].second <<"\n";
    // }

    make_comb(0, 3, -1);
    cout << ans;

}

#include <iostream>
#include <queue>
#include <vector>
#include <set>
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);
#define INF 2147483647
/*
매번 BFS로 큐에 넣을 때마다, x + 1, x -1 을 
넣을 때마다 2배한 값도 검사 후 같이 넣어준다. 

*/
using namespace std;
int board[1000001];
int visited[1000001] = {0,};
int N, K, ans = INF;

bool Cango(int i){
    return 0 <= i && i <= 100000;
}  

void BFS(int s){
    queue <pair< int, int> > Q;
    Q.push(make_pair(s, 0));
    int dir[2] = {-1, 1};
    while(!Q.empty()){
        int cur = Q.front().first;
        int cost = Q.front().second;
        // cout << "visit " <<  cur << "cost " << cost << "\n";
        if(cur == K){
            if(cost < ans){
                ans = cost;
                break;
            } 
        }
        Q.pop();
        if(visited[cur] == true)
            continue;
        visited[cur] = true;
        if(Cango(cur*2) && visited[cur*2] == 0){
                Q.push(make_pair(cur*2, cost));
        }
        for(int i = 0; i < 2; i++){
            int next = cur + dir[i];
            // int nextnext = next * 2;
            if(Cango(next) && visited[next] == 0){
                Q.push(make_pair(next, cost + 1));
            }
        }
        //현재 노드에서 비용변경 없이 2배 된 노드도 검사
    }
}

int main(){
    cin >> N >> K;
    BFS(N);
    cout << ans;
 
}
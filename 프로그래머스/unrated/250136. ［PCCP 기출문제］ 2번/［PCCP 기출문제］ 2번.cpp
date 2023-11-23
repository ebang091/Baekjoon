#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <queue>


using namespace std;
int N, M;
int numberOfVillage[501][510] = {0,};
int villageCount[125010] = {0,}; //마을 번호에 대한 개수
int curVillage = 1;
long long answer = 1;

bool canGo(int r, int c){
    return 0 <= r && r < N && 0 <= c && c < M;
}

void bfs(int r, int c, int v, vector<vector<int>>& land) {
    int count = 1;
    queue<pair<int, int> > Q;
    Q.push(make_pair(r, c));
    numberOfVillage[r][c] = v;
   
    int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1, 0}};
    while (!Q.empty()) {
        int curR = Q.front().first;
        int curC = Q.front().second;
        Q.pop();
        for(int i = 0; i < 4; i++) {
            int nextR = curR + dir[i][0];
            int nextC = curC + dir[i][1];
            if (canGo(nextR, nextC) == false)
                continue;
            if (numberOfVillage[nextR][nextC] == 0 && land[nextR][nextC] == 1) {
                numberOfVillage[nextR][nextC] = v;
                count++;
                Q.push(make_pair(nextR, nextC));
            }
        }
    }
    villageCount[v] = count;
    // return count;
    
 
}

long long max(long long a, long long b){
    return a > b ? a : b;
}

long long solution(vector<vector<int>> land) {
    N = land.size();
    M = land[0].size();

    curVillage = 1;
    for (int j = 0; j < M; j++) {
        long long count = 0;
        // set<int> checkVisited;
        bool checkVisited[125010] = {0,};
        // long long c = 1 << ()
        
        // cout << "j : " << j << "\n";
        for (int i = 0; i < N; i++) {
            int village = numberOfVillage[i][j];
            if (village == 0 && land[i][j] == 1) {
                bfs(i, j, curVillage, land); 
                count += villageCount[curVillage]; 
                checkVisited[curVillage++] = true;
                // checkVisited.insert(curVillage++);
            }
            else if(village != 0 && land[i][j] == 1){
                // if(checkVisited.find(village) == checkVisited.end()){
                if(checkVisited[village] == false) {
                    count += villageCount[village];
                    checkVisited[village] = true;
                    // checkVisited.insert(village);
                }
            }
            // cout << "i " << i << "count " << count << "\n";
        }
        answer = max(answer, count);
    }
    
    return answer;
}
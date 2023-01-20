#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

int N,M;
int S,D;
int nmax;

using namespace std;
int map[101][101];
int flood[101][101];
int visited[101][101];
queue <pair<int, int> > Q;
int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
int visit=1, visitmax=0;

bool Cango(int y, int x)
{
    if(1 <= y && y <= N && 1 <= x && x <= N)
        return true;
    return false;
}

void init()
{
    for(int i=1;i<=N;i++) {
        for (int j = 1; j <= N; j++) {
            flood[i][j] = 0;
            visited[i][j] = 0;
        }
    }
}

void search_flood(int r)
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(map[i][j] <= r)
                flood[i][j] = 1;
        }
    }
}

void BFS(int y, int x)
{
    visited[y][x] = visit;
    if(visit > visitmax)
        visitmax = visit;
    Q.push(make_pair(y, x));

    while(!Q.empty())
    {
        int cury = Q.front().first;
        int curx = Q.front().second;
        Q.pop();
        for(int i = 0;i<4;i++) {
            int nexty = cury + dir[i][0];
            int nextx = curx + dir[i][1];
            if (Cango(nexty, nextx) && flood[nexty][nextx] == 0) {
                if (visited[nexty][nextx] == 0) {
                    visited[nexty][nextx] = visit;
                    Q.push(make_pair(nexty, nextx));
                }
            }
        }
    }
    visit++;
}

void solve()
{
    //비 : 1~nmax까지 내리는 경우마다 조사
    for(int i=0;i<=nmax;i++)
    {
        //flood 0 초기화
        //맵순회하면서 물에 잠기면 flood에 1박음
        //flood순회하면서 BFS : Visit 가 곧 안전영역의 수.
        init();
        search_flood(i);
        //cout << "rain : " << i<<"\n";
        visit = 1;
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++) {
                if(visited[i][j] == false && flood[i][j] == 0) {
                    //cout << "BFS : "  << i << " " << j <<"\n";
                    BFS(i,j);
                }
            }
        }
    }
}

void input() //맵 생성
{
    int n;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++) {
            cin >> n;
            if (n >= nmax)
                nmax = n;
            map[i][j] = n;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    input();
    solve();
    cout << visitmax;
}
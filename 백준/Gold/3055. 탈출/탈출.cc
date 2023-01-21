#include <iostream>
#include <queue>
#include <vector>
#include <queue>

#define MAX 51
using namespace std;
int N, M;
// N <= 50 M <= 50
// 매번 BFS :  2500 * 2500 = 625 * 10^4
char map[MAX][MAX];
int water[MAX][MAX];            //물의 이동.
int visited[MAX][MAX] = {0,}; //고슴도치의 이동.

vector <pair <int, int> > save(3); //D, S , *의 위치 저장.
queue <pair<pair<int, int >, int> > Q;
int dir[4][2] = {{0,1}, {0,-1}, {1, 0}, {-1,0}};

/*
 * . . . . .
 * S . . . .
 * . . . . D
 * * . . . .
 *
 *
 */

void input()
{
    string str;
    for(int i=1;i<=N;i++)
    {
        cin >> str;
        for(int j=1;j<=M;j++)
        {
           map[i][j] = str[j-1];
           if(map[i][j] == 'D') {
               save[0].first = i;
               save[0].second = j;
           }
           else if(map[i][j] == 'S') {
               save[1].first = i;
               save[1].second = j;
           }
        }
    }
}

bool Cango(int r, int c)
{
    if(1 <= r && r <= N && 1 <= c && c <= M && map[r][c] != 'X')
        return true;
    return false;
}

void BFS_water()
{
    while (!Q.empty())
    {
        int r = Q.front().first.first;
        int c = Q.front().first.second;
        int w = Q.front().second;
        Q.pop();

        for (int i=0;i<4;i++)
        {
            int nextr = r + dir[i][0];
            int nextc = c + dir[i][1];
            if (Cango(nextr, nextc) && map[nextr][nextc] != 'D')
            {
                if (water[nextr][nextc] ==0 || water[nextr][nextc] > w+1) {
                    water[nextr][nextc] = w + 1;
                    Q.push(make_pair(make_pair(nextr, nextc), w + 1));
                }
            }
        }
    }
}

void BFS_solve()
{
    while(!Q.empty())
    {
        int r = Q.front().first.first;
        int c = Q.front().first.second;
        int w = Q.front().second;
        Q.pop();
        for(int i=0;i<4;i++) {
            int nextr = r + dir[i][0];
            int nextc = c + dir[i][1];
            if (Cango(nextr, nextc) && visited[nextr][nextc] == 0 && ( w + 1 < water[nextr][nextc] || water[nextr][nextc] == 0)) {
                visited[nextr][nextc] = w + 1;
                Q.push(make_pair(make_pair(nextr, nextc), w + 1));
            }
        }
    }
}

void solve()
{
    //물에서 BFS시작
    //물 위치에서 물이 차오르는 것 구현: 매 분마다 맵에 물이 그려짐.
    //물이 그려질 때마다 고슴도치도 거기서 BFS

    //물과 고슴도치를 번갈아가면서 BFS를 수행하되 물을 먼저한다?
    //물이 차오르는 맵 -> 몇 시에 차는 지 미리 표시 해둔다.
    //고슴도치가 차오르는 맵 구현 : 물이 차오르는 맵보다 이른 시각이라면 전진한다.
    //물 BFS
    int r,c;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            if(map[i][j] == '*')
            {
                water[i][j] = 1;
                Q.push(make_pair(make_pair(i,j), 1));
                BFS_water();
            }
        }
    }
//    cout << "BFS water done\n";
//    for(int i=1;i<=N;i++)
//    {
//        for(int j=1;j<=M;j++)
//        {
//            cout << water[i][j] << " " ;
//        }
//        cout << "\n";
//    }

    r = save[1].first;
    c = save[1].second;
   // cout << "S : " << r << " " << c << "\n";
    visited[r][c] = 1;
    Q.push(make_pair(make_pair(r,c),1));
    BFS_solve();

//    cout << "BFS solve` done\n";
//    for(int i=1;i<=N;i++)
//    {
//        for(int j=1;j<=M;j++)
//        {
//            cout << visited[i][j] << " " ;
//        }
//        cout << "\n";
//    }
    r = save[0].first;
    c = save[0].second;
    if(visited[r][c])
        cout << visited[r][c] - 1;
    else
        cout << "KAKTUS";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    input();
    solve();
}
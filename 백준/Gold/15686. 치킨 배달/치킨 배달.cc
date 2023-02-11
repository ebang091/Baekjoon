#include <unistd.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 198765432
int N,M;
using namespace std;
vector <pair<int, int> > chicken;
vector <pair<int, int> > house;
int map[51][51];
int map_distance[51][51];
int between_chicken[100][14];
bool visited[51][51];
long long theanswer = 198765432;
queue <pair <int, int> > Q;


vector <int> comb;
int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
/*
5 2
0 2 0 1 0
1 0 1 0 0
0 0 0 0 0
0 0 0 1 1
0 0 0 1 2
 */

void input()
{
    int n;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++) {
            cin >> n;
            map[i][j] = n;
            if(n == 2)
                chicken.push_back(make_pair(i,j));
            else if(n == 1)
                house.push_back(make_pair(i, j));
        }
    }
}

int Cango(int y, int x)
{
    if (1<= y && y <= N && 1 <= x && x <= N)
        return 1;
    return 0;
}

void BFS()
{
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            visited[i][j] = false;

    while(!Q.empty())
    {
        int cury = Q.front().first;
        int curx = Q.front().second;
        Q.pop();
        if(visited[cury][curx] == true)
            continue;
        visited[cury][curx] = true;
        for(int i=0;i<4;i++)
        {
            int nexty = cury + dir[i][0];
            int nextx = curx + dir[i][1];
            if(Cango(nexty, nextx) && visited[nexty][nextx] == false)
            {
                Q.push(make_pair(nexty, nextx));
                map_distance[nexty][nextx] = map_distance[cury][curx] + 1;
            }
        }
    }
}

void fill_distance(int house)
{
    for(int j=0;j<chicken.size();j++)
    {
        int y = chicken[j].first;
        int x = chicken[j].second;
        between_chicken[house][j] = map_distance[y][x];
    }
}

void DFS(int start, int depth)
{
    if(depth == M)
    {
//        cout << "comb";
//        for(int i=0;i<comb.size();i++)
//            cout << comb[i] << " ";
//        cout << "\n";
        //정해놓은 치킨집 조합에 대해서 치킨 거리를 구한다.
        //궁극적으로 치킨거리의 최솟값을 구하는 것이 목표이다.
        long long ans = 0;
        for(int i=0;i<house.size();i++)
        {
            long long min = 19876543;
            for(int j=0;j<comb.size();j++)
            {
                if(between_chicken[i][comb[j]] < min)
                    min = between_chicken[i][comb[j]];

            }
//            cout << "min : " << min <<"\n";
            ans += min;
        }
        if(ans < theanswer)
            theanswer = ans;


        return;
    }

    for(int i = start;i<chicken.size();i++)
    {
        comb.push_back(i);
        DFS(i+1, depth + 1);
        comb.pop_back();
    }


}

void check_distance()
{
    cout << "check distance\n\n";
    for(int i=0;i<house.size();i++)
    {
        for(int j=0;j<chicken.size();j++)
        {
            cout << between_chicken[i][j] << " " ;
        }
        cout << "\n";
    }
}
void solve()
{
    for(int i=0;i<house.size();i++)
    {
        //집 하나에 대해서 distance 배열을 모두 갱신하고, 이를 치킨집과의 거리에 담는다. (2N * (4))
        int y = house[i].first;
        int x = house[i].second;
        map_distance[y][x] = 0;
        Q.push(make_pair(y,x));
        BFS();
        fill_distance(i);
    }
//    check_distance();

    DFS(0,0);
}

int main() {
    cin >> N >> M;
    //N<=50 이므로 플로이드 워셜 알고리즘을 통해 각 노드마다 다른 노드까지의 거리를 미리 구해둔다.

    input();
    solve();
    cout << theanswer;

}
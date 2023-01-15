#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 2000000

int N,M;
vector <vector<int> > g(1001);
int visit = 1;
int visited[1001] = {0,};
priority_queue<int> PQ;

void input()
{
    int u, v; // N<=1000
    for(int i=0;i<M;i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void BFS(int i)//i 번째 노드 방문후 BFS 순회!
{
    if(visited[i])
        return; //큐에 저장되어있는데 pop되기 전에 방문될 수 있다.
    visited[i] = visit;
    PQ.push(i);

    while (PQ.size()) {
        int next = PQ.top();
        PQ.pop();
        int j = -1;
        while (++j < g[next].size())//adjecent nodes
        {
            if (visited[g[next][j]] == false) {
                PQ.push(g[next][j]);
                visited[g[next][j]] = visit;
            }
        }
    }
    visit++;
    return ;

}

void find_group()
{
    //단지 순회를 하듯이 방문하지 않은 노드들만을 방문하되, 시작점에서 인접노드까지만 이동하도록 한다. (BFS)
    //그래프 내에서 순회를 하면서 BFS를 한 횟수가 곧 연결요소의 개수일 것이다.
    for(int i=1;i<=N;i++)
    {
        if(visited[i] == 0)
            BFS(i);

    }
}

int main()
{
    cin >> N >> M;
    input();
    find_group();
    if(visit == 0)
       cout << visit;
    else
        cout << visit-1;
}
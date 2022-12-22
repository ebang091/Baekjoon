//
// Created by Eun jung Bang on 2022/12/22.
//

#include <vector>
#include <iostream>
#include <queue>
#include <utility>
#define INF 198767654
using namespace std;

int N,M,S;
vector<pair<int, int > > graph[20001];
int d[20001];

void init()
{
    for(int i =1;i<=N;i++)
        d[i] = INF;
}

void dijkstra()
{
    init(); //거리를 일단 최대로 지정
    priority_queue <pair<int, int> >pq;//node, distance
    pair<int, int>a;
    a = make_pair(0, S);
    pq.push(a);
    d[S] = 0;
    while(!pq.empty())
    {
        int dist = -1*pq.top().first;//가장 가까운 노드를 꺼냄. -> 연결된 노드들을 다 넣음.
        int cur = pq.top().second;
        //printf("cur , dist  = %d %d\n", cur, dist);
        //printf("size: %d\n", pq.size());
        pq.pop();
        if(d[cur] < dist)// 꺼냈던 가장 가까운 노드가 이미 최소경로보다 더 큰 경우라면 패스해버린다.
            continue;
        //printf("%d node size: %d\n", cur, graph[cur].size());
        for(int i=0;i<graph[cur].size();i++)
        {
            int ndist = graph[cur][i].first + dist;
            int ncur = graph[cur][i].second;
            //printf("%d: %d vs %d\n", ncur, d[ncur],ndist );
            if(d[ncur] > ndist)
            {
                //printf("%d win\n", ndist);
                pq.push(make_pair(-ndist, ncur));
                d[ncur] = ndist;
            }
        }

    }


}

void print_dis()
{
    for(int i =1;i<=N;i++)
    {
        //printf("%d: ",i);
        if(d[i] == INF)
            printf("INF\n");
        else
            printf("%d\n",d[i]);
    }

}

int main()
{
    int u,v,w;
    scanf("%d %d", &N, &M);
    scanf("%d", &S);

    for(int i =0;i<M;i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back(make_pair(w,v));
    }
    dijkstra();
    print_dis();
}
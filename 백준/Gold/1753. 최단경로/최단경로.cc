#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>

int V,E,K;
using namespace std;
#define MAX 300001
#define INF 1987654321

vector <vector<pair<int, int>> > g(MAX); //인덱스: 정점, <맞은편 정점, 가중치>
long long dist[MAX];


void input()
{
	int u, v, w;
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		g[u].push_back({ w, v });
	}
}



void dijkstra()
{
	priority_queue <pair<int, int>> PQ;
	//거리 배열 초기화
	for (int i = 1; i <= V; i++)
	{
		dist[i] = INF;
	}
	//시작 점
	PQ.push(make_pair(0, K));
	dist[K] = 0;
	while (!PQ.empty())
	{
		long long nowcost = -PQ.top().first;
		long long now = PQ.top().second;
		PQ.pop();
		for (int i = 0; i < g[now].size(); i++)
		{
			long long nextcost = nowcost + g[now][i].first;
			int next = g[now][i].second;
			if (nextcost < dist[next])
			{
				dist[next] = nextcost;
				PQ.push({ -nextcost  ,next});
			}
		}
	}
}


void print_distance()
{
	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == INF)
			cout << "INF\n";
		else
			cout << dist[i] << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> V >> E;
	cin >> K;
	input();
	dijkstra();
	print_distance();
	
}



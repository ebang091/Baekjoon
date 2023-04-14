#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>

#define MAX 1000001 
using namespace std;

int parent[1000001];
int N, M;
struct Edge {
	int start;
	int end;
	int cost;
};

vector <Edge> Edgelist;
/*크루스칼 알고리즘으로 풀이 : 유니온 파인드 사용!*/
void init()
{
	for (int i = 0; i <= N; i++)
		parent[i] = i;
}


int find(int a)
{
	if (parent[a] == a)
		return a;
	int result = find(parent[a]);//root를 반환받는다.
	parent[a] = result;
	return result;
}

bool ft_union(int a, int b)
{
	int roota = find(a);
	int rootb = find(b);
	if (roota == rootb)
		return false; //이미 같은 집합이라서 추가 하지 않았다는 정보 반환
	parent[rootb] = roota;
	return true; //같은 집합에 추가하였다는 사실 반환.
}


bool isUnion(int a, int b)
{
	return find(a) == find(b);
}

/*union find 의 내용 */
void input()
{
	int u,v,w;
	for (int i = 0; i < M; i++)
	{
		//간선 정보를 입력받는다. 
		cin >> u >> v >> w;
		Edgelist.push_back({ u,v,w });
	}
}

bool cmp(Edge a, Edge b)
{
	return a.cost < b.cost;
}

long long Kruskal()
{
	int edgeCount = 0;
	long long costCount = 0;
	//1. 간선을 가중치 최소 순서로 sort.

	//2. 가중치가 가장 작은 간선을 트리에 포함시키되 이미 트리에 포함되어있는지 확인하면서 수행.
	//3. 이른 종료 조건: 만든 간선의 개수가 전체 정점의 수 -1 일때. (사이클이 없는 트리 그래프의 특징)


	//1번 수행
	sort(Edgelist.begin(), Edgelist.end(), cmp);
	//2번 수행
	for (int i = 0; i < M; i++)
	{
		if (ft_union(Edgelist[i].start, Edgelist[i].end) == true)//유니온 되었다면 == 트리에 포함되어있지 않았다면
		{
			edgeCount++;
			costCount += Edgelist[i].cost;
		}
		if (edgeCount == N - 1)
			return costCount;
	}
	return costCount;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	init();
	input();
	cout << Kruskal();


	


}



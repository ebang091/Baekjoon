#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> graph(100001);
int visited[100001] = {0,};
int queue[200001];
int head = 0, rear = 0;


void	BFS()
{
	int next;
	int i;

	while (head < rear)
	{
		next = queue[head];
		head++;
		visited[next] = 1;

		i = 0;
		while (i < graph[next].size())
		{
			if (visited[graph[next][i]] != 1)
			{
				queue[rear] = graph[next][i];
				rear++;
			}
			i++;
		}
	}

}

// graph[i].size() == strlen(graph[i])느낌
// graph[i][j]로 접근하면 됨

/*
7
6
1 2
2 3
1 5
5 2
5 6
4 7

1 - 2 5
2 - 1 3 5
3 - 2
4 - 7
5 - 1 2 5 6 
6 - 5
7 - 4

		1 ㅡ 5 - 6
		|  /
3	-	2         4 -7






*/

int main() {
	int N, M;//전체 컴퓨터 수, 연결된 컴퓨터 수
	int u, v;
	int count = 0;

//컴퓨터 수 최대 100대 : 노드의 수.  재귀를 짜는 데 문제 없을 것: O(n^2)

//
	scanf("%d %d", &N, &M);
	
	for(int i=0;i<M;i++) {
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	//순서가 필요 없이 수만 셀 것이므로 굳이 필요 없지만 이해의 용이성을 위해 정렬
	for(int i=1;i<=N;i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	for(int i = 1; i <= N; i ++)	
		visited[i] = 0;

	queue[rear] = 1;
	rear++;
	BFS();
	for (int i = 2; i <= N; i++)
	{
		if(visited[i] == 1)
			count++;
	}
	printf("%d", count);

	return 0;
}
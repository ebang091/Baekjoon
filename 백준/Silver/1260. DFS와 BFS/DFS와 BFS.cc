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
	//어떻게 하면 queue에 이미 방문예정인 노드를 중복하여 넣지 않을까?
	//큐에 넣기 전 단순 visited를 검사하는 것으로는 체크가 안된다.
	//큐에 넣는 순간 방문한 거나 마찬가지로 취급해서 visited라고 해준다. 
	//다만 초기 정점은 main에서 visited라고 표시해준다. (방문 전에 큐에 들어간 건 다 visited)
	int next;
	int i;

	while (head < rear)
	{
		next = queue[head++];
		printf("%d ", next);

		i = 0;
		while (i < graph[next].size())
		{
			if (visited[graph[next][i]] != 1)
			{
				queue[rear++] = graph[next][i];
				visited[graph[next][i]] = 1;
			}
			i++;
		}
	}

}
/*
4 5 1

1 2
1 3
1 4
2 4
3 4
       3
      / |
  	/   |
   4 ㅡ 1
	 \	|
	  \ 2

*/
void DFS(int R)
{
	//1. 정점 방문
	//2. 방문 안했다면, 인접 노드 방문(재귀적)
	int i = 0;
	visited[R] = 1;
	printf("%d ", R);
	
	while (i < graph[R].size())
	{
		if (visited[graph[R][i]] == 0)
			DFS(graph[R][i]);
		i++;
	}
}

int main() {
	int N, M, R;//전체 컴퓨터 수, 연결된 컴퓨터 수
	int u, v;
	int count = 0;

//컴퓨터 수 최대 100대 : 노드의 수.  재귀를 짜는 데 문제 없을 것: O(n^2)

//
	scanf("%d %d %d", &N, &M, &R);
	
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

	//DFS
	DFS(R);

	//초기화
	for(int i = 1; i <= N; i ++)	
		visited[i] = 0;
    printf("\n");
	//BFS
	queue[rear] = R;
	rear++;
	visited[R]= 1;
	BFS();
	

	return 0;
}
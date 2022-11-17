#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;
vector<vector<int>> graph(100001);
int visited[100001] = {0,};
int idx = 0;

// graph[i].size() == strlen(graph[i])느낌
// graph[i][j]로 접근하면 됨

void dfs(int r, int *arr) {

	//노드 출력
	//이웃한 간선들을 차례로
		//방문이 안되어있으면 dfs 수행.

	visited[r] = 1;
	arr[r] = ++idx;
	//printf("%d\n", r);//방문 완료.

	int j = 0;
	
	while (j < graph[r].size())
	{
	//남은 간선이 있으면 
	//printf("%d", graph[r][j]);
		if(visited[graph[r][j]] == 0)
			dfs(graph[r][j], arr);
		j++;
	}




}

int main() {
	int N, M, R;
	int u, v;

	scanf("%d %d %d", &N, &M, &R);
	
	for(int i=0;i<M;i++) {
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for(int i=1;i<=N;i++) {
		sort(graph[i].begin(), graph[i].end());
	}	

	int *arr = (int *)malloc(sizeof(int)*(N+1));
	for(int i = 0; i <= N ; i++)
		arr[i] = 0;

	dfs(R, arr);
	for(int i = 1; i <= N ; i++)
		printf("%d\n", arr[i]);

	return 0;
}
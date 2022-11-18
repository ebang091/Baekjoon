#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> graph(100001);
int visited[100001] = {0,};
int willvisit[100001] = {0,};
int queue[200001];
int head = 0, rear = 0;

// graph[i].size() == strlen(graph[i])느낌
// graph[i][j]로 접근하면 됨

void bfs(int N) {
	static int arr[100001];
	int j , r, cnt = 0, k = 0, flag;

	while (head < rear)
	{	
		//printf("head: %d rear: %d\n", head, rear);
		//방문 노드 찾기:
		r = queue[head];
		head++;
		arr[r] = ++cnt;//방문 순서 저장.
		//printf("방문 %d cnt %d\n", r, cnt);
		
		//printf("cnt:  %d\n", cnt);
		j = 0;	
		//방문한 노드와 연결된 노드들을 queue에 담음
		while (j < graph[r].size())				
		{
			if (visited[graph[r][j]] != 1) //아직 안간 노드인지 확인
			{
				if(willvisit[graph[r][j]]!= 1) //큐에 저장되어있는 노드인지 확인
				{
					queue[rear] = graph[r][j];
					rear++;
					willvisit[graph[r][j]] = 1;//방문할 노드인지 기록.
				}
			}
			j++;
		}
	}

	for (int i =1; i <= N ; i++)
		printf("%d\n", arr[i]);

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
	for(int i = 1; i <= N; i ++)	
		visited[i] = 0;
	//첫번째 노드 대입하면서 시작. 	
	queue[rear] = R;
	rear++;
	willvisit[R]  = 1;
	bfs(N);
	return 0;
}
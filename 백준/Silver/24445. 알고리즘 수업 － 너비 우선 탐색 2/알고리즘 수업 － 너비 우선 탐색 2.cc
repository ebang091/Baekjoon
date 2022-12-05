#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> graph(1000001);
int queue[200001];
int visited[100001];
int rear = 0;
int head = 0;
int visit  =1;


void BFS()
{

    int next;
    int j = 0;
    while(head < rear) {
        next = queue[head++];
        j = 0;
        while (j < graph[next].size()) {
            if (visited[graph[next][j]] == 0) {
                visited[graph[next][j]] = visit++;
                queue[rear++] = graph[next][j];
            }

            j++;
        }
    }
}

int main()
{
    int N,M,R;
    int u,v;

    scanf("%d %d %d", &N, &M, &R);
    for(int i = 0 ; i < M; i++)
    {
        scanf("%d %d ", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 1; i <= N; i++)
        sort(graph[i].begin(), graph[i].end(), greater<>());

    for(int i = 1; i<= N; i++)
        visited[i] = 0;

    visited[R] = visit++;
    queue[rear++] = R;
    BFS();
    for(int i = 1; i<= N; i++)
        printf("%d\n", visited[i]);
}
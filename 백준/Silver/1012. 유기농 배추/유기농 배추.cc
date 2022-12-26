#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>

int map[51][51];
int visited[51][51];
int visit=1;
int T;
int N,M,K;
#define TRUE 1
#define FALSE 0
using namespace  std;
queue <pair<int,int> >Q;
void BFS()
{
    while(!Q.empty())
    {
        int r = Q.front().first;
        int c = Q.front().second;
        Q.pop();
        if(visited[r][c] != FALSE)
            continue;
        visited[r][c] = TRUE;
        if(r+1 < N && map[r+1][c] != 0)
            Q.push(make_pair(r+1,c));
        if(c+1 < M && map[r][c+1] != 0)
            Q.push(make_pair(r,c+1));
        if(r-1 >=0 && map[r-1][c] != 0)
            Q.push(make_pair(r-1,c));
        if(c-1 >= 0 && map[r][c-1] != 0)
            Q.push(make_pair(r,c-1));
    }
}
void init()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            map[i][j] = 0;
            visited[i][j] = 0;
        }
    }
    visit = 1;
}
int main()
{
    int r,c;
    scanf("%d", &T);
    for(int p=0;p<T;p++) {
        scanf("%d %d %d", &M, &N, &K);
        init();
        for (int i = 0; i < K; i++) {
            scanf("%d %d", &c, &r);
            map[r][c] = 1;
        }
//        for(int i=0;i<N;i++)
//        {
//            for(int j=0;j<M;j++)
//                printf("%d ", map[i][j]);
//            printf("\n");
//        }
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (visited[i][j] == FALSE && map[i][j] ==1) {
                        //printf("BFS %d %d\n", i,j);
                        Q.push(make_pair(i, j));
                        BFS();
                        visit++;
                    }
                }
            }
        printf("%d\n", visit - 1);
    }
}
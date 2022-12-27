#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#define TRUE 1
#define FALSE 0
#define INF 1987654
using namespace  std;
int N,M,max_=-1, answer=-1;
int map[1001][1001];
int dis[1001][1001] = {0,};
int visited[1001][1001];
int dir[4][2] = {{-1,0}, {0,1}, {1,0} ,{0,-1}};
queue <pair<int, int> > Q;

int Cango(int r, int c)
{
    if(r >=1 && r <= N && c >= 1 && c <= M)
        return 1;
    return 0;
}

void BFS()
{
    while(!Q.empty())
    {
        int r = Q.front().first;
        int c = Q.front().second;
        Q.pop();
        if(visited[r][c] == TRUE)
            continue;
        visited[r][c] = TRUE;
        for(int i=0;i<4;i++)
        {
            int next_r = r + dir[i][0];
            int next_c = c + dir[i][1];
            if(Cango(next_r, next_c) && map[next_r][next_c] == 0)
            {
                if(dis[next_r][next_c] > dis[r][c] + 1) {
                    dis[next_r][next_c] = dis[r][c] + 1;
                    //printf("%d %d - dis %d\n", next_r, next_c, dis[next_r][next_c]);
                }
                Q.push(make_pair(next_r,next_c));
            }
        }
    }
}

void restart()
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            visited[i][j] = FALSE;
        }
    }
}

void find()
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            if(map[i][j] == 1) {
                //printf("%d %d BFS\n", i,j);
                dis[i][j] = 0;
                Q.push(make_pair(i,j));
            }
        }
    }
        BFS();
}

void init()
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            map[i][j] =1;
            visited[i][j] = 0;
            dis[i][j]= INF;
        }
    }
}
int main()
{
    scanf("%d %d", &M, &N);
    init();
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            scanf("%d", &map[i][j]);
            if(map[i][j] == -1)
                dis[i][j] = -1;
        }
    }
    find();
    //printf("distance\n");
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            //printf("%d ", dis[i][j]);
            if(dis[i][j] > answer)
                answer = dis[i][j];
        }
     //   printf("\n");
    }
    if(answer >= INF)
    {
        printf("-1\n");
        return 0;
    }
    printf("%d\n",answer);
}
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>

int map[101][101];
int visited[101][101];
int dis[101][101] = {0,};
int visit= 1;
int N,M;
#define TRUE 1
#define FALSE 0
using namespace  std;
queue <pair<int,int> >Q;

void BFS()
{
    while(!Q.empty()) {
        int r = Q.front().first;
        int c = Q.front().second;
        Q.pop();
        if (visited[r][c] != FALSE)
            continue;
        visited[r][c] = TRUE;

        if (r + 1 <= N && map[r + 1][c] != 0 && visited[r+1][c] == FALSE) {
            Q.push(make_pair(r + 1, c));
            dis[r+1][c] = dis[r][c] + 1;
        }
        if (c + 1 <= M && map[r][c + 1] != 0 && visited[r][c + 1] == FALSE) {
        Q.push(make_pair(r, c + 1));
            dis[r][c+1] = dis[r][c] + 1;
    }
        if(r-1 >0 && map[r-1][c] != 0 && visited[r - 1][c] == FALSE) {
            Q.push(make_pair(r - 1, c));
            dis[r-1][c] = dis[r][c] + 1;
        }
        if(c-1 > 0 && map[r][c-1] != 0 && visited[r][c - 1] == FALSE) {
            Q.push(make_pair(r, c - 1));
            dis[r][c-1] = dis[r][c] + 1;
        }
    }
}
void init()
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            map[i][j] = 0;
            visited[i][j] = 0;
        }
    }
}
void input()
{
    char str[101];
    for(int i=1;i<=N;i++)
    {
        scanf("%s",str);
        for(int j=1;j<=M;j++)
        {
            map[i][j] = *(str+j-1) - '0';
        }
    }
}

void find()
{
    Q.push(make_pair(1,1));
    BFS();
    dis[1][1] = 1;
}
int main() {


    scanf("%d %d", &N, &M);
    init();
    input();
    find();

//    printf("거리 확인용 \n");
//    for(int i=1;i<=N;i++)
//    {
//        for(int j=1;j<=M;j++)
//            printf("%d ", dis[i][j]);
//        printf("\n");
//    }
    printf("%d", dis[N][M] +1);

}
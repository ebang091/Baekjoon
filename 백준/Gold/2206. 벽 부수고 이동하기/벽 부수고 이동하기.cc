#include <iostream>
#include <queue>
#include <utility>
#define TRUE 1
#define FALSE 0
#define INF 1987654

using namespace std;
int N,M;
int map[1001][1001];
int dist[1001][1001][2];
int visited[1001][1001][2] = {0,};
int dir[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
queue < pair<int , pair<pair<int,int>,int> > > Q;

int Cango(int r, int c )
{
    if(1<=r&&r<=N &&1<=c&&c<=M)
        return 1;
    return 0;
}
void input()
{
    char str[1001];
    char *ptr;
    for(int i=1;i<=N;i++)
    {
        scanf("%s", str);
        ptr = str;
        for(int j=1;j<=M;j++)
        {
            map[i][j] = *(ptr ++) - '0';
//            printf("%d ",map[i][j]);
        }
//        printf("\n");
    }
}

int  BFS()
{

    while(!Q.empty()) {
        int dis = Q.front().first;
        int r = Q.front().second.first.first;
        int c = Q.front().second.first.second;
        int crash = Q.front().second.second;

        Q.pop();
        if (visited[r][c][crash] == TRUE)
            continue;
        visited[r][c][crash] = TRUE;
        if(r==N && c ==M)
            return dis;
//        printf("node (%d,%d) dis %d in BFS %d\n", r,c, dis,crash );
        for (int i = 0; i < 4; i++) {
            int next_r = r + dir[i][0];
            int next_c = c + dir[i][1];
            if (Cango(next_r, next_c)) {
//                printf("next: (%d,%d) - ", next_r, next_c );
                if (map[next_r][next_c] == 1) //벽을 만났다면, 부술 수 있어야 갱신을 한다.
                {
                    if (crash == 0 && visited[next_r][next_c][0] == FALSE) {
//                        printf("%d in [1] push\n", dis+1);
                        dist[next_r][next_c][1] = dis + 1;
                        Q.push(make_pair(dis + 1, make_pair(make_pair(next_r, next_c), 1)));
                    }
                }
                else if (crash == 0 && visited[next_r][next_c][0] == FALSE) //벽이 아니다. 그리고 아직 한번도 안부쉈다 -> 0세계에 기록.
                {
//                    printf("%d in [0] push \n", dis+1);
                    dist[next_r][next_c][0] = dis + 1;
                    Q.push(make_pair(dis + 1, make_pair(make_pair(next_r, next_c), 0)));
                }
                else if (crash == 1 &&
                           visited[next_r][next_c][1] == FALSE)//벽이 아니다. 그리고 한번 부순 적이 있다. -> 갈 ㅜㅅ 있고, 1세계에 기록.
                {
//                    printf("%d in [1] push \n", dis+1);
                    dist[next_r][next_c][1] = dis + 1;
                    Q.push(make_pair(dis + 1, make_pair(make_pair(next_r, next_c), 1)));
                }
            }
        }
    }
    return -1;
}

int find()
{
    dist[1][1][0] = 1;
    Q.push(make_pair(1, make_pair(make_pair(1,1),0)));
    return BFS();

}

void print_dist()
{
    printf("\n\t distance \n");
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            printf("%d ", dist[i][j][0]);
        }
    printf("\n");
    }

    printf("\n\t distance crash  \n");
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            printf("%d ", dist[i][j][1]);
        }
        printf("\n");
    }

}

int main()
{
    scanf("%d %d", &N, &M);
    input();
    printf("%d", find());
//    print_dist();



}
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

#define TRUE 1
#define FALSE 0

using namespace std;

queue<pair <pair<int, int>, int> > Q;
int map[26][26];
int visited[26][26];
int visit=1;
int village[6300], idx = 0;

int N;

void init()
{
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++)
            visited[i][j] = 0;
    }
    for(int i=0;i<6300;i++)
        village[i] = 0;
}

void BFS()
{
    int cnt = 0;
    while(!Q.empty())
    {
        int r = Q.front().first.first;
        int c = Q.front().first.second;
        Q.pop();
        if(visited[r][c] != FALSE)
            continue;
        cnt++;
        visited[r][c] = visit;
        if (r+1 <=N && map[r+1][c] == 1)
            Q.push(make_pair(make_pair(r+1,c),map[r+1][c]));
        if (c+1 <=N  && map[r][c+1] == 1)
            Q.push(make_pair(make_pair(r,c+1),map[r][c+1]));
        if (r-1 >=0  && map[r-1][c] == 1)
            Q.push(make_pair(make_pair(r-1,c),map[r-1][c]));
        if (c-1 >=0 && map[r][c-1] == 1)
            Q.push(make_pair(make_pair(r,c-1),map[r][c-1]));
    }
    village[idx++]= cnt;
}

void input(int i, char *s) {
    for(int j=1;j<=N;j++)
        map[i][j] = *s++ - '0';
}

int main()
{
    char string[26];
    scanf("%d", &N);
    init();
    for(int i=1;i<=N;i++) {
        scanf("%s", string);
        input(i,string);
    }

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(visited[i][j] == FALSE && map[i][j] == 1) {
                Q.push(make_pair(make_pair(i, j), map[i][j]));
                BFS();
                visit++;
            }
        }
    }
//    printf("확인용\n");
//    for(int i=1;i<=N;i++)
//    {
//        for(int j=1;j<=N;j++)
//        {
//            printf("%d ", visited[i][j]);
//        }
//        printf("\n");
//    }
    printf("%d\n", visit-1);
    for(int i=0;i<idx;i++)
    {
        for(int j=0;j<idx-i-1;j++)
        {
            if(village[j] > village[j+1])
            {
                int temp = village[j];
                village[j] = village[j+1];
                village[j+1] = temp;
            }
        }
    }
    for(int i=0;i<idx;i++)
        printf("%d\n", village[i]);
}
#include <unistd.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
vector <pair <int, int> > comb;

int K,N,M,combnum;
string strn;
bool selected[10];
int switched= -1;
int tmax;
int kount= 0;
int finishflag;
#define MAX 1000002
int DP[MAX][20];

int number(int n)
{
    int cnt = 0;
    int copy = n;
    while(copy>0)
    {
        copy /=10;
        cnt++;
    }
    return cnt;
}

void make_combination(int start, int count)
{
    if(count == 2)
    {
        int a=0, b=0;
        for(int i=0;i<10;i++) {
            if(selected[i] == true) {
                if (a == 0)
                    a = i;
                else
                    b = i;
            }
        }
        comb.push_back(make_pair(a,b));
        return;
    }
//    cout << "DFS make combination" << start << "\n";
    for (int i=start;i<=M;i++)
    {
        if (selected[i] == false) {
//            cout << i <<"\n";
            selected[i] = true;
            make_combination(i + 1, count + 1);
            selected[i] = false;
        }
    }
}

string itoa(int n)
{
    char str[100];
    int m = number(n);
    str[m] = '\0';
    while(--m >= 0)
    {
        str[m] = n%10 + '0';
        n /=10;
    }
    return str;
}
int atoi(string str)
{
    int i = -1;
    int ret = 0;
    while(str[++i] != '\0')
    {
        ret = ret * 10 + str[i] - '0';
    }
    return ret;
}

int switchnum(int n, int a, int b)//
{
    //int n을 a번째와 b번째를 자릿수를 바꾸어서 반환한다.

    a--,b--;
    string str = itoa(n);
    if(str[b] == '0' && M == 2)
        return -1;
//    cout << str <<"itoa after \n";
    char temp = str[a];
    str[a] = str[b];
    str[b] = temp;
//    cout << str << "change after \n";
    int ret = atoi(str);
//    cout << ret << "atoi after \n";
    return ret;
}

int ft_max(int a, int b)
{
    return a  > b ? a : b;
}

int DFS(int n, int depth)
{
    if(depth == K)
        return n;
    if(DP[n][depth] != 0)
        return DP[n][depth];

    for(int i=0;i<M;i++)
    {
        for(int j=i+1;j<M;j++)
        {
            if (i==0 && strn[j] == '0') continue;
            swap(strn[i], strn[j]);
            int m = atoi(strn);
//            cout << m <<  "depth " << depth << "\n";
            DP[n][depth] = ft_max(DP[n][depth], DFS(m, depth+1));
            swap(strn[i], strn[j]);
        }
    }
    return DP[n][depth];
}

int find()//조합을 골라서 해당 자릿수의 숫자를 교환.
{
    if(M == 1)
        return finishflag=1;
    else
        return DFS(N, 0);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    strn = itoa(N);
    //K번 동안 자릿수의 교환을 반복해서 최댓값을 찾는다: 브루트 포스.
    //BFS 또는 DFS.
    M = number(N);
    combnum = M*(M-1)/2;
    make_combination(1, 0);
    int ans = find();
    if(finishflag)
        cout << "-1";
    else
    {
        if(ans == 0)
            cout << "-1";
        else
            cout << ans;
    }
//    cout << kount;
}

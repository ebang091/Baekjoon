#include <unistd.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 2147483647
#define MAX 1001
int N;
using namespace std;
char arr[2][MAX];
int sizearr[2];
int cache[MAX][MAX];

void input()
{
    string str;
    for(int i=0;i<2;i++)
    {
        cin >> str;
        sizearr[i] = str.length();
        for(int j = 0;j < str.size() ;j++)
            arr[i][j] = str[j];
    }
}

long long solve()
{
    for(int i=0;i<sizearr[0];i++)
    {
        if(arr[1][0] == arr[0][i])
            cache[0][i] = 1;
        else
            cache[0][i] = cache[0][i-1];
    }

    for(int j = 1 ; j < sizearr[1]; j++)
    {
        for(int i = 0; i < sizearr[0]; i++)
        {
            if (arr[1][j] == arr[0][i]) {
                if (i ==0)
                    cache[j][i] = 1;
                else
                    cache[j][i] = cache[j-1][i-1] + 1;
            }
            else
            {
                if (i == 0)
                    cache[j][i] = cache[j-1][i];
                else
                    cache[j][i] = max(cache[j-1][i], cache[j][i-1]);
            }
        }
    }
    long long  ans = cache[sizearr[1]-1][sizearr[0]-1];
//    for(int i=0;i<size[1];i++)
//    {
//        for(int j=0; j < size[0] ; j++)
//            cout << cache[i][j] << " ";
//        cout <<" \n";
//    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    cout << solve();




}
#include <unistd.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 2147483647
#define MAX 501
int N;
using namespace std;

long long arr[MAX];

vector <long long> S;

void input()
{
  long long a, b;
    for(int i=1;i<=N;i++)
    {
        cin >> a >> b;
        arr[a] = b;
    }
}

void solve()
{
    for (int i=0;i<501;i++) {
        if (arr[i] != 0 && (S.size() == 0 || S.back() < arr[i]))
            S.push_back(arr[i]);
        else if(arr[i] != 0) {
            auto it = lower_bound(S.begin(), S.end(), arr[i]);
            *it = arr[i];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    input();
    solve();
//    for(int i=0;i<S.size();i++)
//        cout << S[i] << " " ;
//    cout <<"\n";
    cout << N - S.size();



}
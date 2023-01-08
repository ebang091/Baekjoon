#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <unordered_map>


using namespace std;
vector <int> num;
int N,M;
unordered_map <int, int> m;

void input()
{
    int n;
    for(int i=0;i<N;i++) {
        cin >> n;
        m[n]++;
    }
}

void search()
{
    int find;
    for(int i=0;i<M;i++) {
        cin >> find;
        cout << m[find] << " ";
    }
    cout << "\n";
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    input();
    cin >> M;
    search();
}
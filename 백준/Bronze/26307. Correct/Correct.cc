#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <algorithm>
#include <map>
#include <stack>
#include <cstring>
#include <sstream>
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);
#define all(v) v.begin(), v.end()
#define NONE -1
#define EMPTY ' '
#define INF 2147483647
using namespace std;
vector<string> inputs;
int scores[101];
int N, S, P;
//9:00 ~ HH:MM

int main() {
    cin >> N >> S;
    int hour = N - 9;
    cout << 60* hour + S;

    

}    
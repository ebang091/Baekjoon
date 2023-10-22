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
int N, M, K;
int main() {
    cin >> N;
    string str;
    for(int i = 0; i < N ; i++){
        cin >> str;
        inputs.push_back(str);
    }
    // cout << "start";
    int len = inputs[0].size();
    int idx = len - 1;
    while(true){
        // cout << idx << "\n";
        bool flag = true;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < i; j++){
                string compare1 = inputs[i].substr(idx, len - idx);
                string compare2 = inputs[j].substr(idx, len - idx);
                // cout << "compare " << compare1 << " " << compare2 << "\n";
                if (i != j && compare1 == compare2){
                    // cout << "find\n";
                    flag = false;
                    break;
                }
            }
            if (!flag)
                break;

        }

        if(flag == true)
            break;
        idx--;
        if(idx == -1)
            break;

    }
    cout << inputs[0].size() - idx << "\n";
}    
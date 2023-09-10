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
#define INF 2147483647

using namespace std;
int N;
int friends[51][51] = {0,};
int visited[51] = {0,};
long long ans = -INF;

//다리 2개로 연결되면 연합이 되는 거다.
long long findFriends(int r){

set<int> s;
    long long ret = 0;
    for(int i = 0; i < N; i++){
        if(friends[r][i] == 1){
            s.insert(i);
            for(int j = 0; j < N; j++){
                if(r != j && friends[i][j] == 1)
                    s.insert(j);
            }
        }
    }

    // set<int>::iterator it;
    // for(it = s.begin(); it != s.end(); it++)
    //     cout << *it << " ";

    // cout << "\n";
    return s.size();
}

int main(){
    FAST
    cin >> N;
    string str;
    for(int i = 0 ; i < N; i++){
        cin >> str;
        for(int j = 0; j < N; j++){
            if(str[j] == 'Y')
                friends[i][j] = 1;
        }
    }

    long long max = -INF;
    for(int i = 0; i < N; i++){
        for(int j  = 0; j < N; j++)
            visited[j] = 0;
        int temp = findFriends(i);
        max = temp > max? temp : max;
    }

    cout << max;
    
    

}
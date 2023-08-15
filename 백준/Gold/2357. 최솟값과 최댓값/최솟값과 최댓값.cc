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
using namespace std;

#define SIZE (1 << 17)
#define NONE -1
#define INF 2147483647
enum WHAT {
    MIN,
    MAX
};
long long mintree[SIZE << 3] = {0,};
long long maxtree[SIZE << 3] = {0,};

int N, M;

/*
dp[i] = 카드를 i개 살때 최대 금액

dp[k] = max(dp[k], dp[i] + dp[k-i]) (i = 1 ... K/2)

*/
long long min(long long a, long long b){
    return a < b ? a : b;
}

long long max(long long a, long long b){
    return a > b ? a : b;
}

void update(int node, int v, WHAT l){
    node += SIZE -1;
    if(l == WHAT::MIN){
        mintree[node] = v;
        while(node >= 1){
            node /= 2;
            mintree[node] = min(mintree[node * 2], mintree[node* 2 + 1]);
        }
    }
    else{
        maxtree[node] = v;
        while(node >= 1){
        node /= 2;
        maxtree[node] = max(maxtree[node * 2], maxtree[node* 2 + 1]);
        }   
    }
    
}

int query(int l, int r, WHAT w){
    r += SIZE -1, l += SIZE -1;
    long long  ret;
    if(w == MIN){
        ret = INF;
        while(l <= r){
            if (l % 2 == 1)
                ret = min(ret, mintree[l++]);
            if (r % 2 == 0)
                ret = min(ret, mintree[r--]);
            l /= 2;
            r /= 2;
        }
    }
    else{
        ret = -INF;
        while(l <= r){
            if (l % 2 == 1)
                ret = max(ret, maxtree[l++]);
            if (r % 2 == 0)
                ret = max(ret, maxtree[r--]);
            l /= 2;
            r /= 2;
        }
    }
    return ret;
}


int main(){
    FAST
    cin >> N >> M;
    int n;
    for(int i = 0 ; i < N; i++){
        cin >> n;
        update(i, n, WHAT::MIN);
        update(i, n, WHAT::MAX);
    }
    int a ,b;
    for(int i = 0; i < M ; i++){
        cin >> a >> b;
        cout << query(a-1, b-1 , WHAT::MIN) <<" ";
        cout << query(a-1, b-1 , WHAT::MAX) <<"\n";
    }
    

}
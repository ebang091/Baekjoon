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

#define NONE -1
#define INF 2147483647

long long nums[200001] = {0,};
long long  N, M;
long long  SIZE = (1 << 17);
vector <long long > tree(SIZE << 2);
/*
num 5 4 3 2 1

tree


*/
void update(long long node, long long v){
    node += SIZE -1;
    tree[node] = v;
    while(node > 1){
        node /= 2;
        tree[node] = min(tree[node * 2], tree[node*2 +1]);
    }
}

long long query(long long l, long long r){
    l += SIZE -1;
    r += SIZE -1;
    long long ret = INF;
    while(l <= r){
        if(l % 2 == 1)
            ret = min(ret, tree[l++]);
        if(r % 2 == 0)
            ret = min(ret, tree[r--]);
        l /= 2; 
        r /= 2;
    }
    return ret;
}

int main(){
    FAST
    cin >> N;
    SIZE = (1 << ((int)log2(N) + 1)) ;
    tree.resize(SIZE << 1);
    for(int i = 0; i < N; i++){
        cin >> nums[i];
        update(i+1, nums[i]);
    }
    cin >> M;
    int o,a,b;
    for(int i = 0; i < M; i++){
        cin >> o >> a >> b;
        if(o == 1) {
            nums[a-1] = b;
            update(a, b);
        }
        else if(o == 2){
            cout << query(a, b) << "\n";
        }
    }
}
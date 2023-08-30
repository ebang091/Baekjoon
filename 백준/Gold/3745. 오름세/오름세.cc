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

long long  nums[100001];
long long  N, M;



long long  SIZE = (1 << 17);
vector <long long > tree(SIZE << 2);
long long fmax(long long a , long long b){
    return a > b? a : b;
}

void update(long long node, long long v){
    node += SIZE;
    tree[node] = v;
    while(node > 1){
        node /= 2;
        tree[node] = max(tree[node * 2] , tree[node*2 +1]);
    }
}

long long query(long long l, long long r){
    l += SIZE ;
    r += SIZE ;
    long long ret = 0;
    while(l <= r){
        if(l % 2 == 1)
            ret = fmax(tree[l++], ret);
        if(r % 2 == 0)
            ret = fmax(tree[r--], ret);
        l /= 2; 
        r /= 2;
    }
    return ret;
}



int main(){
    FAST
    while(true){
        cin >> N;
        if(cin.eof())
            break;
        for(int i = 0; i <= (SIZE << 1); i++)
            tree[i] = 0;

        int n;
        for(int i = 0; i < N; i++){
            cin >> nums[i];
        }

        long long max;
        for(int i = 0; i < N ; i++){
            max = 0;
            max = fmax(query(1, nums[i] - 1), max);
            update(nums[i], max + 1);
        }
        cout << query(1, (SIZE << 1)) << "\n";
    }
    
}
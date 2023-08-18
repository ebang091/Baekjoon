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
struct Node{
    long long  value;
    long long  idx;
   void  operator=(Node a){
        this->idx = a.idx;
        this->value = a.value;
    }
};

vector <Node> tree(SIZE << 3);
bool operator <(Node a, Node b){
    if(a.value < b.value)
        return true;
    else if(a.value == b.value)
        return a.idx < b.idx;
    return false;
}

/*
num 5 4 3 2 1

tree


*/


void update(long long n, long long v){
    n += SIZE -1;
    tree[n].idx = n - (SIZE -1);
    tree[n].value = v;
    while(n > 1){
        // cout << "tree[" << n << "]" <<" = " << tree[n].idx << " " << tree[n].value << "\n";
        n /=2;
        if(tree[n*2] < tree[n*2 + 1]){
            tree[n].idx = tree[n*2].idx;
            tree[n].value = tree[n*2].value;
        }
        else{
           tree[n].idx = tree[n*2 + 1].idx;
            tree[n].value = tree[n*2 + 1].value;
        }
        // nums[tree[2 *n]] < nums[tree[2 * n + 1]] ? tree[2*n] : tree[2*n+1];
    }
}

long long  query(long long l, long long r){
    Node  ret;
    l += SIZE -1, r += SIZE -1;
    ret = tree[l];
    while(l <= r){
        // cout << "l = " << l << " " << "r = "  << r << "\n";
        if(l % 2 == 1){
            // cout << "l search  tree["<< l <<"]  =" << tree[l].idx << "\n";
            ret  = ret < tree[l] ? ret : tree[l];
            l++;
        }
        if(r % 2 == 0){
            // cout << "r search  tree["<< r <<"]  =" << tree[r].idx << "\n";
            ret = ret < tree[r] ? ret : tree[r];
            r--;
        }
        l /=2;
        r /=2;
    }
    return ret.idx;
}

int main(){
    FAST
    cin >> N;
    SIZE = (1 << ((int)log2(N) + 1)) ;
    tree.resize(SIZE << 1);
    for(long long i = 0; i <= (SIZE << 1); i++)
        tree[i].value = INF;
    long long  n;
    for(long long  i = 1; i <= N; i++){
        cin >> nums[i];
        tree[i + SIZE -1].idx = i;
        tree[i + SIZE -1].value = nums[i];
    }

    for(int i = 1; i <= N; i++){
        update(i, nums[i]);
    }
    // cout << tree[1].idx << " " << tree[1].value<< "\n";
    // cout << tree[2].idx << " " << tree[2].value << " " << tree[3].idx << " " << tree[3].value << "\n";

    cin >> M;
    long long o, a, b;

    for(int i = 0; i < M ;i++){
        cin >> o >> a >> b;
        if(o == 1){
            nums[a] = b;
            update(a, b);
            // cout << "check :" << tree[a + SIZE -1].value << "\n";
        }
        else if(o == 2) {
            cout << query(a, b) << "\n";
        }
    }
}
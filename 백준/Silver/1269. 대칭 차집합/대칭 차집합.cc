#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <regex>
#include <cmath>
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

set <long long>A;
set <long long >B;
set<long long> ans;
int N, M;
int main(){
    FAST
    cin >> N >> M;
    long long n;
    for(int i = 0; i < N; i++){
        cin >> n;
        A.insert(n);
    }
    for(int i = 0; i < M; i++){
        cin >> n;
        B.insert(n);
    }
    set<long long>::iterator it;
    
    for(it = A.begin(); it != A.end(); it++){
        if(B.find(*it) == B.end())
            ans.insert(*it);
    }

   for(it = B.begin(); it != B.end(); it++){
        if(A.find(*it) == A.end())
            ans.insert(*it);
    }
    cout << ans.size();
}
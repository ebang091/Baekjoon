#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(pair<int, int> a, pair<int ,int> b){
    if(a.second == b.second)    
        return a.first < b.first;
    return a.second < b.second;
}

int main(){
    int N,n;
    vector<pair<int,int> > nums;
    int answer[1001];
    cin >> N;
    for(int i = 0; i < N ; i++){
        cin >> n;
        nums.push_back(make_pair(i, n));
    }
  
    sort(nums.begin(), nums.end(), cmp);
    for(int i = 0; i < N; i++){
          answer[nums[i].first] = i;
     }
     for(int i = 0; i < N; i++){
          cout << answer[i] << " ";
     }
    
}
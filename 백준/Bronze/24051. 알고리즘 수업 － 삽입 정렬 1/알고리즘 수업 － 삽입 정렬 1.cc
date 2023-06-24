#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
long long  nums[10010];

int main(){
    cin >> N >> M;
    int count = 0;
    long long n;
    for(int i = 0; i < N; i++){
        cin >> nums[i];
    }

    bool flag = false;
    
    for(int i = 1; i < N; i++){
        int loc = i -1;
        n = nums[i];
        while (0 <= loc && n < nums[loc]){
            nums[loc + 1] = nums[loc];
            count++;
            if(count == M){
                cout << nums[loc + 1];
                flag = true;
            }
            loc--;
        }
        if(loc+1 != i)
        {nums[loc + 1] = n;
        count++;}

        if(count == M && flag ==0 ){
            cout << nums[loc + 1];
            flag = true;
        }
    }
    if(count < M)
        cout << "-1";
}
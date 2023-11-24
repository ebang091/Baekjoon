#include <iostream>
#include <algorithm>
using namespace std;
#define FAST std::ios::sync_with_stdio(0); std::cin.tie(0);
#define INF 2147483647
long long B,K;
vector<int> krain;
vector<int> box;
int carried[10001] = {0,};
/*
화물을 배에 실어야 한다.

크레인 N대
1분에 박스 한대씩.

무게 제한보다 무거운 박스는 크레인으로 움직일 수 없다. 

1. 각 크레인의 무게 제한
2. 각 박스의 무게제한
-> 어떤 크레인이 어떤 박스를 가지고 운반하는게 좋을까?
모든 크레인은 동시에 움직인다. 

그리디일까?
- 들 수 있는 무게가 가장 큰 크레인이 가장 큰 물건을 든다. && 들지 못하는 물건의 경우 들 수 있는 물건 중 가장 무거운 물건을 든다.
- 정답이 들 수 있는 무게가 더 작은 r 크레인이 가장 큰 물건을 든다고 쳐보자.
    -> 바뀐 상황도 정답이 가능하다.


- 다만 해당 크레인이 물건을 들지 못하는 상황인 경우, 더 큰 크레인이 들때까지 기다릴 수도 있다. 

*/

void input() {
    
    cin >> K;
    int n;
    for(int i = 0; i < K; i++){
        cin >> n;
        krain.push_back(n);
    }

    cin >> B;
    for(int i = 0; i < B; i++){
        cin >> n;
        box.push_back(n);
    }    
}

void printContainer(const vector<int>& c){
    for (auto i = c.begin(); i != c.end(); i++)
        std::cout << *i << ' ';
    std::cout << '\n';
}

int solve(){
    
    int boxCount = 0;
    int time = 0;

    sort(krain.begin(), krain.end(), greater<int>());
    sort(box.begin(), box.end(), greater<int>());

    if(krain[0] < box[0])
        return -1;
    
    while (box.empty() == false) {
        for (int i = 0; i < K; i++) {
            //들 수 있는 박스를 찾아서.
            for (int j = 0; j < box.size(); j++) {
                if(krain[i] >= box[j]) {
                    box.erase(box.begin() + j);
                    // printContainer(box);
                    break;
                }
            }
        }
        time++;
    }
    return time;
}

int main() {
    
    FAST
    input();

   

    cout << solve();
   

    
}
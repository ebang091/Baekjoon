#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define FAST std::ios::sync_with_stdio(0); std::cin.tie(0);
#define INF 2147483647
int N;
int cannotUse[10] = {0,};
vector<int> channel;
// 0, 1, 2, 3 ...9. +, -
//channel >= 0
//목적과 가까운 숫자을 누른다음 특정 숫자를 더하거나 빼서 (== 누르는 횟수) 원하는 숫자로 간다.

int main() {
	cin >> N;
	int count = 0;
	int leftBirds = N;
	int flyBirds = 0;
	int i = 1;
	while(flyBirds < N){
		if(leftBirds < i){ //i만큼 날아갈 수 없다면
			i = 1;
		}
		count ++;
		leftBirds -= i;
		flyBirds += i++;

	}
	cout << count;
}
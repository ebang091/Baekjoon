#include <iostream>
#include <algorithm>
#include <queue>
#include <sstream>
#include <string>
#include <map>
using namespace std;
#define FAST std::ios::sync_with_stdio(0); std::cin.tie(0);
#define INF 2100000000
#define MAX_HEAP_SIZE 10000010
int N;
int x, y;
int answer = INF;
//기다리는 시간의 최소를 구하자 : T초 미루었을 때
//1. 기다리는 시간을 미리 구해둔다. 
//2. 투포인터로 배열의 합이 최소인 경우의 수를 구한다. 

// 약속시간 마법사 도착시간
// 약속시간 - 마법사 도착 시간 == 마법사가 기다리는 시간. (음수면 머글이 기다리는 시간)
// 일단 구해놓는다
// -1 3    -> 1시간 미루면(1증가) 0 4,  2시간 미루면(1 5) 
//-1 시간 미루면 (1감소) -2, 2


//
int diff[52] = {0,};
int main() {
	
	FAST
	cin >> N; 
	long long fmax = -INF;
	long long fmin = INF;
	for(int i = 0; i < N; i++){
		cin >> x >> y; 
		diff[i] = y - x;
	}
	// cout << "max min = " << fmax << " " << fmin << "\n";

	sort(&diff[0], &diff[N]);

	//1 2 3 4 5
	int	mid = diff[N/2];
	if(N % 2 == 1)
		cout << 1;
	else {
		cout << abs(diff[N/2] - diff[N/2 -1]) + 1;
	}
	
	
}
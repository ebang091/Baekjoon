#include <iostream>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;
#define FAST std::ios::sync_with_stdio(0); std::cin.tie(0);
#define INF 198765432
int N;
int dp[1000010] = {0,};
int cannotUse[11] = {0,};
vector<int> validNumber;

// 0, 1, 2, 3 ...9. +, -
//channel >= 0
//목적과 가까운 숫자을 누른다음 특정 숫자를 더하거나 빼서 (== 누르는 횟수) 원하는 숫자로 간다.

//거리가 가장 가까운 숫자를 반환한다. 단, 거리가 같은 경우.. 
//

int countDecimal(long long number){
	long long copy = number;
	if(number == 0)
		return 1;
	int cnt = 0;
	while(copy > 0){
		copy /= 10;
		cnt++;
	}
	return cnt;
}

void DFS(long long number) {
	if (number >= 1000001)
		return;
	
	if (dp[number] != INF)
		return;
		
	dp[number] = countDecimal(number);
	// cout << "num " << number << " : " << dp[number];

	for(int i = 0; i < validNumber.size(); i++){
		long long temp = number * 10 + validNumber[i];
		DFS(temp);
	}
}

int main() {
	cin >> N;
	int n;
	
	cin >> n;
	int a;
	for (int i = 0; i < n; i++){
		cin >> a;
		cannotUse[a] = 1;
	}
	
	for (int i = 0; i <= 9; i++) {
		if(cannotUse[i] == 0)
			validNumber.push_back(i);
	}

	// //check
	// for(int i = 0; i < validNumber.size(); i++)
	// 	cout << validNumber[i] << " ";
	// cout << "\n\n";

	for (int i = 0; i <= 1000001; i++)
		dp[i] = INF;	



	//solution

	for(int i = 0; i < validNumber.size(); i++)	{
		// if(validNumber[i] != 0)
		DFS(validNumber[i]);
	}

	
	int plusDistance = 0;
	int biggerNumber = 0;
	while(true) {
		if(dp[N + plusDistance] != INF || N + plusDistance > 1000000){
			biggerNumber = plusDistance + N;
			break;
		}
		plusDistance++;		
	}

	dp[100] = 0;
	// if(cannotUse[0] == 0)
		// dp[0] = 1;
	for(int i = 1; i <= N; i++) {
		dp[i] = min(dp[i-1] + 1, dp[i]);
	}

	// cout << "bigger number : " << biggerNumber << " " << plusDistance <<  "\n";
	for(int i = biggerNumber; i >= N; i--) {
		dp[i] = min(dp[i], dp[i+1] + 1);
	}
	cout << dp[N] << "\n";

}

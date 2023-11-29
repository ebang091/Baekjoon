#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define FAST std::ios::sync_with_stdio(0); std::cin.tie(0);
#define INF 2147483647
int N;
int nums[1001][3] = {0,};
// int S[1001] = {0,};
int T[1001] = {0,};
vector<pair<int, int> > S;
int minimalStart[1001] = {0,};
// 1, 2, ... N
// 끝나는 시간 걸리는 시간
// T, S

/*
3 5
8 14
5 20
1 16
*/
bool cmp(pair<int, int>& a, pair<int, int>& b){
	// int minimalStartTimeA = minimalStart[a.first];
	// int minimalStartTimeB = minimalStart[b.first];
	
	// if(minimalStartTimeA < minimalStartTimeB)
	// 	return true;
	// else if(minimalStartTimeA == minimalStartTimeB)
	// 	return a.second < b.second;
	// return false;

	if(a.second == b.second) return T[a.first] < T[b.first];
	return a.second < b.second;
}

int main() {

	cin >> N;
	int a, b;
	for(int i = 0; i < N; i++) {
		cin >> a >> b;
		T[i] = a;
		S.push_back(make_pair(i, b));
		minimalStart[i] = b - a;
		// cout << "minimal start : " << minimalStart[i] << "\n";
	}


	int answer = -1;
	sort(&S[0], &S[N], cmp);
	int minStart = minimalStart[S[0].first];
	for(int start = minStart; start >= 0; start--) {
		int endTime = start;
		bool success = true;
		answer = start;
		// cout << "time : " << start << "\n\n";
		for(int j = 0; j < N; j++) {
			int idx = S[j].first;
			endTime += T[idx];
			// cout << "end time : " << endTime << "\n";
			if(endTime > S[j].second){//deadline 넘어감.
				success = false;
				if(start == 0){
					cout << "-1";
					return 0;
				}
			}
		}
		if (!success)
			continue;
		else
			break;
	}
	cout << answer;
}
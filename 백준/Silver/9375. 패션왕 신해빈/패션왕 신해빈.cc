#include <iostream>
#include <algorithm>
#include <queue>
#include <sstream>
#include <string>
#include <map>
using namespace std;
#define FAST std::ios::sync_with_stdio(0); std::cin.tie(0);
#define INF 198765432
int TC;
// int nums[100001] = {0,};
int selected[31] = {0,};
int answer = 0;

// 0, 1, 2, 3 ...9. +, -
//channel >= 0
//목적과 가까운 숫자을 누른다음 특정 숫자를 더하거나 빼서 (== 누르는 횟수) 원하는 숫자로 간다.

//거리가 가장 가까운 숫자를 반환한다. 단, 거리가 같은 경우.. 
//

void DFS(int depth, int idx, int count, vector<int>& numberOfClothes){
	if(depth == numberOfClothes.size() || idx >= numberOfClothes.size()){
		return;
	}

	answer += count;
	// cout << "dfs " << depth << " " << idx << " "  << count << "\n";
	for(int i = idx + 1; i < numberOfClothes.size(); i++){
		if(selected[i] == 0){
			selected[i] = 1;
			DFS(depth + 1, i, count * numberOfClothes[i], numberOfClothes);
			selected[i] = 0;
		}
	}
}

int main() {
	FAST
	cin >> TC; 
	int clothCount;
	string wear;
	string weartype;

	for(int i = 0; i < TC; i++){
		cin >> clothCount;
		vector<int> numberOfClothes;
		map <string, int> clothes;
		answer = 0;
		// cout << "new TC start\n";
		for(int j = 0; j < clothCount;j++){
			cin >> wear;
			cin >> weartype;
			if(clothes.find(weartype) == clothes.end()){
				clothes.insert(make_pair(weartype, 1));
				continue;
			}
			clothes[weartype] = clothes[weartype] + 1;
		}

		map<string, int>::iterator it = clothes.begin();
	
		for(; it != clothes.end(); it++) {
			numberOfClothes.push_back((*it).second);
		}


		answer = 1;
		for(int i = 0 ; i < numberOfClothes.size(); i++){
			answer *= (numberOfClothes[i] + 1);
		}
		answer--;
		cout << answer << "\n";


	}
}
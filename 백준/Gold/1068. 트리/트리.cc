#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define FAST std::ios::sync_with_stdio(0); std::cin.tie(0);
#define INF 2147483647
int N, node;
int parents[51];
int erased[51] = {0,};
int root;
vector<vector< int> > tree;

bool isLeafNode(int n){
	bool isLeaf = true;
	//자식들이 없거나 모두 지워졌다면 리프 노드이다.
	for(int i = 0; i < tree[n].size(); i++){
		if (erased[tree[n][i]] == 0){
			isLeaf = false;
			break;
		}
	}
	return isLeaf;
}

void findNodeAndErase(int parent) {
	if (erased[parent] == 1)
		return;

	erased[parent] = 1;
	for (int nodeIdx = 0; nodeIdx < tree[parent].size(); nodeIdx++) {
		int childNode = tree[parent][nodeIdx];
		if(erased[childNode])
			continue;
		findNodeAndErase(childNode);
	}
}

int main() {
	//트리 정보를 입력받아서, 재귀적으로 트리를 만든다.
	cin >> N;
	tree.resize(N);
	for(int i = 0; i < N; i++){
		cin >> parents[i];
		if(parents[i] == -1)
			root = i;
		else{
			tree[parents[i]].push_back(i);//부모 - 자식들 여러개
		}
	}


	cin >> node;
	if(node == root){
		cout << "0";
		return 0;
	}

	findNodeAndErase(node);

	// cout << "check erased \n";
	// for(int i = 0; i < N; i++){
		// cout << erased[i] << " ";
	// }
	// cout << "\n";
	int answer = 0;
	for(int i = 0; i < N; i++){
		if(erased[i] == 1)
			continue;
		if(isLeafNode(i))
			answer++;
	}
	cout << answer;

}
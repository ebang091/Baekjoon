#include <iostream>
#include <algorithm>
#include <queue>
#include <sstream>
#include <string>
#include <map>
using namespace std;
#define FAST std::ios::sync_with_stdio(0); std::cin.tie(0);
#define INF 2147483647
#define MAX_HEAP_SIZE 1000000
int N;
int x, y;
int answer = INF;
int tree[MAX_HEAP_SIZE];
int heapSize = 1;

void minHeapify(int n);
int parent(int i){
	return i / 2;
}

int leftChild(int i){
	return i * 2;
}

int rightChild(int i){
	return i * 2 + 1;
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void insertKey(int key) { //min heap 구조로 설계한다.

	int idx = heapSize; //마지막 노드에 저장
	tree[idx] = key;

	heapSize++;

	while(idx != 0 && tree[idx] < tree[parent(idx)]) {
		swap(&tree[idx], &tree[parent(idx)]);
		idx = parent(idx);
	}	
}

int deleteKeyMin() {// min heap 구조에서 가장 작은 값 제거하기 = 루트
	// if (heapSize == 2) {
	// 	heapSize--;
	// 	return tree[1];
	// }

	if(heapSize == 1)
		return 0;

	int root = tree[1];
	heapSize--;
	tree[1] = tree[heapSize];
	minHeapify(1);

	return root;
}

int deleteKeyMax(){//min heap 구조에서 가장 큰 값 제거하기

}

void minHeapify(int n){
	
	// int l = leftChild(n);
	// int r = rightChild(n);
	// int smallest = n;
	// if(l < heapSize && tree[smallest] > tree[l])
	// 	smallest = l;
	// if(r < heapSize && tree[smallest] > tree[r])
	// 	smallest = r;

	// if(n != smallest){
	// 	swap(&tree[n], &tree[smallest]);
	// 	minHeapify(smallest);
	// }
	// priority_queue<int> pq;	

	int currentIdx = 1;
	while(true) {

		int l = leftChild(n);
		int r = rightChild(n);

		int smallest = currentIdx;
		if(l < heapSize && tree[smallest] > tree[l])
			smallest = l;

		if(r < heapSize && tree[smallest] > tree[r])
			smallest = r;

		if(smallest != currentIdx){
			swap(&tree[currentIdx], &tree[smallest]);
			currentIdx = smallest;
		}
		else{
			break;
		}

	}




}





int main() {
	
	FAST
	cin >> N;
	priority_queue<int> pq;
	for(int i = 0; i < N; i++){
		cin >> x;
		if(x == 0){
			// int result = deleteKeyMin();
			// cout << result << "\n";
			if(pq.size() == 0)
				cout << "0\n";
			else {
				cout << -pq.top() << "\n";
				pq.pop();
			}
				
		}
		else {
			// insertKey(x);
			pq.push(-x);
		}
	}
	

}
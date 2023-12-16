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


int main() {
	
	FAST
	cin >> N;
	int operateCount;
	char order;
	int value;


	for(int tc = 0; tc < N; tc++){
		cin >> operateCount;
		priority_queue<long long , vector<long long >, greater<long long > > minHeap;
		priority_queue<long long , vector<long long >, less<long long> > maxHeap;
		map<int, int> numberCount;
		for(int i = 0; i < operateCount; i++) {
			cin >> order >> value;

			if (order == 'I'){
				minHeap.push(value);
				maxHeap.push(value);
				if(numberCount.find(value) == numberCount.end())
					numberCount.insert(make_pair(value, 1));
				else{
					numberCount[value] = numberCount[value] + 1;
				}
			}
			else {
				if(value == -1){
					if(minHeap.size() == 0)
						continue;
					int result = minHeap.top();
					minHeap.pop();
					numberCount[result]--;
				}
				else {
					if(minHeap.size() == 0)
						continue;
					int result = maxHeap.top();
					maxHeap.pop();
					numberCount[result]--;
				}
				
				while (minHeap.empty() == false && numberCount[minHeap.top()] <= 0)
					minHeap.pop();
				while (maxHeap.empty() == false && numberCount[maxHeap.top()] <= 0)
					maxHeap.pop();

			}
		}

		while (minHeap.empty() == false && numberCount[minHeap.top()] <= 0)
			minHeap.pop();
		while(maxHeap.empty() == false && numberCount[maxHeap.top()] <= 0)
			maxHeap.pop();

		if (minHeap.size() == 0){
			cout << "EMPTY\n";
		}
		else {
			cout << maxHeap.top() << " " << minHeap.top() << "\n";
		}
	}	

}
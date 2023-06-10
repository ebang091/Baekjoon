#include <iostream>
#include <vector>
#include <algorithm>

#define FAST cin.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
vector<int> length;
long long ans;
/*
K개의 랜선을 갖고 있고, 이 랜선을 길이가 일정한
n개의 랜선으로 만들어야 한다. 이때 그 랜선의 길이가 가장 크도록 만들자. 
*/

int N,K;
int main(){
	FAST
	cin >> K >> N;
	int n;
	for(int i = 0; i < K; i++){
		cin >> n;
		length.push_back(n);
	}
	long long low = 1;
	long long high = *max_element(length.begin(), length.end());

	while(low <= high){
		long long mid = (low + high)/2;
		long long count = 0;		
		for(int i = 0; i < K; i++){
			count += length[i]/mid; 
		}
		if(count >= N){
			ans = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}

	cout << ans;

}
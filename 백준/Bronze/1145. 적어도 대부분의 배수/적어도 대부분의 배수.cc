#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define FAST std::ios::sync_with_stdio(0); std::cin.tie(0);
#define INF 2147483647
int N;
int nums[51];
bool isSequel(int a, int b){

}

bool min(int a, int b){
	return a< b ? a : b;
}

int canDivided(int n){
	int ret = 0;
	for(int i = 0; i < 5; i++){
		if(n % nums[i] == 0)
			ret++;
	}
	
	return ret;
}
int main() {
	FAST
	long long total = 1;
	int vmin = 2147483647;
	for(int i = 0; i < 5; i++){
		cin >> nums[i];
		total *= nums[i];
		// vmin = min(vmin, nums[i]);

	}

	int answer=  1;
	for(long long i = 2; i <= total; i++) {
		int count = canDivided(i);
		// cout << "i : " << i << " count " << count << "\n";
		if(count >= 3){
			// cout << "Find " << i <<  " " << count << "\n";
			cout << i;
			return 0;	
		}
	}
	// cout << answer;
}
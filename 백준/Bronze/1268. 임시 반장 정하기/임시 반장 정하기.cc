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
//기다리는 시간의 최소를 구하자 : T초 미루었을 때한다. 

//
int main() {
	
	FAST
	cin >> N; 
	int students[1001][6] = {0,};
	/*
	1학년 1반


	1. 학년을 순회 (5)
	2. 학년마다 학생을 순회, 같은 반인 학생들에 대해 기록(중복은 없음)
		(N)
	3. 기록한 수를 토대로 반장 선거.
	*/	

	for(int i = 0; i < N; i++){
		for(int j = 0; j < 5; j++){
			cin >> students[i][j];
		}
	}

	int sameClass[1001][1001] = {0,};

	for(int j = 0; j < 5; j++){
		for(int i = 0; i < N; i++){
			for(int k = i + 1; k < N; k++){
				if(students[i][j] == students[k][j]){
					sameClass[i][k] = 1;
					sameClass[k][i] = 1;
				}
			}
		}
	}
	//i ㄹ아 kㄹ아 같은 반
	int maxCnt = -2;
	int maxStudent;
	for(int i = 0; i < N; i++){
		int cnt = 0;
		for(int j = 0; j < N; j++){
			// cout << sameClass[i][j] << " ";
			if(sameClass[i][j] == 1){
				cnt++;
			}

		}
		// cout << "\n";
		if(cnt > maxCnt){
			maxCnt = cnt;
			maxStudent = i;
		}
	}
	cout << maxStudent + 1;

}
#include <iostream>
using namespace std;

int P[5];	  //인덱스 번호 = 키, 값 = 자신보다 키큰사람 명수

int main() {
	int N, left;
	cin >> N;   //사람 수 입력, 예제에서는 4명 입력.

 	for (int i = 0; i < N; i++) {   //0부터 하지만 i+1이 키
		cin >> left;   //키가 1인 사람부터 왼쪽 키가 큰 사람 수 입력
        
		for (int j = 0; j < N; j++) {
   			if (left == 0 && P[j] == 0) {  //키 큰 사람들을 지나쳤고 자신의 자리라면
    			P[j] = i + 1;           //P[j]는 자신의 위치, i+1은 키
    			break;
   			}
   			else if (P[j] == 0) {  //키 큰 사람이 남았다면 돌아가서 j++
    			left--;
   			}
		}

	}
	for (int i = 0; i < N; i++) {
		cout << P[i] << ' ';   //서 있는 순서대로 키 출력
    }

	return 0;
}
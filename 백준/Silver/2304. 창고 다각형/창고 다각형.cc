#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <set>
#include <algorithm>
#include <map>
#include <stack>
#include <cstring>
#include <sstream>
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);
#define all(v) v.begin(), v.end()
#define NONE -1
#define EMPTY ' '
#define INF 2147483647
using namespace std;

int N;
int columns[1001] = {0,};
/*
기둥들의 폭은 모두 1m이고 높이는 다르다. 양철로 된 창고를 제작하려고 한다.
창고에는 모든 기둥이 들어간다. 

기둥들을 입력받고, 창고 다각형의 넓이 중 가장 작은 넓이를 구한다.


  4   6 3     10     4     6     8
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15

오름차순이 되게끔 고르고, 내림차순이 되게끔 내린다. 
*/

int main(){
    // FAST
    
    cin >> N;
    int n, h;
    int maxHeight = -1;
    int maxHeightIdx = 0;
    for(int i = 0; i < N ;i++){
        cin >> n >> h;
        columns[n] = h;
        if(h > maxHeight){
            maxHeight = h;
            maxHeightIdx = n;
        }
    }

    int left = 0;
    int square = 0;
    for(int i = 1; i <= maxHeightIdx; i++){
        if(columns[i] > left){
            left = columns[i];
        }
        square += left;
    }
    int right = 0;
    for(int i = 1000; i > maxHeightIdx; i--){
        if(columns[i] > right){
            right = columns[i];
        }
        square += right;
    }
    
       cout << square;
}
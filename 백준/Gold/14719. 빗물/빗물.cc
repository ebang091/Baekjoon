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

int W,H;
int blocks[501] = {0,};

int findStandardHeight(int idx){
    int left = -1, right = -1;
    for(int i = 0; i < idx; i++){
        int height = blocks[i];
        if (height > left) {
            left = height;
        }
    }

    for(int i = idx + 1; i < W; i++){
        int height = blocks[i];
        if (height > right){
            right = height;
        }
    }

    return left < right ? left : right;
}
int main(){
    // FAST
    
    cin >> H >> W;
    
    int n;
    stack<int> world;
    for (int i = 0; i < W; i++){
        cin >> n;
        blocks[i] = n;
    }

    int rain = 0 ;
    
    for(int i = 0; i < W; i++){
        int height = blocks[i];
        int standard = findStandardHeight(i);
        if(standard >= height)
            rain += (standard - height);
    }

    cout << rain;
}
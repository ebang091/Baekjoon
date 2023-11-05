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

int main(){
    // FAST
    
    double d,f,p;
    cin >> N;
    
    for(int i = 0; i < N ;i++){

        cin >> d >> f >> p;
        std::cout.setf(std::ios_base::fixed);
        cout.precision(2);
        
        cout << "$"  << d*f*p << "\n";
    }
       
}
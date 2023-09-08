#include <iostream>
#include <vector>
#include <cmath>
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
#define INF 2147483647

using namespace std;

long long  num[82] = {0,};



int main(){
    FAST
    string a, b;
    cin >> a >> b;
    int length1 = a.size() -1;
    int length2 = b.size() - 1;
    int maxlength = length1 >= length2 ? length1 : length2;
    int prev = 0;

    int i = 0; 
    while(i <= maxlength){
        long long  add = 0;
        if(i <= length1)
            add += a[length1 - i] - '0';
        if(i <= length2)
            add += b[length2 -i] - '0';
        add += prev;
        num[i] = add % 2;
        prev = add / 2;
        i++;
    }

    if(prev % 2 > 0){
        num[i] = prev;
        maxlength++;
    }

    bool start = true;
    for(int j = maxlength; j >= 0; j--){
        if(start && num[j] == 0)
            continue;
        start = false;
        cout << num[j];
    }
    if(start)
        cout << "0";
}
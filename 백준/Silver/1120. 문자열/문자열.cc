#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>
#include <map>
#include <stack>
#include <cstring>
#include <sstream>
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);
using namespace std;

#define NONE -1
#define INF 198765432


int main(){
    FAST
    string str;
    string strA;
    string strB;

    cin >> strA >> strB;
    // stringstream ss;
    // ss << str;
    // strA = ss.str();
    // ss.clear();
    // ss << str;
    // strB = ss.str();

    // cout << strA << " " << strB << "\n";
    int min = INF;
    for(unsigned int i = 0; i <= strB.size()- strA.size(); i++){
        //strB의 시작점이 i.
        int cnt = 0;
        for(unsigned int j = 0; j < strA.size(); j++){
            if(strA[j] != strB[i + j]) 
                cnt++;
        }
        // cout << "i , cnt : " << i << " " << cnt << "\n";
        if(cnt < min)
            min = cnt;
    }

    cout << min;
}
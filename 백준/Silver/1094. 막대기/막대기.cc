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
#define EMPTY ' '
#define INF 2147483647
using namespace std;
vector<string> inputs;
int scores[101];
int N, S, P;
//9:00 ~ HH:MM

string intToBinary(int n, string ret) {
    // cout << "called " << n <<"\n";
    if(n == 1)
        return ret + "1";
    else if(n == 0)
        return ret + "0";

    if(n % 2 == 0)
        return intToBinary(n/2, ret + "0");
    return intToBinary(n/2, ret + "1");
    
}

int countOne(string str){
    // cout << str <<"\n";
    int count = 0;
    for(int i = 0 ; i < str.size(); i++){
        if(str[i] == '1')
            count++;
    }
    return count;
}
int main() {
    cin >> N ;
    string str = "";
    cout << countOne(intToBinary(N, str));
   

    

}    
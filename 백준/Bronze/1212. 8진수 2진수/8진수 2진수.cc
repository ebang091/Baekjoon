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

long long N;

/*

2의 제곱 : 12  9  6  3  0
         1 1 1 1 1
         
         3 = 3번째 자리
         6 = 

*/

int main(){
    string numStr;
    cin >> numStr;

    stack <long long> output;
    // cout << numStr ;
    if(numStr == "0"){
        cout << "0";
        return 0;
    }

    for(int i = numStr.size() - 1; i >=0; i--){
        long long num = numStr[i] - '0';
        // cout << "num : " << num << "\n";
         for(int j= 0; j < 3; j++){
            // cout << "push " << num % 2 << " " ; 
            output.push(num % 2);
            num /= 2;
        }
    }

    // cout << N << " " << copy <<"\n";

    // while(copy > 0){
    //     long long num = copy % 10; //실제 10진수 값.
    //     cout << "num : " << num << "\n";
    //     for(int i = 0; i < 3; i++){
    //         cout << "push " << num %2 << " " ; 
    //         output.push(num % 2);
    //         num /= 2;
    //     }
    //     copy /= 10;
    // }

    while (output.top() == 0){
        output.pop();
    }
    
    while(output.empty() == false){
        cout << output.top();
        output.pop();
    }
    
}
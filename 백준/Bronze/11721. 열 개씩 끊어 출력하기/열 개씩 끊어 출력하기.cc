#include <iostream>

using namespace std;
//BaekjoonOnlineJudge
int main(){
    string str;
    cin >> str;
    int j = 1;
    for(int i = 0; i < str.length(); i++){
        cout << str[i];

        if(j%(10) == 0)
                cout << "\n";
        j++;    
       }
       
}
#include <iostream>
#include <string>
using namespace std;
//구호 SONGDO에 대해 HIGHSCHOOL로 응원.
long long N;
int main(){
    string input;
    cin >> input;
    string strs[4] = {"SONGDO", "CODE", "2023", "ALGORITHM" };
    string ans[4] = {"HIGHSCHOOL", "MASTER", "0611", "CONTEST"};
    for (int i = 0; i < 4; i++){
        if(strs[i] == input)
            cout << ans[i];
    }   
}
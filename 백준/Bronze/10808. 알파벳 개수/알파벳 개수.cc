#include <iostream>
using namespace std;
int main(){
    string str;
    cin >> str;
    int nums[27] = {0,};
    for(int i = 0; i < str.length(); i++){
        nums[str[i] - 'a']++;
    }
    for(int i = 0; i < 26; i++)
            cout << nums[i] << " ";
    
}
#include <iostream>
using namespace std;
int main(){
    string str;
    int characters[27] = {0,};
    int fmax = -1;
    while (cin >> str){
        for(int i= 0 ; i < str.length(); i++){
            if(str[i] == ' ')
               continue;
            characters[str[i] - 'a']++;
            if(characters[str[i] - 'a'] > fmax){
                fmax = characters[str[i] - 'a'];
            }
        }
    }
   
    for(int i = 0 ; i < 26; i++){
        if(characters[i] == fmax){
             cout << (char)(i + 'a');
        }
    }
   
    
}
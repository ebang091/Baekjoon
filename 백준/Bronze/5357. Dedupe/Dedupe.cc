#include <iostream>

using namespace std;
int main(){
    int T;
    cin >> T;
    for(int tc = 0; tc < T; tc++){
        string str;
        cin >> str;
        char prev;
        for(int i = 0; i < str.length(); i++){
            if(i == 0){
                prev = str[i];
                cout << prev;
            }
            else{
                if(prev != str[i]){
                    cout << str[i];
                    prev = str[i];
                }
                
            }
        }
        cout << "\n";
    }
    
}
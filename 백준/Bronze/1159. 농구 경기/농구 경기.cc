#include <iostream>
int N;
using namespace std;
string str;
bool flag = false;
int names[100] = {0,};
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> str;
        names[str[0] - 'a']++;
        
    }
    for(int i = 0 ; i <= 'z' - 'a'; i++){
        if(names[i] >= 5){
            cout << static_cast<char>(i + 'a');
            flag = true;
        }    
    }
    if(!flag)
        cout << "PREDAJA" ;
}
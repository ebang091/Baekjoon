#include <iostream>
using namespace std;
int main(){
    string str;
    while(true){
          cin >> str;
        if(str[0] == '0' && str.length() == 1)
                break;
    int answer = 0;
    for(int i = 0 ; i < str.length(); i++){
        answer += 1;
        if(str[i] ==  '0')
            answer += 4;
        else if(str[i] == '1')
                answer += 2;
        else
              answer += 3;
        }
            cout << answer + 1 << "\n";
    }
  

    
    
}
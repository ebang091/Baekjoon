#include <iostream>
using namespace std;
int main(){
    int n;
    bool success = true;
    for(int i = 0; i < 8; i++){
        cin >> n;
        if(n != 0 && n != 1)
              success = false;
    }
    if(success)
            cout << "S";
    else
           cout << "F";

}
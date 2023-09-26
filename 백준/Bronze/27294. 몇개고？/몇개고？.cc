#include <iostream>
using namespace std;
int a, b;

bool lunch(int a){
    return 12 <= a && a <= 16;
}

int main(){
    cin >> a >> b;
    
    if(b == 1 || !lunch(a))
            cout << "280";
    else
        cout << "320";
}
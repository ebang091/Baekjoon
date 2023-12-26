#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int whiteSpace = i;
        int star = (n - i) * 2 - 1;
        for(int j = 0 ; j < whiteSpace;j++){
            cout << " ";
        }
        for(int j = 0; j < star; j++ ){
            cout <<"*";
        }
        cout << "\n";
    }
}
#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int star = i + 1;
        int whiteSpace = n*2 - star*2;
        for(int j = 0; j < star; j++)
           cout << "*";
        for(int j = 0; j < whiteSpace; j++)
            cout << " ";
        for(int j = 0; j < star; j++)
           cout << "*";
        cout << "\n";
    }
    
    for(int i = 0; i < n-1; i++){
        int star = n - 1 - i;
        int whiteSpace = n*2 - star*2;
        for(int j = 0; j < star; j++)
           cout << "*";
        for(int j = 0; j < whiteSpace; j++)
            cout << " ";
        for(int j = 0; j < star; j++)
           cout << "*";
        cout << "\n";
    }
}
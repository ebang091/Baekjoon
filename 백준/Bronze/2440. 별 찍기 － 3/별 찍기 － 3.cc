#include <iostream>
#include <algorithm>
using namespace std;
int N;
//1 2 3 4 
//4 1 2 3


int main()
{   

    cin >> N;
    for(int i = N; i > 0; i--){
        for(int j = 0; j < i; j++){
            cout << "*";
        }
        cout << "\n";
    }
}
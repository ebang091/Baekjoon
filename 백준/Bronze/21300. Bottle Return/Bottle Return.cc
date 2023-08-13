#include <iostream>
using namespace std;
int main(){
    int n;
    int sum = 0;
    for(int i = 0; i < 6; i++){
        cin >> n;
        sum += n * 5;
    }
    cout << sum;
    
}
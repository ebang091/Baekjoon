#include <iostream>
using namespace std;
int a;
int main() {
    cin >> a;
    int time = 0;
    while(a >= 5){
        a -= 5;
        time++;
    }
    while(a >= 4){
        a -= 4;
        time++;
    }
    while(a >= 3){
        a -= 3;
        time++;
    }
    while(a >= 2){
        a -= 2;
        time++;
    }
     while(a >= 1){
        a -= 1;
        time++;
    }
        
        cout << time;
}
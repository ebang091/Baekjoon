#include <iostream>
using namespace std;
int main(){
    int N;
    cin >> N;
    string str = "WelcomeToSMUPC";
    cout << str[(N-1) % str.size()];
    
}
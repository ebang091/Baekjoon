#include <iostream>

using namespace std;
int main(){
    long long n;
    cin >> n;
    string str;
    cin.ignore();
    for(int i = 1; i <= n; i++){
    	
        getline(cin, str);
        cout << i <<". " << str <<"\n";
    }
}
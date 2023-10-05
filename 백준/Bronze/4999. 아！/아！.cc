#include <iostream>
using namespace std;
string str1, str2;
int main() {
    cin >> str1 >> str2;
    if(str1.length() >= str2.length())
            cout << "go";
    else cout << "no";
}
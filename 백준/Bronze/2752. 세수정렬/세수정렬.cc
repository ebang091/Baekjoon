#include <iostream>
int a,b,c;
using namespace std;
int main() {
    cin >> a >> b >> c;
    int a1,a2,a3;
    if(a > b){
        if(b > c)
            cout << c << " " << b << " " << a;
        else if(c > a)
            cout << b << " " << a << " " << c;
        else
            cout << b << " " << c << " " << a;

    }
    else {
        if(a > c)
             cout << c << " " << a << " " << b ;
        else if(b > c)
             cout << a << " " << c << " " << b;
        else
            cout << a << " " << b << " " << c;
    }
}

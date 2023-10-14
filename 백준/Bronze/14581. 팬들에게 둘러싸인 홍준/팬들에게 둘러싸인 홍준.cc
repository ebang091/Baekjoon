#include <iostream>
/*
:fan::fan::fan:
:fan::appa::fan:
:fan::fan::fan:
*/
using namespace std;
string id;
string fan = ":fan:";
int main(){
    cin >> id;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
                if(i == 1 && j == 1)
                    cout << ":" << id << ":";
        else            cout << fan;

        }
        cout << "\n";
    }
}
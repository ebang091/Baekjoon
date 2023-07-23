/*
어떤 사람의 C언어 성적이 주어졌을 때, 평점은 몇 점인지 출력하는 프로그램을 작성하시오.

A+: 4.3, A0: 4.0, A-: 3.7

B+: 3.3, B0: 3.0, B-: 2.7

C+: 2.3, C0: 2.0, C-: 1.7

D+: 1.3, D0: 1.0, D-: 0.7

F: 0.0

*/
#include <iomanip>
#include <iostream>
using namespace std;


int main(){
    char str[10];
    cin >> str;
    double add = 0;
    if(str[1] != '\0'){
    	add = str[1] == '0' ? 0.0 : str[1] == '+'? 0.3 : -0.3;
		if(str[1] == '0'){
			cout.setf(ios::showpoint);
			cout.precision(2);  
			
		}
    }
    if(str[0] == 'A'){
        cout <<  (double)((double)4.0 + (double)add);
    }else if(str[0] == 'B'){
                cout << (double)3.0 +  (double)add;
    }else if(str[0] == 'C'){
                cout << 2.0 + (double)add;
    }else if(str[0] == 'D'){
                cout << 1.0 + (double)add;
    }else if(str[0] == 'F'){
        cout << "0.0";
    }
    
    
}
#include <iostream>
using namespace std;
long long  N;
int main() {
    cin >> N;
    if(N == 0){
        cout << "1";
        return 0;
    }
          
    int set = 0;
    int setNumber[10] = {0,};
    while (N > 0) {
        int number = N%10;
        if(number == 6 || number == 9){
            if(setNumber[6] < setNumber[9])
                setNumber[6]++;
            else
                setNumber[9]++;
        }
        else{
            setNumber[number]++;
        }
    
         N /= 10;
    }
    
    for(int i = 0; i < 10; i++){
        set = max(set, setNumber[i]);

    }
    cout << set;
}
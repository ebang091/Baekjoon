#include <iostream>
#include <algorithm>
using namespace std;
int N;
//1 2 3 4 
//4 1 2 3

long long A,B;
long long power(int a, int b){
    if(b == 0)
        return 1;
    return a*power(a,b-1);
}
int main()
{   
    cin >> A >> B >> N;
    int nums[1000001];
    if (B == 0)
        return 1;
    long long i = 0;
    int a = A;
    int b = B;
    while(true){
        if(a == 0){
            break;
        }
        
        
        if(a / b == 0){
            nums[i] = 0;
        }
        else {
            nums[i] = a /b;
            a = a%b;
        }
        // cout << "a " << a << " b " << b << " " << nums[i] << "\n";
        a *= 10;
        i++;
        if(i == N+1)
            break;
    }
    cout << nums[N];



    // long double ret = (long double)A/(long double)B;
    // long double copy = ret;
    // unsigned int i = 0;
    // while(true){
    //     copy *= 10;
    //     i++;
    //     if(i == N)
    //         break;
    //     copy -= (long long )(copy);
        
    // }
    // cout << (long long )copy%10;
}
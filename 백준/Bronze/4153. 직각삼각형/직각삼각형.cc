#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <string.h>

using namespace std;
int N,M, K;



int main()
{
    while(1) {
        cin >> N >> M >> K;
     if(!N && !M && !K)
         return 0;
     int first = (N > M)? (N>K? N:K) :(M>K?M:K);
     int sum = 0;
     if(first == N)
     {
         sum += K*K + M*M;
     }
     else if(first == M)
     {
         sum +=  K*K + N*N;
     }
     else
     {
         sum += N*N + M*M;
     }
//     cout << sum << "\n";
    if(first*first == sum)
        cout << "right" << "\n";
    else
        cout << "wrong" << "\n";
    }


}
#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <set>
#include <algorithm>
#include <map>
#include <stack>
#include <cstring>
#include <sstream>
#define FAST cin.tie(NULL); ios::sync_with_stdio(false);
#define all(v) v.begin(), v.end()
#define NONE -1
#define EMPTY ' '
#define INF 2147483647
using namespace std;

int primes[100001] = {0,};
int dividerCount[100001] = {0,};
bool isPrime(int n){

    if(primes[n] == 0)
        return false;
    return true;
    // if(n == 1)
    //     return false;
    // for(int i = 2; i * i <= n; i++){
    //     if(n % i == 0)
    //         return false;
    // }
    // return true;
}

void findPrimes(){
    for(int i = 2; i < 100001; i++){
        primes[i] = i;
    }

    for(int i = 2; i < 100001; i++){
        if(primes[i] == 0)  continue;

        for(int j = 2*i; j < 100001; j+=i){
            primes[j] = 0;
            int currentNum = j;
            while (currentNum% i == 0)//j는 i의 배수. j의 약수의 개수를 i를 통해서 증가시킨다.
            {
                currentNum /= i;
                dividerCount[j]++;
            }
        }
    }
}
int numberOf(int n){

    return dividerCount[n];
    
    
    int copy = n;
    int divider = 2;
    int count = 0;

    while (copy > 0 && divider <= n) {
        if(isPrime(divider)){
            if(copy % divider == 0){
                
            }
            while(copy % divider == 0){
                copy /= divider;
                count++;
            }
        }
        divider++;
    }
    return count;
}

int main(){
    int A, B;
    cin >> A >> B;

    findPrimes();
    int answer = 0;
    for(int i = A; i <= B; i++) {
        if(isPrime(numberOf(i)))
            answer++;
    }
    cout << answer;
}
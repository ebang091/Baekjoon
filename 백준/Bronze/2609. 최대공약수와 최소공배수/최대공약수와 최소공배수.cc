#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <string.h>

using namespace std;
int N,M;

int gcd(int a, int b)
{
    return b == 0? a : gcd(b, a%b);
}

int main()
{
    cin >> N >> M;
    cout << gcd(N,M) << "\n";
    cout << N*M/gcd(N,M) << "\n";


}
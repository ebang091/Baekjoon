#include <unistd.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector <char> ans;
vector <pair<string, int> > word;
int alpha[27];

bool isPrime(int n)
{
    if(n == 1)
        return false;
    for(int i=2;i*i<=n;i++)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T,a,b;
    int n, i = 0,diff;

    cin >> T;
    for(int j=0;j<T;j++) {
        cin >> n;
        diff = 19876543;
        i = 1;
        while (i <= n / 2) {
            if(isPrime(i) && isPrime(n-i))
            {
                if(n - 2*i <= diff)
                {
                    a = i, b = n-i, diff = n - 2*i;
                }
            }
                i++;
        }
        cout << a << " " ;
        cout << b << "\n";
    }
}
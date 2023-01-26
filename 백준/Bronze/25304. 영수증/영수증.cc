#include <unistd.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int n, cash;
    cin >> cash;
    cin >> n;
    int a,b;
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        cin >> a>>b;
        sum += a*b;

    }
    if(sum == cash)
        cout <<"Yes";
    else
        cout <<"No";

}
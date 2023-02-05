#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
vector <pair <int, int> > comb;

int K,N,M;


int main()
{
    cin >> N ;
    for(int i=2;i<=N;i++)
    {

        while(N%i == 0)
        {
            cout << i<<"\n";
            N /= i;
        }
    }

}

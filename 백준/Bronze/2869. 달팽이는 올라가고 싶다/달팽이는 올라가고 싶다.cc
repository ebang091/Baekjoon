#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
   int a,b,v;
   cin >> a>>b>>v;
   int h = v - a;
   int ans = h/(a-b);
   if(h%(a-b) > 0)
       ans++;
   cout << ans+ 1;
}
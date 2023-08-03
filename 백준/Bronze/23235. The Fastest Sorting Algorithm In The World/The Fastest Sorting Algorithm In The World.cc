#include <iostream>
using namespace std;

int main(){
    int n;
    long long cnt = 0;
    int k;
    while (true)
    {
        cin >> n;

        if(n == 0)
            break;    
        for(int i = 0; i < n; i++)
            cin >> k;

        cout << "Case " << ++cnt << ": Sorting... done!\n";
    }
}
    
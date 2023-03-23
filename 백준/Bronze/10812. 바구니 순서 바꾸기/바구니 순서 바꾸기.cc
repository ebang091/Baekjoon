#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int bu[101];
int main()
{
    int copy[101] ,a ,b, k;
    cin >> N >> M;
    for (int i = 1; i <= N ; i++)
        bu[i] = i;

    for(int i = 0; i < M; i++) {
        cin >> a >> b >> k;
//        cout << a << " " << b << " " << k << "\n";
        for(int j = a ; j <= b; j++)
            copy[j] = bu[j];

        /*
         *a      k   b
         * 1 2 3 4 5 6
         *
         * 4 5 6 1 2 3
         *
         */
        for(int j = 0; j <= (b - k); j++) {
            bu[a + j] = copy[k + j];
        }
        for(int j = 0; j < (k - a); j++)
            bu[a + (b- k + 1) + j] = copy[a + j];
//        for (int i = 1; i <= N ; i++)
//            cout << bu[i] << " ";
//        cout <<"\n";
    }
    for (int i = 1; i <= N ; i++)
        cout << bu[i] << " ";
}

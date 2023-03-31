#include <iostream>
#include <vector>
using namespace std;
vector <int> S;


int main() {

    int y[3], x[3], y3, x3;

    for (int i = 0; i < 3; i++)
        scanf("%d %d", &y[i], &x[i]);
    if (y[0] == y[1])
        y3 = y[2];
    else if(y[1] == y[2])
        y3 = y[0];
    else
        y3 = y[1];


    if (x[0] == x[1])
        x3 = x[2];
    else if(x[1] == x[2])
        x3 = x[0];
    else
        x3 = x[1];

    printf("%d %d", y3, x3);

}
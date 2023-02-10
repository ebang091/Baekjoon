#include <unistd.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int map[10][10];

int main()
{
    int n;
    int max = -1;
    int pos_x, pos_y;
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            cin >> n;
            map[i][j] = n;
            if(n > max)
            {
                max =n, pos_y = i, pos_x = j;
            }
        }
    }
    cout << max << "\n" << pos_y << " " << pos_x;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <string.h>

using namespace std;
int N;
int g[1000001];

void input()
{
    for(int i=0;i<N;i++)
        cin >> g[i];
}
void print()
{
    for(int i=0;i<N;i++)
        cout << g[i] << "\n";

}
int main()
{
    cin >> N;
    input();
    sort(g,g+N);
    print();


}
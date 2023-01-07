#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
string str[20000];

void input()
{
    for(int i=0;i<N;i++)
       cin >> str[i];
}

int sorted(string a, string b)
{
    if(a.length() == b.length())
        return a < b;
    else
        return a.length() < b.length();
}

void print()
{
    for(int i=0;i<N;i++)
    {
        if(i!=0)
            if(str[i] == str[i-1])
                continue;
        cout << str[i] << "\n";
    }

}

int main()
{

    scanf("%d", &N);
    input();
    sort(str, str+N, sorted);
    print();



}
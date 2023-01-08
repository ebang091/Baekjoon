#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <stack>

using namespace std;
int N;
stack <char> s;

int isVPS(char *str)
{
    while (*str)
    {
        if (*str == '(')
            s.push('(');
        else if(*str == ')')
        {
            if(s.size() && s.top() == '(')
                s.pop();
            else
                return false;
        }
        str++;
    }
    if(s.size())
        return false;
    return true;
}

void init()
{
    while(!s.empty())
        s.pop();
}
void check()
{
    char str[51];
    for(int i=0;i<N;i++)
    {
        cin >> str;
        init();
        if(isVPS(str))
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
}
int main()
{
    cin >> N;
    check();
}
#include <unistd.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

int N;
using namespace std;
//vector <pair< pair<string, int>, int> >  num;
vector <string> num;
long long selected[27][2]; //각 알파벳의 자릿수합 과 값을 저장할 것임.

long long square(int n, int r)
{
    if(r == 0)
        return 1;
    return square(n , r-1)*n;
}

void input()
{
    string str;
    for(int i=0;i<N;i++)
    {
        cin >> str;
        num.push_back(str);
        for(int j=0;j<str.length();j++)
        {
            selected[str[j] - 'A'][0] += square(10, str.length()-j-1);
        }
    }

    for(int i=0;i<27;i++)
        selected[i][1] = -1;
}

int findmax() //최대 합을 가진 알파벳을 아직 값을 안 정한 알파벳중에서 골라서 반환
{
    long long max = -1;
    int idx = 0;
    for(int i=0;i<27;i++)

        if(selected[i][1] == -1 && selected[i][0] > 0)//값이 안정해지고 input에는 존재하는 알파벳일 경우 후보. (다 채우고 없으면 max == -1)
        {
            if(selected[i][0] > max)//매번 갱신: 0이상의 값이기때문에 놓치지는 않음
            {
                max = selected[i][0];
                idx = i;
            }
        }

    if(max == -1)
        return -1;
    return idx;
}

void solve()
{
    int n = 9;
    int cnt=  0;
    while(1)
    {
        int alpha = findmax();
//        cout << alpha <<"\n";
        if(alpha != -1) {
            selected[alpha][1] = n;
//            cout << (char)(alpha + 'A') << " : " << selected[alpha][0]  << " "<<n<< "\n";
            n--;

        }
        else
            break;
    }

    unsigned long long sum = 0;
    for(int i=0;i<N;i++)
    {
        string str = num[i];
        long long tmp = 0;
        for(int j=0;j<str.length();j++)
        {
            tmp = tmp * 10 +  selected[str[j]- 'A'][1];
//            cout << tmp <<"\n";
        }
        sum += tmp;
    }
    cout << sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    input();
    solve();//각 알파벳이 의미하는 값 찾기.
}

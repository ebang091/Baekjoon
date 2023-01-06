#include <iostream>
#include <vector>

/*
 *  A+B, A-B, A*B, A/B(몫), A%B(나머지)를 출력하는 프로그램을 작성하시오.
 */

using namespace std;
vector <int> num(9);

int main()
{
    int N;
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N-i;j++)
            cout << " ";
        for(int j=1;j<=i;j++)
            cout <<'*';
        cout << "\n";
    }


}


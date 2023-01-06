#include <iostream>
#include <vector>

/*
 *  A+B, A-B, A*B, A/B(몫), A%B(나머지)를 출력하는 프로그램을 작성하시오.
 */

using namespace std;
vector <int> num(9);

int main()
{
    int N,M;

    while(cin >> N >> M)
    {
        //if (cin.eof())
          //  return 0;
        cout << N + M << "\n";
    }
}


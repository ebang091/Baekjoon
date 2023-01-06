#include <iostream>
#include <vector>

/*
 *  A+B, A-B, A*B, A/B(몫), A%B(나머지)를 출력하는 프로그램을 작성하시오.
 */

using namespace std;
vector <int> num(4);
vector <int> number(10);

void check(long long ret)
{
    long long copy = ret;
    while(copy)
    {
        number[copy%10] += 1;
        copy /=10;
    }
}

int main()
{
    long long ret = 1;
    for(int i=1;i<=3;i++) {
        cin >> num[i];
        ret *= num[i];
    }
    check(ret);
    for(int i=0;i<=9;i++)
        cout << number[i] << "\n";

}


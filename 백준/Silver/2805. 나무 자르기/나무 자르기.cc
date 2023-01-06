#include <iostream>
#include <vector>

/*
 *  A+B, A-B, A*B, A/B(몫), A%B(나머지)를 출력하는 프로그램을 작성하시오.
 */
using namespace std;
vector <int> t;
vector <int> number;

using namespace std;
long long tree, target;
long long MIN = 2147483647, MAX = 0;

long long  cutted(int height)
{
    long long  ret= 0;
    for(int i=1;i<=tree;i++)
    {
        if(t[i] > height)
            ret += t[i] - height;
    }
    return ret;
}

long long  find(long long l, long long r)
{
    long long mid;
    long long ret = 0;
    while(l<=r)
    {
        mid = (l+r)/2;
        if(cutted(mid) >= target)
        {
            ret = mid;
            l = mid+1;
        }
        else
            r = mid-1;

    }
//    cout << ret << "\n";
    return ret;
}

void init_number()
{
    for (int i=0;i<=MAX;i++) {
        number[i] = i;
//        printf("%d ", number[i]);
    }
    printf("\n");
}

int main()
{
    cin >> tree >> target;
    t.resize(tree + 1, 0);
    for(int i=1;i<=tree;i++) {
        cin >> t[i];
        if(MIN > t[i])
            MIN = t[i];
        if(MAX < t[i])
            MAX = t[i];
    }
//    number.resize(MAX+1);
//    init_number();
//    cout << (MAX+MIN)/2 ;

    printf("%lld\n", find(0, MAX));





}


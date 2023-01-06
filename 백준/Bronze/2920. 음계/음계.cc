#include <iostream>
#include <vector>

#define MIXED "mixed"
#define ASC "ascending"
#define DSC "descending"

using namespace std;
vector <int> num(9);

string check()
{
    if(num[1] < num[2])//오름차순인지 확인
    {
        for(int i=1;i<=7;i++)
    {
        if(num[i] > num[i+1])
            return MIXED;

    }
        return ASC;
    }
    else
    {
        for(int i=1;i<=7;i++)
        {
            if(num[i] < num[i+1])
                return MIXED;

        }
        return DSC;
    }


}
int main()
{
    for(int i=1;i<=8;i++)
        cin >> num[i];

    cout << check() << "\n";
    return 0;
}


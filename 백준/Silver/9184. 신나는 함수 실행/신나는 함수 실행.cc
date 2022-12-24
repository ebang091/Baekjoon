#include <stdio.h>
#include <stdlib.h>

long long w[21][21][21];

//if a < b and b < c, then w(a, b, c) returns:
//    w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)
//w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)
void prepare()
{
    for(int i=0;i<21;i++)
    {
        for(int j=0;j<21;j++)
        {
            for(int k=0;k<21;k++)
            {
               w[i][j][k] = 0;
            }
        }
    }

}

long long func(int i, int j, int k)
{
    if(i<=0|| j<=0||k<=0)
    {
        return 1;
    }
    else if(i > 20 || j > 20 || k >20)
        return func(20,20,20);
    if(w[i][j][k] != 0)
        return w[i][j][k];
    if (i < j && j < k) {
        w[i][j][k] = func(i, j, k - 1) + func(i, j - 1, k - 1) - func(i, j - 1, k);
        return w[i][j][k];
    }
    w[i][j][k] = (func(i - 1, j, k) + func(i - 1, j - 1, k) + func(i - 1, j, k - 1) -
                func(i - 1, j - 1, k - 1));
    return w[i][j][k];


}

int main()
{
    int a,b,c;
    prepare();
    while(1) {
        scanf("%d %d %d", &a, &b, &c);
        if (a == -1 && b == -1 && c == -1)
            break;
       printf("w(%d, %d, %d) = %lld\n", a,b,c,func(a,b,c));
    }
    return 0;
}
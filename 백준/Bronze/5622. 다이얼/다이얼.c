#include <stdio.h>

/*                         15161718 192021 22232425
 * ABC DEF   GHI JKL   MNO   PQRS   TUV  WXYZ
 *  2    3    4   5     6     7      8     9
 * 012   345  678  91011 121314
 */
int press(int n)
{
    return n+3;
}

int press_time(char *num)
{
    int     i;
    int     time;

    i = 0;
    time = 0;
    char *str[100] = {"ABC\0", "DEF\0", "GHI\0", "JKL\0", "MNO\0", "PQRS\0", "TUV\0", "WXYZ\0"};
    int j,k,n;
    while(num[i] != '\0')
    {
        n = -1;
        for(k = 0; k < 8; k++)
        {
            j = 0;
            while(str[k][j] != '\0')
            {
                if (str[k][j] == num[i]) {
                    n = k;
                    break;
                }
                j++;
            }

        }
        if(n != -1) {
            time += press(n);
        }

        i++;
    }

    return time;
}



int main()
{
    char num[16];
    scanf("%s", num);
    //각 문자를 숫자로 변환.
    //숫자를 구하면 각 숫자 +1 을 하면 누르는데 걸리는 시간이 나온다.
    int time = press_time(num);
    if(time == 0)
        return 0;
    printf("%d", time);


}
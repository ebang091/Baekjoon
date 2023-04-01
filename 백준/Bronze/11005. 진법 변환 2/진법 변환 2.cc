#include <stdio.h>

void ft_putnbr(int num, int base)
{
    char str[100] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if(num >= base)
           ft_putnbr(num/base , base);
    printf("%c", str[num%base]);
}
int main()
{
   
     int num;
    int base;
    scanf("%d %d", &num, &base);
    ft_putnbr(num, base);
}
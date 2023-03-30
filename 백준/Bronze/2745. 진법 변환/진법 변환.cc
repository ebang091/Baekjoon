#include <stdio.h>
#include <string.h>


int main()
{
    char str[100];
    int base;
    scanf("%s %d", str, &base);
    // int i  = 0;
    long long  sum = 0;
    long long b = 1;
    long long  len = strlen(str)- 1;
    while (len >= 0)
    {
    	if('0' <= str[len] && str[len] <= '9' )
    		sum +=  (str[len] - '0')*b;
    	else
    		sum += (str[len] - 'A' + 10) * b;
    	b *= base;
    	// printf("%lld\n", sum);
    	len--;
    }
    printf("%lld", sum);
}
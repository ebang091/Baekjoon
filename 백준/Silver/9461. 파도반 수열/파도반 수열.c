#include <stdio.h>

unsigned long long answer[102];

// long long func(int n)
// {



// }

int main()
{
    int T;
    int n;
    
    answer[1] = 1;
    answer[2] = 1;
    answer[3] = 1;
    for(int i=4;i<102;i++)
    {
        answer[i] = answer[i-3] + answer[i-2];
        // printf("%lld, ", answer[i]);
    }
    // printf("\n");
    scanf("%d", &T);
    for(int i=0;i<T;i++)
    {
        scanf("%d", &n);
        // if(n < 79)
            printf("%llu\n", answer[n]);
        // else
        //     printf("%u\n", answer[n]);

    }
}
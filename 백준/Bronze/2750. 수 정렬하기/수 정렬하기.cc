#include <stdio.h>

int N;
int nums[1001];

int main()
{
    int n;
    scanf("%d", &N);
    for(int i=0;i<N;i++)
    {
        scanf("%d", &n);
        nums[i] = n;
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N-i-1;j++)
        {
            if(nums[j] > nums[j+1])
            {
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }
     for(int i=0;i<N;i++)
         printf("%d\n", nums[i]);
}
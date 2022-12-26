#include <stdio.h>
#include <string.h>

int nums[1001];


int main()
{
   int T,N;
   int sum,count;
   double avg;

   scanf("%d", &T);
   for(int i=0;i<T;i++)
   {
       scanf("%d", &N);
       sum = 0;
       count = 0;
       for(int i=0;i<N;i++)
           scanf("%d", &nums[i]);
       for(int i=0;i<N;i++)
           sum+=nums[i];
       avg = (double)sum/N;
       for(int i=0;i<N;i++){
           if(nums[i] > avg)
               count++;
       }
       printf("%.3f%%\n", (float)count/(float)N*100);
   }
}
#include <stdio.h>

int main()
{
    int hour, minute;
    int time;
    scanf("%d %d", &hour, &minute);
    scanf("%d", &time);
    //59 , 60. 119
    //30 80     110 1: 50
    minute += time;
    if (minute >= 60)
    {
        hour += minute/60;
        minute = minute%60;
    }
    if(hour >= 24)
        hour -= 24;
    printf("%d %d", hour, minute);
}
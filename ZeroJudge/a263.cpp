#include <stdio.h>

int monthday[13] = {0,0,31,59,90,120,151,181,212,243,273,304,334};

int CountDay(int year, int month, int day)
{
    int isleap;
    int leaps;

    isleap = (year%4==0 && year%100!=0) || year%400==0;

    year--;
    leaps = year/4 - year/100 + year/400;

    return (year*365+leaps) + (monthday[month]+((month>2)?isleap:0)) + day;
}

int main ()
{
    int i;
    int y1,m1,d1;
    int y2,m2,d2;
    int         gap;

    while(scanf("%d %d %d",&y1,&m1,&d1)==3)
    {
        scanf("%d %d %d",&y2,&m2,&d2);

           gap= CountDay(y1,m1,d1) - CountDay(y2,m2,d2);

        printf("%d\n",gap>-1?gap:-gap);
    }

    return 0;
}
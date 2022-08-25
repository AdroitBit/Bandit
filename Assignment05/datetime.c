#include<stdio.h>
/*
2700000
24 february 2020

*/

typedef struct datetime {
    int date;           //1-31
    int month;          //1-12
    int year;           //1970++
    int dayOfWeek;      //0-6
    int hour;           //0-23
    int minute;         //0-59
    int second;         //0-59
} datetime_t;


int dayofweek(int d, int m, int y){
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    y -= m < 3;
    return ( y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}
int isleap(int y){
    return (y%4==0 && y%100!=0) || y%400==0;
}

datetime_t createDate(unsigned int timestamp) {
    datetime_t date;
    date.second=timestamp%60;   
    date.minute=timestamp/60%60;
    date.hour=timestamp/3600%24;

    date.year=timestamp/31556926+1970;
    
    printf("fuck");


    int days=timestamp/86400;
    date.month=1;
    date.date=1;
    date.dayOfWeek=(4+days)%7+1;
    int year_i=1970;
    for(year_i=1970;1;++year_i){
        if(days<365+isleap(year_i)){
            break;
        }else{
            days-=365+isleap(year_i);
        }
    }
    date.year=year_i;
    


    int months_days[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    months_days[2]=isleap(date.year)?29:28;

    while(days>0){
        int month_days=months_days[date.month];
        if(days>month_days){
            days-=month_days;
            date.month++;
        }
        if(days<month_days){
            date.date+=days;
            break;
        }
    }

    //date.dayOfWeek=dayofweek(date.date,date.month,date.year);
    

    return date;
}



void printDate(datetime_t d) {
    char* months[]={"NUL","JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
    char* days[]={"NUL","Sun","Mon","Tue","Wed","Thu","Fri","Sat"};

    printf("%s %d %s %d %02d:%02d:%02d\n",days[d.dayOfWeek],d.date,months[d.month],d.year, d.hour, d.minute, d.second);
}

int main() {
    datetime_t inputDate;
    unsigned int timestamp;

    scanf("%lu", &timestamp);
    inputDate = createDate(timestamp);
    printDate(inputDate);
    return 0;
}
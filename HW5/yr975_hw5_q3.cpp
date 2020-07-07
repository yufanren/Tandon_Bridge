//
// Created by yufanren on 2/7/20.
//
#include <iostream>
using namespace std;

int printMonthCalender(int numOfDays, int startingDay);
bool isLeapYear(int year);
void printYearCalender(int year, int startingDay);

int main() {
    int year, startDay;
    cout<<"Please input the year for which you want the calender: "<<endl;
    cin>>year;
    cout<<"which day of the week does this year start on? Please enter integer 1 through 7: "<<endl;
    cin>>startDay;
    printYearCalender(year, startDay);
    return 0;
}

void printYearCalender(int year, int startingDay) {
    int startDayNext, daysFeb;
    if (isLeapYear(year))
        daysFeb = 29;
    else
        daysFeb = 28;
    cout<<"\nJanuary\t"<<year<<endl;
    startDayNext = printMonthCalender(31, startingDay) + 1;
    cout<<"\nFeburary\t"<<year<<endl;
    startDayNext = printMonthCalender(daysFeb, startDayNext) + 1;
    cout<<"\nMarch\t"<<year<<endl;
    startDayNext = printMonthCalender(31, startDayNext) + 1;
    cout<<"\nApril\t"<<year<<endl;
    startDayNext = printMonthCalender(30, startDayNext) + 1;
    cout<<"\nMay\t"<<year<<endl;
    startDayNext = printMonthCalender(31, startDayNext) + 1;
    cout<<"\nJune\t"<<year<<endl;
    startDayNext = printMonthCalender(30, startDayNext) + 1;
    cout<<"\nJuly\t"<<year<<endl;
    startDayNext = printMonthCalender(31, startDayNext) + 1;
    cout<<"\nAugust\t"<<year<<endl;
    startDayNext = printMonthCalender(31, startDayNext) + 1;
    cout<<"\nSeptember\t"<<year<<endl;
    startDayNext = printMonthCalender(30, startDayNext) + 1;
    cout<<"\nOctober\t"<<year<<endl;
    startDayNext = printMonthCalender(31, startDayNext) + 1;
    cout<<"\nNovember\t"<<year<<endl;
    startDayNext = printMonthCalender(30, startDayNext) + 1;
    cout<<"\nDecember\t"<<year<<endl;
    startDayNext = printMonthCalender(31, startDayNext) + 1;
}

bool isLeapYear(int year) {
    bool leapYear;
    if (year % 400 == 0)
        leapYear = true;
    else
        leapYear = year % 4 == 0 && year % 100 != 0;
    return leapYear;
}

int printMonthCalender(int numOfDays, int startingDay) {
    cout<<"Mon\tTue\tWed\tThr\tFri\tSat\tSun"<<endl;
    int dayInWeek, dateInMonth;
    if (startingDay > 7)
        startingDay %= 7;
    for (dateInMonth = -1 * (startingDay - 2), dayInWeek = 1; dateInMonth <= numOfDays; dateInMonth++, dayInWeek++) {
        if (dayInWeek == 8) {
            dayInWeek = 1;
            cout<<endl;
        }
        if (dateInMonth < 1)
            cout<<" ";
        else
            cout<<dateInMonth;
        cout<<"\t";
    }
    cout<<endl;
    return dayInWeek - 1;
}
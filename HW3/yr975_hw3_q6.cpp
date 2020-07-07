//
// Created by yufanren on 1/25/20.
//
#include <iostream>
#include <string>
using namespace std;

const double WEEKEND = 0.15, WEEKDAY_LOW = 0.25, WEEKDAY_HIGH = 0.4;
int main() {
    string dayInWeek;
    int hourCall, minCall, lengthCall;
    char temp;
    double costTotal;
    cout<<"Please enter the day which phone call started: ";
    cin>>dayInWeek;
    cout<<"Please enter the time phone call started: ";
    cin>>hourCall>>temp>>minCall;
    cout<<"Please enter the how long the call lasted (in minutes): ";
    cin>>lengthCall;
    if (dayInWeek == "Sa" || dayInWeek == "Su")
        costTotal = lengthCall * WEEKEND;
    else if (dayInWeek == "Mo" || dayInWeek == "Tu" || dayInWeek == "We" || dayInWeek == "Th" || dayInWeek == "Fr" ){
        if (hourCall < 8 || hourCall > 17)
            costTotal = lengthCall * WEEKDAY_LOW;
        else
            costTotal = lengthCall * WEEKDAY_HIGH;
    }
    else {
        cout<<"Illegal day entry!"<<endl;
        return 0;
    }
    cout<<"The total cost of the phone call is: $"<<costTotal<<endl;
    return 0;
}

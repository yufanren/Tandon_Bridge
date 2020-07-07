//
// Created by yufanren on 1/24/20.
//
#include <iostream>
#include <string>

using namespace std;

int main() {
    int yearCurrent, yearGraduate, statusStudent;
    string studentName;
    cout<<"Please enter your name: ";
    cin>>studentName;
    cout<<"Please enter your graduation year: ";
    cin>>yearGraduate;
    cout<<"Please enter current year: ";
    cin>>yearCurrent;
    statusStudent = yearGraduate - yearCurrent;
    if (statusStudent > 4)
        cout<<studentName<<", you are not in college yet";
    else if (statusStudent == 4)
        cout<<studentName<<", you are a Freshman";
    else if (statusStudent == 3)
        cout<<studentName<<", you are a Sophomore";
    else if (statusStudent == 2)
        cout<<studentName<<", you are a Junior";
    else if (statusStudent == 1)
        cout<<studentName<<", you are a Senior";
    else
        cout<<studentName<<", you are Graduated";
    return 0;
}

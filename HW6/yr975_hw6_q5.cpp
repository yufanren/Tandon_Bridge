//
// Created by yufanren on 2/15/20.
//
#include <iostream>
using namespace std;

int main() {
    string firstName, middleName, lastName, nameFinalFormat;
    cout<<"Please enter your full name(first name, middle name then last name, separated by space): \n";
    cin>>firstName>>middleName>>lastName;
    nameFinalFormat = lastName + ", " + firstName + " " + middleName[0] +".";
    cout<<endl<<nameFinalFormat<<endl;
    return 0;
}

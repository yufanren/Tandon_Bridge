//
// Created by yufanren on 1/25/20.
//
#include <iostream>
using namespace std;

const double KG_PER_POUND = 0.453592, METER_PER_INCH = 0.0254;
int main() {
    double weightBMI, heightBMI, massIndex;
    cout<<"Please enter weight (in pounds): ";
    cin>>weightBMI;
    cout<<"please enter height (in inches): ";
    cin>>heightBMI;
    massIndex = weightBMI * KG_PER_POUND / (heightBMI * METER_PER_INCH * heightBMI * METER_PER_INCH);
    if (massIndex < 18.5)
        cout<<"The weight status is: Underweight"<<endl;
    else if (massIndex < 25)
        cout<<"The weight status is: Normal"<<endl;
    else if (massIndex < 30)
        cout<<"The weight status is: Overweight"<<endl;
    else
        cout<<"The weight status is: Obese"<<endl;
    return 0;
}

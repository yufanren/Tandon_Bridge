//
// Created by yufanren on 2/1/20.
//
#include <iostream>
using namespace std;

int main() {
    int num;
    cout<<"Please enter a positive number n for a nxn multiplication table: "<<endl;
    cin>>num;
    //determine how much space the highest number in the table needs. for formatting purposes.
    //Pad each number in table with highest numbers' digit# blanks minus current numbers' length plus 1.
    int numHighest = num * num, numDigits = 1;
    while (numHighest) {
        numDigits++;
        numHighest /= 10;
    }
    for (int axiesX = 1; axiesX <=num; axiesX++) {
        for (int axiesY = 1; axiesY <=num; axiesY++) {
            int numCurrent = axiesX * axiesY, numLength = 0;
            cout<<numCurrent;
            while (numCurrent) {
                numLength++;
                numCurrent /= 10;
            }
            for (int blankLength = 0; blankLength < numDigits - numLength; blankLength++) {
                cout<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}

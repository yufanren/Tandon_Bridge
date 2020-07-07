//
// Created by yufanren on 2/1/20.
//
#include <iostream>
using namespace std;

int main() {
    int num;
    cout<<"Please enter a positive integer: ";
    cin>>num;
    for (int countToNum = 1; countToNum <= num; countToNum++) {
        int countEven = 0, countOdd = 0, numCurrent = countToNum;
        while (numCurrent > 0) {
            if (numCurrent % 2 == 0) {
                countEven++;
            }
            else {
                countOdd++;
            }
            numCurrent /= 10;
        }
        if (countEven > countOdd) {
            cout<<countToNum<<endl;
        }
    }
    return 0;
}


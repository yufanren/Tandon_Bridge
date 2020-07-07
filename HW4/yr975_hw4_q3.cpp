//
// Created by yufanren on 1/31/20.
//
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int num, numBinary = 0;
    cout<<"Enter decimal number: "<<endl;
    cin>>num;
    int numTemp = num, digitCounter = 0;
    while (numTemp > 0) {
        numBinary += (numTemp % 2) * pow(10, digitCounter);
        numTemp /= 2;
        digitCounter++;
    }
    cout<<"The binary representation of "<<num<<" is "<<numBinary<<endl;
    return 0;
}

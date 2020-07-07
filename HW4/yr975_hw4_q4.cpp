//
// Created by yufanren on 1/31/20.
//
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int numEntry, productTotal, entry;
    double meanGeometric;
    cout<<"section a"<<endl;
    productTotal = 1;
    cout<<"Please enter the length of the sequence: ";
    cin>>numEntry;
    for (int counterEntry = 1; counterEntry <= numEntry; counterEntry++) {
        cin>>entry;
        productTotal *= entry;
    }
    meanGeometric = pow(productTotal, (1 / (double) numEntry));
    cout<<"The geometric mean is: "<<meanGeometric<<endl;
    cout<<"section b"<<endl;
    productTotal = 1;
    numEntry = 0;
    cout<<"Please enter a non-empty sequence of positive integers, each one in a separate line. End your\n"
          "sequence by typing -1:"<<endl;
    bool endSeq = false;
    while (!endSeq) {
        cin>>entry;
        if (entry == -1) {
            endSeq = true;
        } else {
            productTotal *= entry;
            numEntry++;
        }
    }
    meanGeometric = pow(productTotal, (1 / (double) numEntry));
    cout<<"The geometric mean is: "<<meanGeometric<<endl;
    return 0;
}

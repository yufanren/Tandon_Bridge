//
// Created by yufanren on 1/31/20.
//
#include <iostream>
using namespace std;

const int FIRST_INT = 2;
int main() {
    int num;
    cout<<"Please enter a positive integer: ";
    cin>>num;
    cout<<"\nsection a\n";
    int numCounter = 1, evenCurrent = FIRST_INT;
    while (numCounter <= num) {
        cout<<evenCurrent<<endl;
        evenCurrent +=2;
        numCounter++;
    }
    cout<<"\nsection b\n";
    for (numCounter = 1, evenCurrent = FIRST_INT; numCounter <= num; numCounter++) {
        cout<<evenCurrent<<endl;
        evenCurrent += 2;
    }
    return 0;
}

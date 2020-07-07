//
// Created by yufanren on 2/7/20.
//
#include <iostream>
using namespace std;

int fib(int n);

int main() {
    int num;
    cout<<"Please enter a positive integer: ";
    cin>>num;
    cout<<fib(num)<<endl;
    return 0;
}

int fib(int n) {
    int fibCurrent = 1, fibPrevious = 1, temp;
    for (int counter = 3; counter <= n; counter++) {
        temp = fibCurrent;
        fibCurrent += fibPrevious;
        fibPrevious = temp;
    }
    return fibCurrent;
}
//
// Created by yufanren on 2/7/20.
//
#include <iostream>
#include <cmath>
using namespace std;

void printDivisors(int num);

int main() {
    int num;
    cout<<"Please enter a positive integer >= 2: ";
    cin>>num;
    printDivisors(num);
    return 0;
}

void printDivisors(int num) {
    double sqrtNum = sqrt(num);
    for (int i = 1; i <= sqrtNum; i++) {
        if (num % i == 0) {
            cout<<i<<"\t";
        }
    }
    if ((int) sqrtNum * (int) sqrtNum == num) {
        sqrtNum -= 1;
    }
    for (int j = sqrtNum; j >= 1; j--) {
        if (num % j == 0) {
            cout<<num / j<<"\t";
        }
    }
    cout<<endl;
}
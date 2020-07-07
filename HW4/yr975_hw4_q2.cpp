//
// Created by yufanren on 1/31/20.
//
#include <iostream>
using namespace std;

int main() {
    int num;
    cout<<"Enter decimal number:\n";
    cin>>num;
    cout<<num<<" is ";
    if (num < 0) {
        num *= -1;
        cout<<"-";
    }
    while (num >= 1000) {
        cout<<"M";
        num -= 1000;
    }
    while (num >= 500) {
        cout<<"D";
        num -= 500;
    }
    while (num >= 100) {
        cout<<"C";
        num -= 100;
    }
    while (num >= 50) {
        cout<<"L";
        num -= 50;
    }
    while (num >= 10) {
        cout<<"X";
        num -= 10;
    }
    while (num >= 5) {
        cout<<"V";
        num -= 5;
    }
    while (num > 0) {
        cout<<"I";
        num--;
    }
    return 0;
}

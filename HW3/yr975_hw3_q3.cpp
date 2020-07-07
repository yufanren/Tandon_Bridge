//
// Created by yufanren on 1/24/20.
//
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double parameterA, parameterB, parameterC;
    cout<<"Please enter value of a: ";
    cin>>parameterA;
    cout<<"Please enter value of b: ";
    cin>>parameterB;
    cout<<"Please enter value of c: ";
    cin>>parameterC;
    if (parameterA == 0) {
        if (parameterB == 0) {
            if (parameterC == 0)
                cout<<"This equation has infinite number of solutions"<<endl;
            else
                cout<<"This equation has no solution"<<endl;
        }
        else
            cout<<"This equation has a single solution x="<<(parameterC / parameterB) * -1<<endl;
    }
    else {
        double numSolutionChecker = parameterB * parameterB - 4 * parameterA * parameterC;
        if (numSolutionChecker == 0)
            cout<<"This equation has a single solution x="<<parameterB / (2 * parameterA) * -1<<endl;
        else if (numSolutionChecker < 0)
            cout<<"This equation has no real solution"<<endl;
        else
            cout<<"This equation has two real solutions x="<<(-1 * parameterB - sqrt(numSolutionChecker)) / (2 *
            parameterA)<<" and x="<<(-1 * parameterB + sqrt(numSolutionChecker)) / (2 * parameterA)<<endl;
    }
    return 0;
}

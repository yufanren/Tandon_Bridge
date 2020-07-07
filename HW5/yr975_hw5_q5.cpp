//
// Created by yufanren on 2/7/20.
//
#include <iostream>
#include <cmath>
using namespace std;

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs);
bool isPerfect(int num);

int main() {
    int num;
    cout<<"Please enter a positive integer M (>=2): "<<endl;
    cin>>num;

    cout<<"All perfect numbers between 2 and M are: "<<endl;
    for (int i = 2; i <= num; i++) {
        if (isPerfect(i)) {
            cout<<i<<endl;
        }
    }

    cout<<"\nAll amicable numbers between 2 and M are: "<<endl;
    for (int j = 2; j <= num; j++) {
        int countDivs = 1, sumDivs = 1, countDivsComp = 1, sumDivsComp = 1;
        analyzeDividors(j, countDivs, sumDivs);
        analyzeDividors(sumDivs, countDivsComp, sumDivsComp);
        if (j < sumDivs && sumDivsComp == j && sumDivs < num) {
            cout<<j<<"\tand\t"<<sumDivs<<endl;
        }
    }
    return 0;
}

bool isPerfect(int num) {
    int countDivs = 1, sumDivs = 1;
    analyzeDividors(num, countDivs, sumDivs);
    return num == sumDivs;
}

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs) {
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            if (num / i == i) {
                outCountDivs += 1;
                outSumDivs += i;
            }
            else {
                outCountDivs += 2;
                outSumDivs += i + num / i;
            }
        }
    }
}
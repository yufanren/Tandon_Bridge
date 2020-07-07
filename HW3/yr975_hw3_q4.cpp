//
// Created by yufanren on 1/25/20.
//
#include <iostream>
using namespace std;

const int FLOOR_ROUND = 1, CEILING_ROUND = 2, ROUND = 3;
int main() {
    double numToRound;
    int optionRound;
    cout<<"Please enter a Real number:"<<endl;
    cin>>numToRound;
    cout<<"Choose your rounding method:\n1. Floor round\n2. Ceiling round\n3. Round to the nearest whole number"<<endl;
    cin>>optionRound;
    switch (optionRound) {
        case FLOOR_ROUND:
            cout<<(int) numToRound<<endl;
            break;
        case CEILING_ROUND:
            if (numToRound > 0)
                cout<<(int) (numToRound + 1)<<endl;
            else if (numToRound < 0)
                cout<<(int) (numToRound - 1)<<endl;
            else
                cout<<numToRound<<endl;
            break;
        case ROUND:
            if (numToRound > 0 && (numToRound - ((int) numToRound)) >= 0.5)
                cout<<(int) (numToRound + 1)<<endl;
            else if (numToRound < 0 && ((int) numToRound) - numToRound >= 0.5)
                cout<<(int) (numToRound - 1)<<endl;
            else
                cout<<(int) numToRound<<endl;
            break;
        default:
            cout<<"Illegal option!"<<endl;
    }
    return 0;
}

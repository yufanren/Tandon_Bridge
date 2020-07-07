//
// Created by yufanren on 1/31/20.
//
#include <iostream>
using namespace std;

int main() {
    int num;
    cout<<"Enter a positive integer: "<<endl;
    cin>>num;
    int numBlank;
    for (numBlank = 0; 2 * num - (1 + 2 * numBlank) > 0; numBlank++) {
        for (int blankCounter = 0; blankCounter < numBlank; blankCounter++) {
            cout<<" ";
        }
        for (int starCounter = 2 * num - (1 + 2 * numBlank); starCounter > 0; starCounter--) {
            cout<<"*";
        }
        cout<<endl;
    }
    for (numBlank = num - 1; numBlank >= 0; numBlank--) {
        for (int blankCounter = 0; blankCounter < numBlank; blankCounter++) {
            cout<<" ";
        }
        for (int starCounter = 2 * num - (1 + 2 * numBlank); starCounter > 0; starCounter--) {
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}

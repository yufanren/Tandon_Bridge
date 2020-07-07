//
// Created by yufanren on 3/3/20.
//
#include <iostream>

using namespace std;

void reduceBy5(int n);

int main() {
    reduceBy5(16);
    return 0;
}

void reduceBy5(int n) {
        cout<<n<<" ";
    if (n > 0) {
        reduceBy5(n - 5);
        cout<<n<< " ";
    }
}

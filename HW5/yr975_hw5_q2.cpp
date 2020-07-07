//
// Created by yufanren on 2/7/20.
//
#include <iostream>
using namespace std;

void printShiftedTriangle(int n, int m, char symbol);
void printPineTree(int n, char symbol);

int main() {
    int size;
    char symbol;
    cout<<"Please enter size of the pine tree: ";
    cin>>size;
    cout<<"Please enter a symbol which form the tree; ";
    cin>>symbol;
    printPineTree(size, symbol);
    return 0;
}

void printPineTree(int n, char symbol) {
    for (int counter = 1; counter <= n; counter++) {
        int marginTriangle = n - counter;
        printShiftedTriangle(counter + 1, marginTriangle, symbol);
    }
}

void printShiftedTriangle(int n, int m, char symbol){
    for (int row = 1; row <= n; row++) {
        for (int i = 1; i <= m + n - row; i++)
            cout<<" ";
        int symbolCount = 2 * (row - 1) + 1;
        for (int j = 1; j <= symbolCount; j++)
            cout << symbol;
        cout<<endl;
    }
}



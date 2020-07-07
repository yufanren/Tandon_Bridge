//
// Created by yufanren on 2/28/20.
//
#include <iostream>

void printRuler(int n);
void printOppositeTriangles(int n);
void printTriangle(int n);
void printLine(int n, char c);

using namespace std;

int main() {
    printTriangle(5);
    cout << endl;
    printOppositeTriangles(5);
    cout << endl;
    printRuler(4);
    return 0;
}

void printRuler(int n) {
    if (n == 1) {
        printLine(1, '-');
    }
    else {
        printRuler(n - 1);
        cout << endl;
        printLine(n, '-');
        cout << endl;
        printRuler(n -1);
    }
}

void printOppositeTriangles(int n) {
    if (n != 0) {
        printLine(n, '*');
        cout << endl;
        printOppositeTriangles(n - 1);
        printLine(n, '*');
        cout << endl;
    }
}

void printTriangle(int n) {
    if (n != 0) {
        printTriangle(n - 1);
        printLine(n, '*');
        cout << endl;
    }
}

void printLine(int n, char c) {
    cout << c;
    if (n != 1)
        printLine(n - 1, c);
}



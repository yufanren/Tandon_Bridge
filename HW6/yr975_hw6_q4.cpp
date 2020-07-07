//
// Created by yufanren on 2/15/20.
//
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

const int ARRAY_PHYSICAL_SIZE = 10;
const int PIN_NUMBER = 13579;
const int CODE_LOWER_BOUND = 1, CODE_HIGHER_BOUND = 3;

void fillRandomArr(int arr[], int arrSize, int lBound, int hBound);
bool verifyPin(const int arr[], int arrSize, int userEntry);
int fetchCode(const int codeTable[], int arrSize, int pin);
void displayTable(const int arr[], int arrSize);

int main() {
    int arr[ARRAY_PHYSICAL_SIZE], userEntry;
    //generate random numbers for array
    fillRandomArr(arr, ARRAY_PHYSICAL_SIZE, CODE_LOWER_BOUND, CODE_HIGHER_BOUND);
    //display prompt.
    cout<<"Please enter your PIN according to the following mapping:\n";
    //display code table.
    displayTable(arr, ARRAY_PHYSICAL_SIZE);
    cin>>userEntry;
    //compare pin to array, display result.
    cout<<"Your PIN is ";
    if (!verifyPin(arr, ARRAY_PHYSICAL_SIZE, userEntry))
        cout<<"not ";
    cout<<"correct\n";
    return 0;
}

bool verifyPin(const int arr[], int arrSize, int userEntry) {
    return userEntry == fetchCode(arr, arrSize, PIN_NUMBER);
}

int fetchCode(const int codeTable[], int arrSize, int pin) {
    int code = 0, decimalPosition = 0;
    while (pin) {
        code += codeTable[pin % 10] * pow(10, decimalPosition);
        decimalPosition++;
        pin /= 10;
    }
    return code;
}

void displayTable(const int arr[], int arrSize) {
    cout<<"PIN:\t";
    for (int i = 0; i < arrSize; i++) {
        cout<<i<<"\t";
    }
    cout<<"\nNUM:\t";
    for (int j = 0; j < arrSize; j++) {
        cout<<arr[j]<<"\t";
    }
    cout<<endl;
}

void fillRandomArr(int arr[], int arrSize, int lBound, int hBound) {
    srand(time(0));
    for (int i = 0; i < arrSize; i++) {
        arr[i] = rand() % (hBound - lBound + 1) + lBound;
    }
}
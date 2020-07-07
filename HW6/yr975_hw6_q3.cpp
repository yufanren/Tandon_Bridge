//
// Created by yufanren on 2/15/20.
//
#include <iostream>
using namespace std;

void printArray(int arr[], int arrSize);
void reverseArray(int arr[], int arrSize);
void removeOdd(int arr[], int& arrSize);
void splitParity(int arr[], int arrSize);

int main() {
    int arr1[10] = {9, 2, 14, 12, -3, 999, 71, -20, 1};
    int arr1Size = 9;
    int arr2[10] = {9, 5, 20, 1, 44, 100, 77};
    int arr2Size = 7;
    int arr3[10] = {4, 1, 12, 55, 80, 100, 13, 21, 50, 121};
    int arr3Size = 9;
    reverseArray(arr1, arr1Size);
    printArray(arr1, arr1Size);
    removeOdd(arr2, arr2Size);
    printArray(arr2, arr2Size);
    splitParity(arr3, arr3Size);
    printArray(arr3, arr3Size);
    return 0;
}

void splitParity(int arr[], int arrSize) {
    int temp, reverseEvenPointer = arrSize - 1;
    for (int counter = 0; counter < reverseEvenPointer; counter++) {
        if (arr[counter] % 2 == 0) {
            temp = arr[reverseEvenPointer];
            arr[reverseEvenPointer] = arr[counter];
            arr[counter] = temp;
            counter--;
            reverseEvenPointer--;
        }
    }
}

void removeOdd(int arr[], int& arrSize) {
    int evenCounter = 0;
    bool startModify = false;
    for (int counter = 0; counter < arrSize; counter++) {
        if (!startModify && arr[counter] % 2 == 1) {
            evenCounter = counter;
            startModify = true;
        }
        else if (arr[counter] % 2 == 0 && startModify) {
            arr[evenCounter] = arr[counter];
            evenCounter++;
        }
    }
    if (startModify)
        arrSize = evenCounter;
}

void reverseArray(int arr[], int arrSize) {
    int temp;
    for (int pointerFront = 0, pointerEnd = arrSize - 1; pointerFront < pointerEnd; pointerFront++, pointerEnd--) {
        temp = arr[pointerEnd];
        arr[pointerEnd] = arr[pointerFront];
        arr[pointerFront] = temp;
    }
}

void printArray(int arr[], int arrSize){
    int i;
    for (i = 0; i < arrSize; i++) {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}
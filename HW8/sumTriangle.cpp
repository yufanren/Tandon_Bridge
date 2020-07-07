//
// Created by yufanren on 3/3/20.
//
#include <iostream>

using namespace std;

void displayArr(int arr[], int arrSize);
void sumTriangle(int arr[], int arrSize);

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    sumTriangle(arr, 5);
    return 0;
}

void sumTriangle(int arr[], int arrSize) {
    if (arrSize < 2)
        displayArr(arr, arrSize);
    else {
        int* smallerArr = new int[arrSize - 1];
        for (int i = 0; i < arrSize - 1; i++)
            smallerArr[i] = arr[i] + arr[i + 1];
        sumTriangle(smallerArr, arrSize - 1);
        displayArr(arr, arrSize);
        delete [] smallerArr;
    }
}

void displayArr(int arr[], int arrSize) {
    cout<<"[";
    for (int i = 0; i < arrSize; i++) {
        cout<<arr[i];
        if (i != arrSize - 1)
            cout<<", ";
    }
    cout<<"]"<<endl;
}

//
// Created by yufanren on 2/14/20.
//
#include <iostream>;
using namespace std;

int minInArray(const int arr[], int arrSize);
void printValLocation(const int arr[], int arrSize, int value);
int readArrValue(int arr[], int arrPhysSize);

const int MAX_ARRAY_SIZE = 20;
int main() {
    int arrTest[MAX_ARRAY_SIZE], dataSize, arrMin;
    dataSize = readArrValue(arrTest, MAX_ARRAY_SIZE);
    arrMin = minInArray(arrTest, dataSize);
    printValLocation(arrTest, dataSize, arrMin);
    return 0;
}

void printValLocation(const int arr[], int arrSize, int value) {
    cout<<"The minimum value is "<<value<<", and it is located in the following indices:";
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == value)
            cout<<i<<" ";
    }
    cout<<endl;
}

int readArrValue(int arr[], int arrPhysSize) {
    cout<<"Please enter "<<arrPhysSize<<" integers separated by a space:"<<endl;
    int dataSize = 0;
    for (int i = 0; i < arrPhysSize; i++) {
        cin>>arr[i];
        dataSize++;
    }
    return dataSize;
}

int minInArray(const int arr[], int arrSize) {
    int minNum = arr[0];
    for (int i = 1; i < arrSize; i++) {
        if (arr[i] < minNum)
            minNum = arr[i];
    }
    return minNum;
}


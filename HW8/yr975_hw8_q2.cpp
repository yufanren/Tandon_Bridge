//
// Created by yufanren on 2/28/20.
//
#include <iostream>

using namespace std;

int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);

int main() {
    int arrTest[] = {2, -1, 3, 10};
    cout << sumOfSquares(arrTest, 4) << endl;
    int arrSrtTest[] = {1, 1, 5, 8, 10};
    cout << isSorted(arrSrtTest, 5) << endl;
    return 0;
}

bool isSorted(int arr[], int arrSize) {
    if (arrSize == 1)
        return true;
    else
        return (arr[arrSize - 1] >= arr[arrSize - 2]) && isSorted(arr, arrSize - 1);
}

int sumOfSquares(int arr[], int arrSize) {
    if (arrSize == 1)
        return arr[arrSize - 1] * arr[arrSize - 1];
    else {
        return arr[arrSize - 1] * arr[arrSize - 1] + sumOfSquares(arr, arrSize - 1);
    }
}

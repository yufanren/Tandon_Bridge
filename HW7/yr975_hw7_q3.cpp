#include <iostream>

using namespace std;

void oddsKeepEvensFlip(int arr[], int arrSize);

int main() {

    int list [9] = {13, 6, 9, 17, 100, 918, 666, 69, 0};
    for (int i = 0; i < 9; i++) {
        cout << list[i] << " ";
    }
    cout << endl;
    oddsKeepEvensFlip(list, 9);
    for (int i = 0; i < 9; i++) {
        cout << list[i] << " ";
    }
    return 0;
}

void oddsKeepEvensFlip(int arr[], int arrSize) {
    int* arrTemp = new int[arrSize];
    int oddCounter = 0, evenCounter = arrSize - 1;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] % 2 == 1) {
            arrTemp[oddCounter] = arr[i];
            oddCounter++;
        }
        else {
            arrTemp[evenCounter] = arr[i];
            evenCounter--;
        }
    }
    for (int j = 0; j < arrSize; j++) {
        arr[j] = arrTemp[j];
    }
    delete [] arrTemp;
    arrTemp = nullptr;
}
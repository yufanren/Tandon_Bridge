//
// Created by yufanren on 2/22/20.
//
#include <iostream>

using namespace std;

int* findMissing(int arr[], int n, int& resArrSize);
bool* createFalseTable(int size);
void updateTable(bool* numTable, int numTableSize, const int* numsArr, int numArrSize);
int countMissing(const bool* numTable, int numTableSize);
int* fillMissingsTable(int* missingsTable, int msTableSize, bool* numTable, int numTableSize);
void displayArr(int* arr, int arrSize);

int main() {
    int arr[8] = {2, 8, 6, 5, 4, 3, 2, 1};
    int missingArrSize;
    int* missingArr = findMissing(arr, 8, missingArrSize);
    cout << "Array:\t\t";
    displayArr(arr, 8);
    cout << "Missing:\t";
    displayArr(missingArr, missingArrSize);
    delete [] missingArr;
    missingArr = nullptr;
    return 0;
}

int* findMissing(int arr[], int n, int& resArrSize) {
    int numTableSize = n + 1;
    bool* numTable = createFalseTable(numTableSize);
    updateTable(numTable, numTableSize, arr, n);
    int numMissing = countMissing(numTable, numTableSize);
    int* missingsTable = new int [numMissing];
    resArrSize = numMissing;
    return fillMissingsTable(missingsTable, numMissing, numTable, numTableSize);
}

int* fillMissingsTable(int* missingsTable, int msTableSize, bool* numTable, int numTableSize) {
    int msCounter = 0;
    while (msCounter < msTableSize) {
        for (int i = 0; i < numTableSize; i++) {
            if (!numTable[i]) {
                missingsTable[msCounter] = i;
                msCounter++;
            }
        }
    }
    delete [] numTable;
    numTable = nullptr;
    return missingsTable;
}

bool* createFalseTable(int size) {
    bool* falseTable = new bool [size];
    for (int i = 0; i < size; i++) {
        falseTable[i] = false;
    }
    return falseTable;
}

int countMissing(const bool* numTable, int numTableSize) {
    int missingCount = 0;
    for (int i = 0; i < numTableSize; i++) {
        if (!numTable[i])
            missingCount++;
    }
    return missingCount;
}

void updateTable(bool* numTable, int numTableSize, const int* numsArr, int numArrSize) {
    for (int i = 0; i < numArrSize; i++) {
        if (numsArr[i] < numTableSize)
            numTable[numsArr[i]] = true;
    }
}

void displayArr(int* arr, int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

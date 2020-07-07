//
// Created by yufanren on 2/22/20.
//
#include <iostream>

using namespace std;

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
void getPosNums2(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
int* getPosNums3(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);
int countPosNums(const int* arr, int arrSize);
int* createPosArr(const int* arr, int arrSize, int arrPosSize);
void displayArr(int* arr, int arrSize);

const int TEST_ARRAY_SIZE = 10;

int main() {
    int arr [TEST_ARRAY_SIZE] = {-15, 0, -7, 1, 99, 87, -20, 7, -1, 666};
    int arrSize1, arrSize2, arrSize3, arrSize4;
    int *arrPos2, *arrPos4;

    int* arrPos1 = getPosNums1(arr, TEST_ARRAY_SIZE, arrSize1);
    getPosNums2(arr, TEST_ARRAY_SIZE, arrPos2, arrSize2);
    int* arrPos3 = getPosNums3(arr, TEST_ARRAY_SIZE, &arrSize3);
    getPosNums4(arr, TEST_ARRAY_SIZE, &arrPos4, &arrSize4);

    cout << "original:\t";
    displayArr(arr, TEST_ARRAY_SIZE);
    cout << "function 1:\t";
    displayArr(arrPos1, arrSize1);
    cout << "function 2:\t";
    displayArr(arrPos2, arrSize2);
    cout << "function 3:\t";
    displayArr(arrPos3, arrSize3);
    cout << "function 4:\t";
    displayArr(arrPos4, arrSize4);

    delete [] arrPos1;
    arrPos1 = nullptr;
    delete [] arrPos2;
    arrPos2 = nullptr;
    delete [] arrPos3;
    arrPos3 = nullptr;
    delete [] arrPos4;
    arrPos4 = nullptr;
    return 0;
}

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize) {
    int posArrSize = countPosNums(arr, arrSize);
    outPosArrSize = posArrSize;
    return createPosArr(arr, arrSize, posArrSize);
}

void getPosNums2(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize) {
    int posArrSize = countPosNums(arr, arrSize);
    outPosArr = createPosArr(arr, arrSize, posArrSize);
    outPosArrSize = posArrSize;
}

int* getPosNums3(int* arr, int arrSize, int* outPosArrSizePtr) {
    int posArrSize = countPosNums(arr, arrSize);
    *outPosArrSizePtr = posArrSize;
    return createPosArr(arr, arrSize, posArrSize);
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr) {
    int posArrSize = countPosNums(arr, arrSize);
    *outPosArrPtr = createPosArr(arr, arrSize, posArrSize);
    *outPosArrSizePtr = posArrSize;
}

int* createPosArr(const int* arr, int arrSize, int arrPosSize) {
    int* arrPos = new int [arrPosSize];
    int counter = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            arrPos[counter] = arr[i];
            counter++;
        }
    }
    return arrPos;
}

int countPosNums(const int* arr, int arrSize) {
    int posNumCount = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0)
            posNumCount++;
    }
    return posNumCount;
}

void displayArr(int* arr, int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
//
// Created by yufanren on 2/29/20.
//
#include <iostream>

using namespace std;

void moveZeros(int nums[], int arrSize);
void displayArr(int nums[], int arrSize);

int main() {
    int nums[] = {0, 2, 0, 1, 0, 999, -8, 0, 74, 0, 0, 1};
    moveZeros(nums, 12);
    displayArr(nums, 12);
    return 0;
}

void moveZeros(int nums[], int arrSize) {
    int numCounter = 0;
    for (int i = 0; i < arrSize; i++) {
        if (nums[i] != 0) {
            nums[numCounter] = nums[i];
            numCounter++;
        }
    }
    for (int j = numCounter; j < arrSize; j++)
        nums[j] = 0;
}

void displayArr(int nums[], int arrSize) {
    for (int i = 0; i < arrSize; i++)
        cout<<nums[i]<<" ";
    cout<<endl;
}

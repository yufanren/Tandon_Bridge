//
// Created by yufanren on 2/28/20.
//
#include <iostream>

using namespace std;

int minNum(int a, int b);
int minJumps(int arr[], int arrSize);

int main() {
    int arrTest[] = {0, 3, 2, 4};
    cout << minJumps(arrTest, 4) << endl;
    return 0;
}

int minJumps(int arr[], int arrSize) {
    if (arrSize < 3)
        return arr[arrSize - 1];
    else
        //cout<<arr[arrSize - 1]<<minJumps(arr, arrSize - 1)<<minJumps(arr, arrSize - 2)<<endl;
        return arr[arrSize - 1] + minNum(minJumps(arr, arrSize - 1), minJumps(arr, arrSize - 2));
}

int minNum(int a, int b) {
    if (a < b)
        return a;
    else
        return b;
}

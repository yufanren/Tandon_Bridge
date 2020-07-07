//
// Created by yufanren on 3/2/20.
//
#include <iostream>
#include <vector>

using namespace std;

void displayVector(vector<int> nums);
void allCombs(int arr[], int arrSize, int r);
void allCombs(vector<int> nums, int r, vector<int> numsSub, int posInNums);

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    allCombs(arr, 5, 3);
    return 0;
}

void allCombs(int arr[], int arrSize, int r) {
    if (arrSize < r)
        return;
    vector<int> emptyVector, nums;
    for (int i = 0; i < arrSize; i++)
        nums.push_back(arr[i]);
    allCombs(nums, r, emptyVector, 0);
}

void allCombs(vector<int> nums, int r, vector<int> numsSub, int posInNums) {
    if (posInNums > nums.size())
        return;
    else if (numsSub.size() == r)
        displayVector(numsSub);
    else {
        for (int i = posInNums; i < nums.size(); i++) {
            vector<int> newSubVector = numsSub;
            newSubVector.push_back(nums[i]);
            allCombs(nums, r, newSubVector, i + 1);
        }
    }
}

void displayVector(vector<int> nums) {
    for (int i: nums)
        cout<<i<<" ";
    cout<<endl;
}

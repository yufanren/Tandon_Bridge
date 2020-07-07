//
// Created by yufanren on 2/29/20.
//
#include <iostream>

int maxZeroLength(int nums[], int len, int startIdx);

using namespace std;

int main() {
    int nums[] = {0, 0, 1, 0, 0, 0, 0, 1};
    cout<<maxZeroLength(nums, 8, 0)<<endl;
    return 0;
}

int maxZeroLength(int nums[], int len, int startIdx) {
    if (len <= startIdx)
        return 0;
    else if (len == startIdx + 1)
        if (nums[startIdx] == 0)
            return 1;
        else
            return 0;
    else {
        if (nums[len - 1] == 0) {
            int offset = -1, currentZeros = 1;
            while (nums[len - 1 + offset] == 0 && len - offset > startIdx) {
                currentZeros++;
                offset--;
            }
            return max(currentZeros, maxZeroLength(nums, len - 1, startIdx));
        } else
            return maxZeroLength(nums, len - 1, startIdx);
    }
}


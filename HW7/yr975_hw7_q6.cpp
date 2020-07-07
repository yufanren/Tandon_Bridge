//
// Created by yufanren on 2/22/20.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void main1();
void main2();
void arrPushBack(int*& arr, int& logicSize, int& physSize, int value);
void doubleArrSize(int*& arr, int& logicSize, int&physSize);
vector<int> saveIntList();
int* saveIntList(int& arrSize);
vector<int> createMatchList(vector<int> intList, int& searchTarget);
int* createMatchList(int* intList, int intListSize, int& matchListSize, int& searchTarget);
void displayMatchList(vector<int> matchList, int searchTarget);
void displayMatchList(int* matchList, int matchListSize, int searchTarget);

int main() {
    cout << "\nMethod 1: \n";
    main1();
    cout << "\nMethod 2: \n";
    main2();
    return 0;
}

void main1() {
    int intListSize = 0, matchListSize = 0, searchTarget = 0;
    int* intList = saveIntList(intListSize);
    int* matchList = createMatchList(intList, intListSize, matchListSize, searchTarget);
    displayMatchList(matchList, matchListSize, searchTarget);
    delete [] intList;
    delete [] matchList;
    intList = nullptr;
    matchList = nullptr;
}

void main2() {
    int searchTarget = 0;
    vector<int> intList = saveIntList();
    vector<int> matchList = createMatchList(intList, searchTarget);
    displayMatchList(matchList, searchTarget);
}

void displayMatchList(int* matchList, int matchListSize, int searchTarget) {
    if (matchListSize == 0)
        cout << searchTarget << " does not show at all in the sequence." << endl;
    else {
        cout << searchTarget <<  " shows in lines ";
        for (int i = 0; i < matchListSize; i++) {
            cout << matchList[i];
            if (i == matchListSize - 1)
                cout << ".\n";
            else
                cout << ", ";
        }
    }
}

void displayMatchList(vector<int> matchList, int searchTarget) {
    if (matchList.empty())
        cout << searchTarget << " does not show at all in the sequence." << endl;
    else {
        cout << searchTarget <<  " shows in lines ";
        for (int i = 0; i < matchList.size(); i++) {
            cout << matchList[i];
            if (i == matchList.size() - 1)
                cout << ".\n";
            else
                cout << ", ";
        }
    }
}

int* createMatchList(int* intList, int intListSize, int& matchListSize, int& searchTarget) {
    int matchListPhysSize = 5;
    int* matchList = new int [matchListPhysSize];
    cout << "Please enter a number you want to search:\n";
    cin >> searchTarget;
    for (int i = 0; i < intListSize; i++) {
        if (intList[i] == searchTarget)
            arrPushBack(matchList, matchListSize, matchListPhysSize, i + 1);
    }
    return matchList;
}

vector<int> createMatchList(vector<int> intList, int& searchTarget) {
    vector<int> matchList;
    cout << "Please enter a number you want to search:\n";
    cin >> searchTarget;
    for (int i = 0; i < intList.size(); i++) {
        if (intList[i] == searchTarget)
            matchList.push_back(i + 1);
    }
    return matchList;
}

int* saveIntList(int& arrSize) {
    int current, numSize = 0, numPhysSize = 5;
    int* nums = new int [numPhysSize];
    cout << "Please enter a sequence of positive integers, each in a separate line.\n";
    cout << "End you input by typing -1.\n";
    cin >> current;
    while (current != -1) {
        arrPushBack(nums, numSize, numPhysSize, current);
        cin >> current;
    }
    arrSize = numSize;
    return nums;
}

vector<int> saveIntList() {
    int current;
    vector<int> nums;
    cout << "Please enter a sequence of positive integers, each in a separate line.\n";
    cout << "End you input by typing -1.\n";
    cin >> current;
    while (current != -1) {
        nums.push_back(current);
        cin >> current;
    }
    return nums;
}

void arrPushBack(int*& arr, int& logicSize, int& physSize, int value) {
    if (logicSize == physSize)
        doubleArrSize(arr, logicSize, physSize);
    arr[logicSize] = value;
    logicSize++;
}

void doubleArrSize(int*& arr, int& logicSize, int&physSize) {
    int* temp = new int[physSize * 2];
    for (int i = 0; i < logicSize; i++) {
        temp[i] = arr[i];
    }
    physSize *= 2;
    delete [] arr;
    arr = temp;
}
//
// Created by yufanren on 3/3/20.
//
#include <iostream>
#include <vector>

using namespace std;

void allNonIncreaseSeq(int n, vector<int> currentSeq);
void displayVec(vector<int> v);
void testVector(vector<int> v0);

int main() {
    vector<int> list;
    testVector(list);
    //allNonIncreaseSeq(4, list);
    return 0;
}

void allNonIncreaseSeq(int n, vector<int> currentSeq) {
    if (n == 0)
        displayVec(currentSeq);
    else if (n > 0) {
        for (int i = n; i > 0; i--) {
            vector<int> v1 = currentSeq;
            v1.push_back(i);
            allNonIncreaseSeq(n - i, v1);
        }
    }
}

void displayVec(vector<int> v) {
    for (int i = 0; i < v.size(); i++)
        cout<<v[i]<<" ";
    cout<<endl;
}

void testVector(vector<int> v0) {
    vector<int> v1 = v0;
    vector<int> v2 = v1;
    v1.push_back(1);
    cout<<"v1: "<<&v1;
    cout<<"v2: "<<&v2;
}


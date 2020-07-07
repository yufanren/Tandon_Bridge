//
// Created by yufanren on 2/21/20.
//
#include <iostream>
#include <vector>

using namespace std;

bool isLetter(char c);
bool compareAnagrams(string str1, string str2);
vector<int> updateCounts(string str, vector<int> ltrCount, int increment);
bool evaluateZeroCounts(vector<int> ltrCount);
int convertCharToNum(char c);

int const NUMBER_OF_LETTERS = 'z' - 'a' + 1;

int main() {
    string str1, str2;

    cout << "Please enter a line of text: " << endl;
    getline(cin, str1);
    cout << "Please enter a second line of text for comparison: " << endl;
    getline(cin, str2);
    cout << "These two strings are ";
    if (! compareAnagrams(str1, str2))
        cout << "not ";
    cout << "anagrams."<<endl;
    return 0;
}

bool compareAnagrams(string str1, string str2) {
    vector<int> letterCounts;
    for (int i = 0; i < NUMBER_OF_LETTERS; i++) {
        letterCounts.push_back(0);
    }
    letterCounts = updateCounts(str2, updateCounts(str1, letterCounts, 1), -1);
    return evaluateZeroCounts(letterCounts);
}

//convert a letter into a index number.
int convertCharToNum(char c) {
    if (c - 'a' > -1 && c - 'a' < NUMBER_OF_LETTERS)
        return c - 'a';
    else if (c - 'A' > -1 && c - 'A' < NUMBER_OF_LETTERS)
        return c - 'A';
    else
        return -1;
}

//update vector with number of letters in a string.
vector<int> updateCounts(string str, vector<int> ltrCount, int increment) {
    for (int i = 0; i < str.size(); i++) {
        int index = convertCharToNum(str[i]);
        if (index != -1)
            ltrCount[index] += increment;
    }
    return ltrCount;
}

//check if vector has 0 as all of its values.
bool evaluateZeroCounts(vector<int> ltrCount) {
    for (int i : ltrCount) {
        if (i != 0)
            return false;
    }
    return true;
}

//check if this character is a letter.
bool isLetter(char c) {
    return (c - 'a' > -1 && c - 'a' < NUMBER_OF_LETTERS) || (c - 'A' > -1 && c - 'A' < NUMBER_OF_LETTERS);
}


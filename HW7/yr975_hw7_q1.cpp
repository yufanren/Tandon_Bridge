//
// Created by yufanren on 2/21/20.
//
#include <iostream>
#include <string>

using namespace std;

int countWords(string str, int* ltrArr, int arrSize);
int* createLtrTable(int tableLength);
void reportLtrCount(int* ltrArr, int arrSize);
bool startWord(string str, int position);
bool isLetter(char c);
int getWordLength(string str, int position);
void countLtrInWord(string str, int* ltrArr, int arrSize);

const int NUMBER_OF_LETTERS = 'z' - 'a' + 1;

int main() {
    int* ltrTable;
    string line;
    int wordCount;

    ltrTable = createLtrTable(NUMBER_OF_LETTERS);
    cout << "Please enter a line of text:" << endl;
    getline(cin, line);

    wordCount = countWords(line, ltrTable, NUMBER_OF_LETTERS);

    cout << wordCount << "\twords" << endl;
    reportLtrCount(ltrTable, NUMBER_OF_LETTERS);

    delete [] ltrTable;
    ltrTable = nullptr;
    return 0;
}

//count the number of words in the line while call a function that adds letter counts.
int countWords(string str, int* ltrArr, int arrSize) {
    int wordCount = 0, strPos = 0, strLength = str.size();
    while (strPos < strLength) {
        if (startWord(str, strPos)) {
            int wordLength = getWordLength(str, strPos);
            countLtrInWord(str.substr(strPos, wordLength), ltrArr, arrSize);
            strPos += wordLength;
            wordCount++;
        }
        else
            strPos++;
    }
    return wordCount;
}

//count letters in a word and add them to the letter array.
void countLtrInWord(string str, int* ltrArr, int arrSize) {
    for (char i : str) {
        if (i - 'a' > -1 && i - 'a' < arrSize)
            ltrArr[i - 'a']++;
        else if (i - 'A' > -1 && i - 'A' < arrSize)
            ltrArr[i - 'A']++;
    }
}

//get the length of word starting at position.
int getWordLength(string str, int position) {
    int posOffset = 1;
    while (position + posOffset < str.size() && isLetter(str[position + posOffset]))
        posOffset++;
    return posOffset;
}

//report number of letters as recorded on array.
void reportLtrCount(int* ltrArr, int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        if (ltrArr[i] != 0)
            cout << ltrArr[i] << "\t" << (char)('a' + i) << endl;
    }
}

//create a array with indexes representing letters and set initial counts to 0.
int* createLtrTable(int tableLength) {
    int* tablePtr = new int[tableLength];
    for (int i = 0; i < tableLength; i++)
        tablePtr[i] = 0;
    return tablePtr;
}

//check if this position on string is the start of a word.
bool startWord(string str, int position) {
    if (position != 0 )
        return isLetter(str[position]) && !isLetter(str[position - 1]);
    else
        return isLetter(str[position]);
}

//check if this character is a letter.
bool isLetter(char c) {
    return (c - 'a' > -1 && c - 'a' < NUMBER_OF_LETTERS) || (c - 'A' > -1 && c - 'A' < NUMBER_OF_LETTERS);
}
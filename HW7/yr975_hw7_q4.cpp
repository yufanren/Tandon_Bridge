//
// Created by yufanren on 2/21/20.
//
#include <iostream>
#include <string>

using namespace std;

string* createWordsArray(string sentence, int& outWordsArrSize);
bool startOfWord(string str, int position);
int getWordLength(string str, int position);

int main() {
    string line;
    int wordCount;
    cout << "Please enter a sentence:" << endl;
    getline(cin, line);
    string* strArr = createWordsArray(line, wordCount);

    for (int i = 0; i < wordCount; i++) {
        cout << i <<".\t" << strArr[i] << endl;
    }
    delete [] strArr;
    strArr = nullptr;
    return 0;
}

string* createWordsArray(string sentence, int& outWordsArrSize) {
    int wordCount = 0, strPos = 0, strLength = sentence.size();
    while (strPos < strLength) {
        if (startOfWord(sentence, strPos))
            wordCount++;
        strPos++;
    }
    string* strArr = new string [wordCount];
    outWordsArrSize = wordCount;
    strPos = 0, wordCount = 0;
    while (strPos < strLength) {
        if (startOfWord(sentence, strPos)) {
            int wordLength = getWordLength(sentence, strPos);
            strArr[wordCount] = sentence.substr(strPos, wordLength);
            strPos += wordLength;
            wordCount++;
        }
        else
            strPos++;
    }
    return strArr;
}

int getWordLength(string str, int position) {
    int posOffset = 1;
    while (position + posOffset < str.size() && str[position + posOffset] != ' ')
        posOffset++;
    return posOffset;
}

bool startOfWord(string str, int position) {
    return (position == 0 || str[position - 1] == ' ') && str[position] != ' ';
}

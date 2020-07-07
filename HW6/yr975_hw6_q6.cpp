//
// Created by yufanren on 2/15/20.
//
#include <iostream>
#include <string>
using namespace std;

bool isNumber(char c);
bool isNumericStr(string str);
string hideNumInStr(string& str);
int getWordLength(string str, int pos);
void hideStr(string& str, int pos, int length);

int main() {
    string str;
    cout<<"Please enter a line of text: \n";
    getline(cin, str);
    str = hideNumInStr(str);
    cout<<str<<endl;
    return 0;
}

string hideNumInStr(string& str) {
    int counter = 0;
    while (counter < str.length()) {
        //reach start of a word.
        if ((counter == 0 || str[counter - 1] == ' ') && str[counter] != ' ') {
            //get length of word.
            int wordLength = getWordLength(str, counter);
            //check if word is numeric, change if yes.
            if (isNumericStr(str.substr(counter, wordLength)))
                hideStr(str, counter, wordLength);
            //set counter to new position.
            counter += wordLength;
        }
        else
            counter++;
    }
    return str;
}

void hideStr(string& str, int pos, int length) {
    for (int i = pos; i < pos + length; i++) {
        str[i] = 'x';
    }
}

int getWordLength(string str, int pos) {
    int offset = 0;
    while (pos < str.length() && (str[pos] != ' ')) {
        pos++;
        offset++;
    }
    return offset;
}

bool isNumericStr(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (!isNumber(str[i]))
            return false;
    }
    return true;
}

bool isNumber(char c) {
    char first = '0';
    return !((c - first) < 0 || (c - first) > 9);
}

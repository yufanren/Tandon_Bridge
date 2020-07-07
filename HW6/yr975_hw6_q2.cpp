//
// Created by yufanren on 2/14/20.
//
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str);

int main() {
    string str;
    cout<<"Please enter a word:";
    cin>>str;
    if (isPalindrome(str))
        cout<<str<<" is a palindrome"<<endl;
    else
        cout<<str<<" is not a palindrome"<<endl;
    return 0;
}

bool isPalindrome(string str) {
    int counterA = 0, counterB = str.length() - 1;
    while (counterB > counterA) {
        if (str[counterA] != str[counterB])
            return false;
        else {
            counterA++;
            counterB--;
        }
    }
    return true;
}


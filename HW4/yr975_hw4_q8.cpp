//
// Created by yufanren on 2/1/20.
//
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int NUM_OF_GUESS = 5;
int main() {
    srand(time(0));
    int guessCurrent, guessCount = NUM_OF_GUESS, numRand = (rand() % 100) +1;
    int boundLower = 1, boundHigher = 100;
    bool outOfGuess = false;
    cout<<"I thought of a number between 1 and 100! Try to guess it."<<endl;
    while (!outOfGuess) {
        cout<<"\nRange: ["<<boundLower<<", "<<boundHigher<<"], Number of guesses left: "<<guessCount<<endl;
        cout<<"Your guess: ";
        cin>>guessCurrent;
        guessCount--;
        if (guessCurrent == numRand) {
            cout << "Congrats! You guessed my number in " << NUM_OF_GUESS - guessCount << " guesses." << endl;
            outOfGuess = true;
        }
        else if (guessCount <= 0) {
            cout<<"Out of guesses! My number is "<<numRand<<endl;
            outOfGuess = true;
        }
        else if (guessCurrent < boundLower || guessCurrent > boundHigher) {
            cout<<"Hey its outside the known range, it's not helping!\nPlease try again."<<endl;
        }
        else if (guessCurrent > numRand) {
            cout<<"Wrong! My number is smaller."<<endl;
            boundHigher = guessCurrent - 1;
        }
        else {
            cout<<"Wrong! My number is bigger."<<endl;
            boundLower = guessCurrent + 1;
        }
    }
    return 0;
}


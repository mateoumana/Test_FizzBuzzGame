#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <chrono>
#include "FizzBuzzGame.h"

using namespace std;

int maxN = 0;

int main() {
    cout << "Welcome to the FizzBuzz Game!" << endl;
    cout << "Choose an option:\n\n1. Default game:\n Names: Abdul, Bart, Claudia, Divya\n Divisors: 3 & 5\n\n2. Custom game: you choose the players and the divisors.\n" << endl;
    int choice;
    cout << "Pick an option: ";
    cin >> choice;
    cout << "\nHow many turns do you wanna see?: ";
    cin >> maxN;
    cout << "\n";

    if (choice == 1) {
        vector<string> names = {"Abdul", "Bart", "Claudia", "Divya"};
        FizzBuzzGame game(names, 3, 5, maxN);
        game.startGame();
    } else if (choice == 2) {
        int numPlayers, fizz, buzz;
        cout << "Enter number of players: ";
        cin >> numPlayers;

        vector<string> names(numPlayers);
        for (int i = 0; i < numPlayers; ++i) {
            cout << "Enter name of player " << i + 1 << ": ";
            cin >> names[i];
        }

        cout << "Enter Fizz divisor: ";
        cin >> fizz;
        cout << "Enter Buzz divisor: ";
        cin >> buzz;
        cout << "\n";

        FizzBuzzGame game(names, fizz, buzz, maxN);
        game.startGame();
    } else {
        cout << "\n<<<Try again, wrong option!>>>\n" << endl;
    }

    return 0;
}

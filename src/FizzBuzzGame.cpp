#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <chrono>
#include "FizzBuzzGame.h"

using namespace std;

FizzBuzzGame::FizzBuzzGame(vector<string> &playerNames, int fizz, int buzz, int maxNum) {
    players = playerNames; fizzDiv = fizz; buzzDiv = buzz;
    currentNumber = 1; currentTurn = 0; gameOver = false; maxNumber = maxNum;
}

FizzBuzzGame::~FizzBuzzGame() {
}

string FizzBuzzGame::fizzBuzzValue(int num) {
    bool fizz = (num % fizzDiv == 0);
    bool buzz = (num % buzzDiv == 0);

    if (fizz && buzz) return "fizzbuzz!";
    else if (fizz) return "fizz!";
    else if (buzz) return "buzz!";
    else return to_string(num);
}

void FizzBuzzGame::playerAction(int index) {
    while (!gameOver){
        if (currentTurn != index) { // espera activa hasta que sea su turno
            this_thread::sleep_for(chrono::milliseconds(1));
            continue;
        }

        if (currentNumber > maxNumber) { // verificar si ya terminó el juego
            gameOver = true;
            break;
        }

        string result = fizzBuzzValue(currentNumber); // si es su turno imprime
        cout << players[index] << " says " << result << endl;

        currentNumber++; // avanzar número y turno
        currentTurn = (currentTurn + 1) % players.size(); //+1 para generar ese residuo creciente

        this_thread::sleep_for(chrono::milliseconds(5)); // dar tiempo a los otros hilos a tomar el control
    }
}

void FizzBuzzGame::startGame() {
    vector<thread> threads;
    for (int i = 0; i < (int)players.size(); ++i) {
        threads.push_back(thread(&FizzBuzzGame::playerAction, this, i));
    }

    for (auto &t : threads){
        if(t.joinable()) t.join();
    }

    cout << "\n\nGAME OVER!" << endl;
}

#ifndef MAP_H
#define MAP_H

using namespace std;

class FizzBuzzGame{
    private:

    protected:
        vector<string> players;
        int fizzDiv, buzzDiv;
        int currentNumber;
        int currentTurn;
        int maxNumber;

        bool gameOver;

    public:
        FizzBuzzGame(vector<string> &playerNames, int fizz, int buzz, int maxNum);
        ~FizzBuzzGame();
        string fizzBuzzValue(int num);
        void playerAction(int index);
        void startGame();
};

#endif

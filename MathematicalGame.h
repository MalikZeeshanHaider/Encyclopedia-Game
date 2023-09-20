#ifndef MATHEMATICALGAME_H
#define MATHEMATICALGAME_H
#include "Game.h"
class MathematicalGame : public Game {
public:
    MathematicalGame(string name, int age) : Game(name, age) {}

    void play() override {
        cout << "Welcome to the Mathematical Game!" << endl;
        cout << "Instructions: Solve the following mathematical equations." << endl;

        // Game logic for Mathematical game
        srand(static_cast<unsigned int>(time(0)));

        for (int i = 0; i < 5; i++) {
            int num1 = rand() % 10 + 1;
            int num2 = rand() % 10 + 1;
            int operation = rand() % 4; // 0: Addition, 1: Subtraction, 2: Multiplication, 3: Division

            int result;
            string operatorSign;

            switch (operation) {
            case 0:
                result = num1 + num2;
                operatorSign = "+";
                break;
            case 1:
                result = num1 - num2;
                operatorSign = "-";
                break;
            case 2:
                result = num1 * num2;
                operatorSign = "*";
                break;
            case 3:
                result = num1 / num2;
                operatorSign = "/";
                break;
            }

            int answer;
            cout << "Equation " << i + 1 << ": " << num1 << " " << operatorSign << " " << num2 << " = ";
            cin >> answer;

            if (answer == result) {
                cout << "Correct answer!" << endl;
                score += 10;
            }
            else {
                cout << "Incorrect answer!" << endl;
            }
        }
    }
};
#endif
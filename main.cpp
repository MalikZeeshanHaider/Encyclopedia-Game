#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Game.h"
#include "SentenceCompletionGame.h"
#include "MathematicalGame.h"
#include "HangmanGame.h"
#include "showHighestScore.cpp"
using namespace std;

// Base class for the game
int main() {
	cout<<"\n\n\n**************** Muhammad Zeeshan Hadier ****************\n";
	cout<<"\n************************ [221093] ***********************\n\n\n";
    cout << "Welcome to the Encyclopedia Game!" << endl;

    while (true) {
        cout << "----- MENU -----" << endl;
        cout << "1. Sentence Completion Game (Age: 4-6)" << endl;
        cout << "2. Mathematical Game (Age: 6-10)" << endl;
        cout << "3. HUNGMAN Game (Age: 12)" << endl;
        cout << "4. Show Highest Score" << endl;
        cout << "5. Quit" << endl;
        cout << "----------------" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore();

        switch (choice) {
        case 1: {
            string playerName;
            int playerAge;

            cout << "Enter your name: ";
            getline(cin, playerName);

            cout << "Enter your age: ";
            cin >> playerAge;

            if (playerAge >= 4 && playerAge <= 6) {
                Game* game = new SentenceCompletionGame(playerName, playerAge);
                game->play();
                game->displayScore();
                game->saveScore();
                cout<<"\nThe Correct Answersgy is  \n",
                cout<<"The sky is Blue.\n",
                cout<<"I like to play with toys.\n",
                cout<<"My favorite color is red.\n",
                cout<<"I have two pets.\n",
                cout<<"I am five years old.\n\n";
                delete game;
            }
            else {
                cout << "Sorry, the Sentence Completion Game is not suitable for your age." << endl;
            }
            break;
        }
        case 2: {
            string playerName;
            int playerAge;

            cout << "Enter your name: ";
            getline(cin, playerName);

            cout << "Enter your age: ";
            cin >> playerAge;

            if (playerAge >= 6 && playerAge <= 10) {
                Game* game = new MathematicalGame(playerName, playerAge);
                game->play();
                game->displayScore();
                game->saveScore();
                delete game;
            }
            else {
                cout << "Sorry, the Mathematical Game is not suitable for your age." << endl;
            }
            break;
        }
        case 3: {
            string playerName;
            int playerAge;

            cout << "Enter your name: ";
            getline(cin, playerName);

            cout << "Enter your age: ";
            cin >> playerAge;

            if (playerAge == 12) {
                Game* game = new HangmanGame(playerName, playerAge);
                game->play();
                game->displayScore();
                game->saveScore();
                delete game;
            }
            else {
                cout << "Sorry, the HUNGMAN Game is not suitable for your age." << endl;
            }
            break;
        }
        case 4:
            showHighestScore();
            break;
        case 5:
            cout << "Thank you for playing the game!" << endl;
            return 0;
        default:
            cout << "Invalid choice! Please try again." << endl;
            break;
        }
    }

    return 0;
}

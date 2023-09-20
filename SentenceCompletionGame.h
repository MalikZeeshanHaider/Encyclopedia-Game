#ifndef SENTENCECOMPLETIONGAME_H
#define SENTENCECOMPLETIONGAME_H
#include "Game.h"
class SentenceCompletionGame : public Game {
public:
    SentenceCompletionGame(string name, int age) : Game(name, age) {}

    void play() override {
        cout << "Welcome to the Sentence Completion Game!" << endl;
        cout << "Instructions: Complete the given sentence with a suitable word." << endl;

        // Game logic for Sentence Completion game
        const string sentences[] = {
            "The sky is ______.",
            "I like to play with ______.",
            "My favorite color is ______.",
            "I have ______ pets.",
            "I am ______ years old."
        };

        const string answers[] = {
            "blue",
            "toys",
            "red",
            "two",
            "five"
        };

        for (int i = 0; i < 5; i++) {
            string answer;
            cout << "Sentence " << i + 1 << ": " << sentences[i] << endl;
            cout << "Your answer: ";
            cin >> answer;

            if (answer == answers[i]) {
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
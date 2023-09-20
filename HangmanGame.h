#ifndef HANGMANGAME_H
#define HANGMANGAME_H
#include "Game.h"
class HangmanGame : public Game {
    public:
    HangmanGame(string name, int age) : Game(name, age) {}

    void play() override
    {
        cout << "Welcome to the Hangman Game!" << endl;
        cout << "Instructions: Guess the word by guessing the missing letters." << endl;

        // Game logic for Hangman game
        const string words[] = {
            "apple",
            "banana",
            "carrot",
            "elephant",
            "giraffe"
        };

        srand(static_cast<unsigned int>(time(0)));
        int randomIndex = rand() % 5;
        string word = words[randomIndex];
        int wordLength = word.length();

        string hiddenWord(wordLength, '_');
        int attempts = 6;
        string guessedLetters;

        while (true) {
            cout << "Hidden Word: " << hiddenWord << endl;
            cout << "Attempts Remaining: " << attempts << endl;
            cout << "Guessed Letters: " << guessedLetters << endl;

            char guess;
            cout << "Enter your guess: ";
            cin >> guess;

            // Convert guess to lowercase for case-insensitive comparison
            guess = tolower(guess);

            // Check if the guessed letter is already guessed
            if (guessedLetters.find(guess) != string::npos) {
                cout << "You already guessed that letter. Try again." << endl;
                continue;
            }

            // Add the guessed letter to the guessed letters list
            guessedLetters += guess;

            // Check if the guessed letter is present in the word
            if (word.find(guess) != string::npos) {
                // Update the hidden word with the correctly guessed letter
                for (int i = 0; i < wordLength; i++) {
                    if (word[i] == guess) {
                        hiddenWord[i] = guess;
                    }
                }

                // Check if the word has been completely guessed
                if (hiddenWord == word) {
                    cout << "Congratulations! You guessed the word correctly: " << word << endl;
                    score = 100;
                    break;
                }
            }
            else {
                cout << "Incorrect guess!" << endl;
                attempts--;

                if (attempts == 0) {
                    cout << "You ran out of attempts. The word was: " << word << endl;
                    break;
                }
            }
        }
    }
};

#endif
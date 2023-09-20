#ifndef GAME_H
#define GAME_H
using namespace std;
class Game {
protected:
    string playerName;
    int playerAge;
    int score;

public:
    Game(string name, int age) : playerName(name), playerAge(age), score(0) {}

    virtual void play() = 0;

    void displayScore() {
        cout << "Score: " << score << endl;
    }

    void saveScore() {
        ofstream outputFile("scores.txt", ios::app);
        outputFile << "Name: " << playerName << ", Age: " << playerAge << ", Score: " << score << endl;
        outputFile.close();
    }
};
#endif
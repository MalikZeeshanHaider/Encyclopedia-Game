#include <fstream>
#include <iostream>
using namespace std;
void showHighestScore() {
    ifstream inputFile("scores.txt");

    if (!inputFile.is_open()) {
        cout << "No scores found." << endl;
        return;
    }

    string line;
    int highestScore = 0;
    string playerName;

    while (getline(inputFile, line)) {
        string name;
        int age;
        int score;

        if (line.find("Name: ") != string::npos) {
            name = line.substr(line.find("Name: ") + 6);
            name = name.substr(0, name.find(","));
        }

        if (line.find("Age: ") != string::npos) {
            age = stoi(line.substr(line.find("Age: ") + 5));
        }

        if (line.find("Score: ") != string::npos) {
            score = stoi(line.substr(line.find("Score: ") + 7));
        }

        if (score > highestScore) {
            highestScore = score;
            playerName = name;
        }
    }

    inputFile.close();

    if (highestScore == 0) {
        cout << "No scores found." << endl;
    }
    else {
        cout << "Highest Score: " << highestScore << " (Player: " << playerName << ")" << endl;
    }
}
#include <iostream>
#include <fstream>
#include <ctype.h>
#include <map>
// #include "Game.hpp"
// using namespace std;

class Game {
public:
    Game(std::string gameString) {

        this->redCount = 0;
        this->greenCount = 0;
        this->blueCount = 0;

        std::map<std::string, std::string> gameMap = this->parseGameString(gameString);
        this->gameId = this->parseGameId(gameMap["gameName"]);
        // std::cout << "Game id = " << this->gameId << std::endl;

        std::string gameData = gameMap["gameData"];
        std::vector<std::string> parsedRounds = this->parseRounds(gameData);
        for (std::string s1 : parsedRounds) {
            std::vector<std::string> parsedRoundInfo = this->parseRoundInfo(s1);

            for (std::string s2 : parsedRoundInfo) {
                this->calculateResults(s2);
            }
        }
        // std::cout << redCount << greenCount << blueCount << std::endl;
    };

    int getGameId() {
        return this->gameId;

    }
    bool isGameLegal(int redMax, int greenMax, int blueMax) {
        if (
            this->redCount <= redMax
            && this->greenCount <= greenMax
            && this->blueCount <= blueMax
            ) {
            return true;
        }
        return false;
    }


private:
    int gameId;

    int redCount;
    int greenCount;
    int blueCount;

    std::vector<std::string> parseRounds(std::string gameData) {
        std::vector<std::string> rounds = this->splitString(gameData, "; ");
        return rounds;
    };

    std::vector<std::string> parseRoundInfo(std::string roundsString) {
        std::vector<std::string> informations = this->splitString(roundsString, ", ");
        return informations;
    }

    void calculateResults(std::string informationString) {
        std::vector <std::string> colorInfo = this->splitString(informationString, " ");

        std::string ballColor = colorInfo[1];
        int ballCount = std::stoi(colorInfo[0]);

        if (ballColor == "red") {
            this->redCount += ballCount;
        }

        if (ballColor == "green") {
            this->greenCount += ballCount;
        }

        if (ballColor == "blue") {
            this->blueCount += ballCount;
        }
    }

    std::vector<std::string> static splitString(std::string string, std::string delimiter) {
        std::vector<std::string> stringContainer;
        size_t pos = 0;
        std::string token;
        while ((pos = string.find(delimiter)) != std::string::npos) {
            token = string.substr(0, pos);
            // std::cout << token << std::endl;
            stringContainer.push_back(token);
            string.erase(0, pos + delimiter.length());
        }
        stringContainer.push_back(string);
        return stringContainer;
    }

    std::map<std::string, std::string> parseGameString(std::string line) {
        std::map<std::string, std::string> results;

        std::vector<std::string> parsedString = Game::splitString(line, ": ");

        std::string gameName = parsedString[0];
        std::string gameData = parsedString[1];

        results["gameName"] = gameName;
        results["gameData"] = gameData;

        return results;
    }

    int parseGameId(std::string gameIdStr) {
        std::vector<std::string> parsedGameId = Game::splitString(gameIdStr, " ");
        return std::stoi(parsedGameId[1]);
    }



};

int main()
{
    // Create and open a text file
    std::string line;
    std::ifstream MyFile("../exercise.txt");

    int total = 0;

    while (getline(MyFile, line))
    {
        std::map<std::string, std::string> gameObject;
        int length = line.length();

        Game myGame(line);
        if (myGame.isGameLegal(12, 13, 14)) {
            total += myGame.getGameId();
        }

        // parser les différents rounds
 // Parser l'id de la game
 // créer un objet game
 // 

    }
    std::cout << total;

    MyFile.close();
    return 0;
}
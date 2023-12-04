#include <string>
#include <map>
#include <iostream>
// #include "Game.hpp"

class Game {
public:
    Game(std::string gameString) {

        this->redCount = 0;
        this->greenCount = 0;
        this->blueCount = 0;

        std::map<std::string, std::string> gameMap = this->parseGameString(gameString);
        this->gameId = this->parseGameId(gameMap["gameName"]);
        std::cout << "Game id = " << this->gameId << std::endl;
    };

    void newRound(std::string roundStr) {

    };

    // bool isGameLegal(int redMax, int greenMax, int blueMax) {

    // }
private:
    int gameId;

    int redCount;
    int greenCount;
    int blueCount;

    std::map<std::string, int> parseRoundString(std::string);

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
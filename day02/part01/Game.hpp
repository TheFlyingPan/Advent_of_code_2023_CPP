#include <string>
#include <map>

class Game {

public:
    Game(std::string gameString);

    void newRound(std::string roundStr);

    // bool isGameLegal(int redMax, int greenMax, int blueMax);
private:
    int gameId;

    int redCount;
    int greenCount;
    int blueCount;

    std::map<std::string, int> parseRoundString(std::string);

    std::vector<std::string> static splitString(std::string string, std::string delimiter);

    std::map<std::string, std::string> parseGameString(std::string line);

    int parseGameId(std::string gameIdStr);


};
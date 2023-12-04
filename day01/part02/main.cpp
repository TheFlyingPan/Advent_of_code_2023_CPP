#include <iostream>
#include <fstream>
#include <map>
#include <variant>
#include <ctype.h>
using namespace std;

map<string, int> parse_map{
    {"nine", 9},
    {"eight", 8},
    {"seven", 7},
    {"six", 6},
    {"five", 5},
    {"four", 4},
    {"three", 3},
    {"two", 2},
    {"one", 1}
};

// int hasDigitValue(std::string token) {

//  }

std::vector<int> findTokenInStr(std::string str) {
    std::vector<int> results;
    std::string subString;
    int strLen = str.length();
    for (int i = 0; i < strLen; i++) {

        subString = str.substr(i, strLen);
        std::string currentWord;

        for (char& c : subString) {
            currentWord += c;
            if (parse_map[currentWord] != 0) {
                results.push_back(parse_map[currentWord]);
            }

        }
    }

    return results;
}



std::vector<std::string> getSubstrings(std::string line) {
    std::vector<std::string> results;
    std::string currentBuffer = "";

    for (char& c : line) {
        if (isdigit(c)) {
            if (currentBuffer != "") {
                results.push_back(currentBuffer);
                currentBuffer = c;
                results.push_back(currentBuffer);
                currentBuffer = "";
            }
            else {
                currentBuffer = c;
                results.push_back(currentBuffer);
                currentBuffer = "";
            }
        }
        else {
            currentBuffer += c;
        }
    }
    if (currentBuffer != "") {
        results.push_back(currentBuffer);
    }

    return results;
}

// array de substr 
// foreach si string decouper en vector d'int
// si digit alors

int main()
{
    // Create and open a text file
    string line;
    ifstream MyFile("../exercise.txt");

    std::string firstDigit;
    std::string lastDigit;

    int totalValueCount = 0;
    while (getline(MyFile, line))
    {
        std::vector<int> allLineDigits;
        int lineTotal;
        std::string currentBuffer;

        for (char& c : line) {
            // std::cout << c << std::endl;
            if (isdigit(c)) {
                if (currentBuffer != "") {
                    std::vector<int> tokenParsing = findTokenInStr(currentBuffer);
                    for (int i : tokenParsing) {
                        allLineDigits.push_back(i);
                    }
                }
                // std::cout << static_cast<int> (c) << std::endl;
                currentBuffer = c;
                allLineDigits.push_back(std::stoi(currentBuffer));
                currentBuffer = "";
            }
            else {
                currentBuffer += c;
            }
        }
        if (currentBuffer != "") {

            std::vector<int> tokenParsing = findTokenInStr(currentBuffer);
            for (int i : tokenParsing) {
                allLineDigits.push_back(i);
            }
        }
        for (int i : allLineDigits) {
            // std::cout << i << std::endl;
        }
        firstDigit = std::to_string(allLineDigits[0]);
        lastDigit = std::to_string(allLineDigits.back());
        lineTotal = std::stoi(firstDigit + lastDigit);
        totalValueCount += lineTotal;
        // std::cout << lineTotal << "\n";

    }
    std::cout << totalValueCount << std::endl;
    // Close the file
    MyFile.close();
}
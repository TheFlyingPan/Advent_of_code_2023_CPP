#include <iostream>
#include <fstream>
#include <ctype.h>
using namespace std;

int main()
{
    // Create and open a text file
    string line;
    ifstream MyFile("../exercise.txt");

    int totalValueCount = 0;

    while (getline(MyFile, line))
    {
        int length = line.length();
        std::string firstDigit;
        std::string lastDigit;
        bool digitsInitialized = false;
        // boucler sur chaque caractere, si c'est un chiffre on l'enregistre
        for (int i = 0; i < length; i++) {
            if (isdigit(line[i])) {
                if (!digitsInitialized) {
                    firstDigit = lastDigit = line[i];
                    digitsInitialized = true;
                }
                else {
                    lastDigit = line[i];
                }
            }
        }

        std::string totalDigitStr = firstDigit + lastDigit;
        int totalDigit = stoi(totalDigitStr);
        totalValueCount += totalDigit;
        // std::cout << totalDigitStr << std::endl;
    }
    std::cout << totalValueCount << std::endl;
    // Close the file
    MyFile.close();
}
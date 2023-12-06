#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>

void display2dVector(std::vector<std::vector<char>> partMap)
{
    for (std::vector<char> vect : partMap)
    {
        for (char &c : vect)
        {
            std::cout << c;
        }
        std::cout << std::endl;
    }
}

void scanIntString(
    // std::string intString,
    std::vector<std::tuple<int, int>> stringCoordinates,
    std::vector<std::vector<char>> &partMap)
{
    std::string symbols = "";

    // handle first and last element

    for (std::tuple<int, int> coordinate : stringCoordinates)
    { // foreach element in str check around
        int x = std::get<0>(coordinate);
        int y = std::get<1>(coordinate);
        // std::cout << "x = " << x << ", y = " << y;

        // checker les character autour 
        // mais il faut faire attention a ne pas arriver en dehors de l'array
        if (symbols.find(',') != std::string::npos)
        {
        
        }

        std::cout << partMap[y][x];
    }

    std::cout << std::endl;
}

int main()
{
    // Create and open a text file
    std::string line;
    std::ifstream MyFile("../test.txt");

    std::vector<std::vector<char>> partMap;

    // Init par map
    while (getline(MyFile, line))
    {
        std::vector<char> lineData;

        for (char &c : line)
        {
            lineData.push_back(c);
        }
        partMap.push_back(lineData);
    }

    // parcourir l'array
    // si digit -> début d'une chaine
    //      si plus digit -> fin de la chaine et début du scan
    //          first character -> checker tout autour

    int yCoordinates = 0;
    for (std::vector<char> vect : partMap)
    {
        int xCoordinate = 0;
        std::string currentIntStr = "";
        std::vector<std::tuple<int, int>> currentIntCoordinates;

        for (char &c : vect)
        {
            // si la str est pas null alors on ajoute
            // si c'est pas un digit on termine la séquence et on scan
            if (isdigit(c))
            {
                // record les coordonnées du caractere
                currentIntStr += c;
                currentIntCoordinates.push_back({xCoordinate, yCoordinates});
            }
            else if (currentIntStr != "")
            {
                // start sequence
                scanIntString(currentIntCoordinates, partMap);

                currentIntStr = "";
                currentIntCoordinates.clear();
            }
            // si la string est
            // std::cout << c;

            xCoordinate++;
        }
        yCoordinates++;
        // std::cout << std::endl;
    }

    MyFile.close();
    return 0;
}
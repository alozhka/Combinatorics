#include "Knapsack.hpp"

#include <fstream>

std::optional<std::string> parseCmd(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Invalid input type\n";
        return std::nullopt;
    }
    else
    {
        return argv[1];
    }
}

std::optional<InputType> parseInFile(std::string dest)
{
    std::optional<InputType> in;
    std::ifstream inputFile(dest);

    if (!inputFile.is_open())
    {
        std::cout << "Error opening file\n";
        return std::nullopt;
    }
    
    if (!inputFile.eof()) in->n;
    else return std::nullopt;
    if (!inputFile.eof()) in->S;
    else return std::nullopt;
    if (!inputFile.eof()) in->T;
    else return std::nullopt;

    for (size_t i = 0; !inputFile.eof(); i++)
    {
        in->items.push_back({});
        inputFile >> in->items[i].weight;
        inputFile >> in->items[i].cost;
    }
}

void solveBackpack()
{

}
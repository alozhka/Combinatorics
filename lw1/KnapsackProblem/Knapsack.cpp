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
    InputType* in = new InputType;
    std::ifstream inputFile(dest);

    if (!inputFile.is_open())
    {
        std::cout << "Error opening file\n";
        return std::nullopt;
    }
    
    if (!inputFile.eof()) inputFile >> in->n;
    else return std::nullopt;
    if (!inputFile.eof()) inputFile >> in->S;
    else return std::nullopt;
    if (!inputFile.eof()) inputFile >> in->T;
    else return std::nullopt;

    for (size_t weight, cost; !inputFile.eof(); )
    {
        inputFile >> weight;
        inputFile >> cost;
        in->items.push_back({weight, cost});
    }

    return *in;
}

namespace Knapsack
{
    void getCombination
    (
        size_t k, std::vector<size_t>& combs, const std::vector<item>& items, size_t& allW, size_t& allC, size_t limitW,
        size_t limitC, size_t& resultC, size_t& resultW, std::vector<size_t>& resultCombs
    )
    {
        for (int j = 0; j < k; j++)
        {
            if (combs[j] == 1)
            {
                allW += items[j].weight;
                allC += items[j].cost;
            }
        }
        if (allW <= limitW && allC >= limitC)
        {
            if (allC > resultC)
            {
                resultC = allC;
                resultW = allW;
                resultCombs = combs;
            }
        }
        else
        {
            allW = 0;
            allC = 0;
        }
    }
}

void solveKnapsack(size_t k, size_t maxWeight, size_t maxCost, const std::vector<item>& items)
{
    size_t i = 0, resultWeight = 0, resultCost = 0, allWeight = 0, allCost = 0;
    std::vector<size_t> resultCombs, combs(k + 1); // combinations

    while (combs[k] != 1)
    {
        Knapsack::getCombination(k, combs, items, allWeight, allCost, maxWeight, maxCost, resultCost, resultWeight, resultCombs);
        i = 0;
        while (combs[i] == 1)
        {
            combs[i] = 0;
            i++;
        }
        combs[i] = 1;
    }

    std::cout << "Result combination: ";
    copy(resultCombs.begin(), resultCombs.end() - 1, std::ostream_iterator<size_t>(std::cout, " "));
    std::cout << std::endl;
    std::cout << "Result weight: " << resultWeight << std::endl;
    std::cout << "Result cost: " << resultCost << std::endl;
}
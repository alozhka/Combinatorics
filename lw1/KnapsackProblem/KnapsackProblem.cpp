#include <iostream>
#include "Knapsack.hpp"

using namespace std;


int main(int argc, char* argv[])
{
    optional<string> inFile = parseCmd(argc, argv);
    if (!inFile)
    {
        return 1;
    }

    optional<InputType> in = parseInFile(*inFile);
    if (!in)
    {
        return 1;
    }

    solveKnapsack(in->n, in->S, in->T, in->items);

    return 0;
}
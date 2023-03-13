#pragma once

#include <iostream>
#include <optional>
#include <vector>

struct item
{
    size_t weight = 0, cost = 0;
};
struct InputType
{
    /**
    * n - количество элементов
    * S - максимальную стоимость
    * T - максимальный вес
    */
    size_t n = 0, S = 0, T = 0;
    std::vector<item> items;
};


std::optional<std::string> parseCmd(int argc, char* argv[]);
std::optional<InputType> parseInFile(std::string dest);

void solveKnapsack(size_t k, size_t maxWeight, size_t maxCost, const std::vector<item>& items);
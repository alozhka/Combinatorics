#pragma once

#include <iostream>
#include <optional>
#include <vector>

struct InputType
{
    /**
    * n - количество элементов
    * S - максимальную стоимость
    * T - максимальный вес
    */
    size_t n, S, T;
    std::vector<item> items;
};

struct item
{
    size_t weight = 0, cost = 0;
};

std::optional<std::string> parseCmd(int argc, char* argv[]);
std::optional<InputType> parseInFile(std::string dest);
void solveBackpack();
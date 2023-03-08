#pragma once

#include <iostream>
#include <vector>

using AdjMatrix = std::vector< std::vector<size_t> >;


bool initMatrix(AdjMatrix& adj, const std::string& dest);
void printMatrix(const AdjMatrix& adj);
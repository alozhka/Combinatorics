#include "Graph.hpp"
#include <fstream>

using NodeColor = struct
{
	size_t node, color;
};

bool initMatrix(AdjMatrix& adj, const std::string& dest)
{
	std::ifstream in(dest);
	if (!in.is_open())
	{
		std::cout << "Such file does not exist\n";
		return false;
	}
	else
	{
		size_t amountVert = 0;
		if (in.eof())
		{
			std::cout << "Invalid data structure\n";
			return false;
		}
		else
		{
			in >> amountVert;
		}

		adj.resize(amountVert + 1, std::vector<size_t>(amountVert + 1));

		size_t node1 = 0, node2 = 0, maxnode = 0;
		for (int i = 1; !in.eof() && i <= amountVert; i++)
		{
			if (!in.eof()) in >> node1;
			if (!in.eof()) in >> node2;
			maxnode = std::max(maxnode, std::max(node1, node2));
			if (!in.eof()) in >> adj[node1][node2];
		}

		if (maxnode != amountVert)
		{
			std::cout << "Invalid amount of vertexes\n";
			return false;
		}
	}

	return true;
}
void printMatrix(const AdjMatrix& adj)
{
	size_t size = adj.size();
	std::cout << "* ";
	for (int i = 1; i < size; i++)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
	for (int i = 1; i < size; i++)
	{
		std::cout << i << " ";
		copy(adj[i].begin() + 1, adj[i].end(), std::ostream_iterator<std::size_t>(std::cout, " "));
		std::cout << std::endl;
	}
}
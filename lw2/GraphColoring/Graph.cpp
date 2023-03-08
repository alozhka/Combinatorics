#include "Graph.hpp"
#include <fstream>
#include <unordered_set>

using ColorSet = std::unordered_set<size_t>;

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

		size_t node1 = 0, node2 = 0, weight = 0, maxnode = 0;
		for (int i = 1; !in.eof() && i <= amountVert; i++)
		{
			if (!in.eof()) in >> node1;
			if (!in.eof()) in >> node2;
			maxnode = std::max(maxnode, std::max(node1, node2));
			if (!in.eof()) in >> weight;
			adj[node1][node2] = weight;
			adj[node2][node1] = weight;
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

ColorSet findNearestNodes(const AdjMatrix& adj, const size_t& node)
{
	ColorSet s;
	size_t amountVert = adj.size() - 1;
	for (int i = 1; i <= amountVert; i++)
	{
		if (adj[node][i])
		{
			s.insert(i);
		}
	}
	for (auto el : s) std::cout << el;
	return s;
}
ColorSet findSecondOrderNodes(const AdjMatrix& adj, const size_t& node)
{
	ColorSet s, nearest = findNearestNodes(adj, node);
	size_t amountVert = adj.size() - 1;

	for (int i = 1; i <= amountVert; i++)
	{
		if (!adj[node][i] && node != i)
		{
			s.insert(i);
		}
	}
	return s;
}
void connectNodes(const AdjMatrix& adj, const size_t& node1, const size_t& node2)
{

}

void graphColoring(AdjMatrix& adj)
{
	size_t amountVert = adj.size() - 1;
	std::vector<size_t> nodeColors(amountVert);
	ColorSet remote, colored;

	
	for (size_t node = 1, color = 1; color <= amountVert; color++)
	{
		// выбираем любую вершину и красим
		colored.insert(node);
		nodeColors[node] = color;

		// находим вершину окрестности 2 порядка
		remote = findSecondOrderNodes(adj, node);

		// красим вершину 2 порядка
		node = *remote.begin();
		colored.insert(node);
		nodeColors[node] = color;

		//склеиваем вершины
	}
}

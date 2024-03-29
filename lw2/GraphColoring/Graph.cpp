﻿#include "Graph.hpp"
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
		for (int i = 1; !in.eof(); i++)
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
	return s;
}
ColorSet findSecondOrderNodes(const AdjMatrix& adj, const size_t& node)
{
	ColorSet s, nearestNodes = findNearestNodes(adj, node);
	size_t amountVert = adj.size() - 1;

	for (auto nearestNode : nearestNodes)
	{
		for (int i = 1; i <= amountVert; i++)
		{
			if (adj[nearestNode][i] && (node != i) && !nearestNodes.count(i))
			{
				s.insert(i);
			}
		}
	}

	return s;
}

void connectNodes(AdjMatrix& adj, const size_t& destNode, const size_t& sourceNode)
{
	size_t amountNodes = adj.size() - 1;
	for (int i = 1; i <= amountNodes; i++)
	{
		adj[destNode][i] |= adj[sourceNode][i];
		adj[sourceNode][i] = 0;
	}
	for (int i = 1; i <= amountNodes; i++)
	{
		adj[i][destNode] |= adj[i][sourceNode];
		adj[i][sourceNode] = 0;
	}
}

size_t getNotColoredNode(const ColorSet& isColored, const size_t amountVert, size_t& color)
{
	for (int i = 1; i <= amountVert; i++)
	{
		if (!isColored.count(i))
		{
			color++;
			return i;
		}
	}
	if (isColored.empty())
	{
		return 1;
	}
}

void graphColoring(AdjMatrix adj)
{
	size_t amountVert = adj.size() - 1;
	std::vector<size_t> nodeColors(amountVert + 1);
	ColorSet remoteNodes, isColored;

	remoteNodes = findSecondOrderNodes(adj, 1);
	for (size_t color = 0, node = 1, secondNode = 0; isColored.size() < amountVert; node = 1)
	{
		//берём незакрашенную вершину
		node = getNotColoredNode(isColored, amountVert, color);

		// красим её текущим цветом
		isColored.insert(node);
		nodeColors[node] = color;

		// берём любой узел 2-го порядка, красим его, 
		// склеиваем с текущим, повторяем, пока будуут узлы 2-го порядка
		for (
			 remoteNodes = findSecondOrderNodes(adj, node);
			!remoteNodes.empty();
			 remoteNodes = findSecondOrderNodes(adj, node)
			)
		{
			secondNode = *remoteNodes.begin();
			isColored.insert(secondNode);
			nodeColors[secondNode] = color;
			connectNodes(adj, node, secondNode);
		}
	}

	for (int i = 1; i <= amountVert; i++)
	{
		std::cout << i << ": " << nodeColors[i] << std::endl;
	}
}

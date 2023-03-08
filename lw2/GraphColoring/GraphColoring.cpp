#include <iostream>
#include "../GraphsHandler.hpp"
#include <vector>
#include <fstream>
#include <set>

using namespace std;

using AdjMatrix = std::vector< std::vector<size_t> >;
using NodeColor = struct
{
	size_t node, color;
};


//bool initMatrix(AdjMatrix& adj, const std::string& dest)
//{
//	std::ifstream in(dest);
//	if (!in.is_open())
//	{
//		cout << "Such file does not exist\n";
//		return false;
//	}
//	else
//	{
//		size_t amountVert = 0;
//		if (in.eof())
//		{
//			cout << "Invalid data structure\n";
//			return false;
//		}
//		else
//		{
//			in >> amountVert;
//		}
//
//		adj.resize(amountVert + 1, vector<size_t>(amountVert + 1));
//
//		size_t node1 = 0, node2 = 0, maxnode = 0;
//		for (int i = 1;!in.eof() && i <= amountVert; i++)
//		{
//			if (!in.eof()) in >> node1;
//			if (!in.eof()) in >> node2;
//			maxnode = max(maxnode, max(node1, node2));
//			if (!in.eof()) in >> adj[node1][node2];
//		}
//
//		if (maxnode != amountVert)
//		{
//			cout << "Invalid amount of vertexes\n";
//			return false;
//		}
//	}
//
//	return true;
//}
//void printMatrix(const AdjMatrix& adj)
//{
//	size_t size = adj.size();
//	cout << "* ";
//	for (int i = 1; i < size; i++)
//	{
//		cout << i << " ";
//	}
//	cout << endl;
//	for (int i = 1; i < size; i++)
//	{
//		cout << i << " ";
//		copy(adj[i].begin() + 1, adj[i].end(), ostream_iterator<size_t>(cout, " "));
//		cout << endl;
//	}
//}
string getData()
{
	string source;

	cout << "Enter file name: ";
	cin >> source;
	cout << endl;

	return source;
}

void graphColoring(AdjMatrix& adj)
{
	size_t amountVert = adj.size();
	vector<NodeColor> nodeColors(amountVert);
	set<size_t> neighbourhood, colored;
	// выбираем любую вершину и красим
	while (colored.size() <= amountVert)
	{

	}
	// повторяем
	// 
	// находим смежные с ней вершины
	// берём любую из несмежных, красим её в этот же цвет и соединяем в первоначальную
}

int main()
{
	AdjMatrix adj;
	string dest = getData();
	 
	if (initMatrix(adj, dest))
	{
		printMatrix(adj);
	}

	return 0;
}
#include <iostream>

#include <vector>
#include <fstream>
#include <set>

using namespace std;

using AdjMatrix = std::vector< std::vector<size_t> >;
using NodeColor = struct
{
	size_t node, color;
};

void initMatrixMemory(AdjMatrix& adj, const size_t amountVert)
{
	vector<size_t> v;
	for (int i = 0; i <= amountVert; i++)
	{
		v.clear();
		for (int j = 0; j <= amountVert; j++)
		{
			v.push_back(0);
		}
		adj.push_back(v);
	}
}
bool initMatrix(AdjMatrix& adj, const std::string& dest)
{
	std::ifstream in(dest);
	if (!in.is_open())
	{
		cout << "Such file does not exist\n";
		return false;
	}
	else
	{
		size_t amountVert = 0;
		if (in.eof())
		{
			cout << "Invalid data structure\n";
			return false;
		}
		else
		{
			in >> amountVert;
		}

		initMatrixMemory(adj, amountVert);

		size_t node1 = 0, node2 = 0;
		int i;
		for (i = 1;!in.eof(), i <= amountVert; i++)
		{
			if (!in.eof()) in >> node1;
			if (!in.eof()) in >> node2;
			if (!in.eof()) in >> adj[node1][node2];
		}

		if (i - 1 != amountVert)
		{
			cout << "Invalid amount of vertexes\n";
			return false;
		}
	}

	return true;
}
void printMatrix(AdjMatrix& adj)
{
	size_t size = adj.size();
	cout << "* ";
	for (int i = 1; i < size; i++)
	{
		cout << i << " ";
	}
	cout << endl;
	for (int i = 1; i < size; i++)
	{
		cout << i << " ";
		copy(adj[i].begin(), adj[i].end(), ostream_iterator<size_t>(cout, " "));
		cout << endl;
	}
}
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

	initMatrix(adj, dest);

	return 0;
}
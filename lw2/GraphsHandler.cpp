#include <fstream>

void initMatrixMemory(AdjMatrix& adj, size_t amountVert)
{
	vector<size_t> v;
	for (int i = 0; i <= amountVert; i++)
	{
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
		for (i = 1; !in.eof(), i <= amountVert; i++)
		{
			if (!in.eof()) in >> node1;
			if (!in.eof()) in >> node2;
			if (!in.eof()) in >> adj[node1][node2];
		}

		if (i != amountVert)
		{
			cout << "Invalid amount of vertexes\n";
			return false;
		}
	}

	return true;
}
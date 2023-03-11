#include <iostream>
#include <optional>
#include "Graph.hpp"

using namespace std;

optional<string> parseCmd(const int argc, char* argv[])
{
	string source;

	if (argc != 2)
	{
		cout << "Invalid input data\n";
		return nullopt;
	}
	else
	{
		return argv[1];
	}
}


int main(int argc, char* argv[])
{
	AdjMatrix adj;
	auto dest = parseCmd(argc, argv);
	 
	if (!dest)
	{
		return 1;
	}
	else
	{
		if (initMatrix(adj, *dest))
		{
			graphColoring(adj);
		}
		else
		{
			return 1;
		}
	}

	return 0;
}
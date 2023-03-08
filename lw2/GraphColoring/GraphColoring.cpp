#include <iostream>
#include "Graph.hpp"

using namespace std;

string getData()
{
	string source;

	cout << "Enter file name: ";
	cin >> source;
	cout << endl;

	return source;
}


int main()
{
	AdjMatrix adj;
	string dest = getData();
	 
	if (!initMatrix(adj, dest))
	{
		return 1;
	}
	else
	{
		printMatrix(adj);
		graphColoring(adj);
	}

	return 0;
}
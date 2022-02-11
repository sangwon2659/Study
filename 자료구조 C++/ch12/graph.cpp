#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> get_adj_list(const vector<vector<int>>& adj_matrix)
{
	vector<vector<int>> adj_list(adj_matrix.size());

	for (int u = 0; u < adj_matrix.size(); u++) {
		for (int v = 0; v < adj_matrix[u].size(); v++) {
			if (adj_matrix[u][v] == 1)
				adj_list[u].push_back(v);
		}
	}

	return adj_list;
}

int main()
{
	// 인접 행렬(adjacency matrix)
	vector<vector<int>> adj_matrix = {
		{0, 1, 0, 1, 1, 0},
		{1, 0, 1, 0, 1, 0},
		{0, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1, 0},
		{1, 1, 0, 1, 0, 0},
		{0, 0, 1, 0, 0, 0}
	};

/*
	// 인접 리스트(adjacency list)
	vector<vector<int>> adj_list = {
		{1, 3, 4},
		{0, 2, 4},
		{1, 5},
		{0, 4},
		{0, 1, 3},
		{2}
	};
*/

	vector<vector<int>> adj_list = get_adj_list(adj_matrix);

	for (const auto& l : adj_list) {
		for (const auto n : l)
			cout << n << ", ";
		cout << endl;
	}
}
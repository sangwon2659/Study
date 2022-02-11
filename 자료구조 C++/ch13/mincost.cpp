#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> m)
{
	int rows = (int)m.size();
	int cols = (int)m[0].size();

	vector<vector<int>> dp(rows, vector<int>(cols, 0));

	for (int y = 0; y < rows; y++) {
		for (int x = 0; x < cols; x++) {
			if (x == 0 && y == 0)
				dp[y][x] = m[y][x];
			else if (x == 0)
				dp[y][x] = dp[y - 1][x] + m[y][x];
			else if (y == 0)
				dp[y][x] = dp[y][x - 1] + m[y][x];
			else
				dp[y][x] = min(dp[y - 1][x], dp[y][x - 1]) + m[y][x];
		}
	}

	return dp[rows - 1][cols - 1];
}

int main()
{
	vector<vector<int>> m = {
		{2, 7, 5, 4},
		{5, 3, 6, 8},
		{7, 8, 7, 4},
		{8, 1, 9, 5}
	};

	cout << "Minimum cost: " << solution(m) << endl;
}

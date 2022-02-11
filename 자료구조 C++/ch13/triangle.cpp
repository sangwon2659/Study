#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle)
{
	vector<vector<int>> dp = triangle;

	int n = triangle.size();

	for (int y = 1; y < n; y++) {
		for (int x = 0; x <= y; x++) {
			if (x == 0)
				dp[y][x] = dp[y - 1][x] + triangle[y][x];
			else if (x == y)
				dp[y][x] = dp[y - 1][x - 1] + triangle[y][x];
			else
				dp[y][x] = max(dp[y - 1][x - 1], dp[y - 1][x]) + triangle[y][x];
		}
	}

	return *max_element(dp[n - 1].begin(), dp[n - 1].end());
}

int main()
{
	vector<vector<int>> tri {
		{7},
		{3, 8},
		{8, 1, 0},
		{2, 7, 4, 4},
		{4, 5, 2, 6, 5}
	};

	cout << solution(tri) << endl;
}
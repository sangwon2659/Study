#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> computers)
{
	vector<bool> visited(n, false);
	int num_networks = 0;

	for (int i = 0; i < n; i++) {

		if (visited[i])
			continue;

		queue<int> q;
		q.push(i);

		while (!q.empty()) {
			int v = q.front();
			q.pop();

			if (visited[v])
				continue;

			visited[v] = true;

			for (int j = 0; j < n; j++) {
				if (v != j && computers[v][j] == 1 && !visited[j])
					q.push(j);
			}
		}

		num_networks++;
	}

	return num_networks;
}

int main()
{
	cout << solution(3, {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}}) << endl; // 2
	cout << solution(3, {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}}) << endl; // 1
}

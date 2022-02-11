#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void print_vector(const vector<T>& vec)
{
	for (const auto& e : vec)
		cout << e << " ";
	cout << endl;
}

void permutation(vector<int>& vec, int k)
{
	if (k == vec.size() - 1) {
		print_vector(vec);
		return;
	}

	for (int i = k; i < vec.size(); i++) {
		swap(vec[k], vec[i]);
		permutation(vec, k + 1);
		swap(vec[k], vec[i]);  // 순서 원복
	}
}

int main()
{
	// 재귀 알고리즘 사용 예제
	vector<int> vec {1, 2, 3, 4};
	permutation(vec, 0);

	// std::next_permutation() 사용 예제
	sort(vec.begin(), vec.end());

	do {
		print_vector(vec);
	} while (next_permutation(vec.begin(), vec.end()));
}

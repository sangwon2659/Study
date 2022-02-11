#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

class hash_set
{
private:
	int sz;
	std::vector<std::list<int>> data;

public:
	hash_set(int n) : sz(n), data(sz) {}

	int hash(int key)
	{
		return key % sz;
	}

	void insert(int value)
	{
		data[hash(value)].push_back(value);
	}

	bool find(int value)
	{
		auto& entries = data[hash(value)];
		return std::find(entries.begin(), entries.end(), value) != entries.end();
	}

	void erase(int value)
	{
		auto& entries = data[hash(value)];
		auto it = std::find(entries.begin(), entries.end(), value);

		if (it != entries.end()) {
			entries.erase(it);
		}
	}

	void print()
	{
		for (int i = 0; i < sz; i++) {
			std::cout << i << ": ";
			for (auto n : data[i]) {
				std::cout << n << ", ";
			}
			std::cout << std::endl;
		}
	}
};

using namespace std;

int main()
{
	hash_set num_set(7);

	num_set.insert(10);
	num_set.insert(15);
	num_set.insert(20);
	num_set.insert(100);

	int value = 10;
	if (num_set.find(value))
		cout << value << " is found!" << endl;
	else
		cout << value << " is NOT found!" << endl;

	num_set.insert(2);

	value = 100;
	if (num_set.find(value))
		cout << value << " is found!" << endl;
	else
		cout << value << " is NOT found!" << endl;

	num_set.print();
}

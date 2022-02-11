#include <iostream>
#include <vector>

class hash_set
{
private:
	int sz;
	std::vector<int> data;

public:
	hash_set(int n) : sz(n), data(sz, -1) {}

	int hash(int key)
	{
		return key % sz;
	}

	void insert(int value)
	{
		data[hash(value)] = value;
	}

	bool find(int value)
	{
		return (data[hash(value)] == value);
	}

	void erase(int value)
	{
		data[hash(value)] = -1;
	}

	void print()
	{
		for (auto n : data)
			std::cout << n << ", ";
		std::cout << std::endl;
	}
};

using namespace std;

int main()
{
	hash_set num_set(7);

	num_set.insert(10); // 3
	num_set.insert(15); // 1
	num_set.insert(20); // 6
	num_set.insert(100); // 2
	num_set.print();

	int value = 10;
	if (num_set.find(value))
		cout << value << " is found!" << endl;
	else
		cout << value << " is NOT found!" << endl;

	num_set.insert(2);
	num_set.print();

	value = 100;
	if (num_set.find(value))
		cout << value << " is found!" << endl;
	else
		cout << value << " is NOT found!" << endl;
}

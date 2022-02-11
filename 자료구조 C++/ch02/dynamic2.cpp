#include <iostream>

using namespace std;

template <typename T>
class DynamicArray
{
private:
	unsigned int sz;
	T* arr;

public:
	DynamicArray(int n) : sz(n) {
		arr = new T[sz] {};
	}

	~DynamicArray() { 
		delete [] arr;
		cout << "memory deleted!" << endl;
	}

	unsigned int size() { return sz; }

	T& operator[] (const int i) { return arr[i]; }
	const T& operator[] (const int i) const { return arr[i]; }
};

int main()
{
	DynamicArray<int> da(5);
	da[0] = 10;
	da[1] = 20;
	da[2] = 30;

	for (int i = 0; i < da.size(); i++)
		cout << da[i] << endl;
}
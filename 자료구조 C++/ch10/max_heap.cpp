#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class MaxHeap
{
private:
	vector<int> vec;

public:
	MaxHeap() : vec(1) {}

	void push(int value)
	{
		vec.push_back(value);
		heapify_up(vec.size() - 1);
	}

	void pop()
	{
		vec[1] = vec.back();
		vec.pop_back();
		heapify_down(1);
	}

	int top() const { return vec[1]; }

	void clear() { vec.clear(); vec.push_back(0); }
	int size() { return vec.size() - 1; }
	bool empty() { return vec.size() == 1; }

	void print()
	{
		for (auto n : vec)
			cout << n << ", ";
		cout << endl;
	}

private:
	int parent(int i) { return i / 2; }
	int left(int i) { return 2 * i; }
	int right(int i) { return 2 * i + 1; }

	void heapify_up(int i)
	{
		if (i > 1 && vec[i] > vec[parent(i)]) {
			swap(vec[i], vec[parent(i)]);
			heapify_up(parent(i));
		}
	}

	void heapify_down(int i)
	{
		int largest = i;

		if (left(i) < vec.size() && vec[left(i)] > vec[largest]) {
			largest = left(i);
		}

		if (right(i) < vec.size() && vec[right(i)] > vec[largest]) {
			largest = right(i);
		}

		if (largest != i) {
			swap(vec[i], vec[largest]);
			heapify_down(largest);
		}
	}
};

int main()
{
	MaxHeap heap;
	heap.push(10);
	heap.push(5);
	heap.push(15);
	heap.push(7);
	heap.push(3);
	heap.push(9);
	heap.push(14);
	heap.push(8);
	heap.push(2);
	heap.push(4);
	heap.print();

	while (!heap.empty()) {
		cout << heap.top() << ", ";
		heap.pop();
	}
	cout << endl;
}

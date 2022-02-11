#include <algorithm>
#include <iostream>

using namespace std;

int partition(int data[], int left, int right)
{
	int pivot = data[left];
	int i = left + 1;
	int j = right;

	while (true) {
		while (data[i] <= pivot && i <= right)
			i++;

		while (data[j] > pivot && j > left)
			j--;

		if (i < j) {
			swap(data[i], data[j]);
		}
		else
			break;
	}

	swap(data[left], data[j]);

	return j;
}

void quick_sort(int data[], int left, int right)
{
	if (left < right) {
		int p = partition(data, left, right);
		quick_sort(data, left, p - 1);
		quick_sort(data, p + 1, right);
	}
}

int main()
{
	int data[] = { 5, 6, 7, 3, 1, 9, 2, 4, 8 };
	quick_sort(data, 0, size(data) - 1);

	for (auto n : data)
		cout << n << ", ";
	cout << endl;
}

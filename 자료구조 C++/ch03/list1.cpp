#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> l1;
	l1.push_back(10);  // 10
	l1.push_back(20);  // 10, 20

	list<int> l2 {10, 20, 30, 40};
	
	for (auto a : l2)
		cout << a << ", ";
	cout << endl;

	l2.splice(l2.end(), l1);  // 10, 20, 30, 40, 10, 20

	for (auto a : l2)
		cout << a << ", ";
	cout << endl;

	l2.sort();  // 10, 10, 20, 20, 30, 40

	for (auto a : l2)
		cout << a << ", ";
	cout << endl;	

	l2.unique();  // 10, 20, 30, 40

	for (auto a : l2)
		cout << a << ", ";
	cout << endl;		
}
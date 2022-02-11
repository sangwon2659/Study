#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
	set<int> odds {1, 7, 5, 3, 9};
	set<int, greater<>> evens {2, 4, 6, 8};
	evens.insert(10);
	evens.insert(2);

	if (evens.find(4) != evens.end())
		cout << "4 is found!" << endl;
	else
		cout << "4 is not found!" << endl;

	for (auto n : odds)
		cout << n << ", ";
	cout << endl;

	for (auto n : evens)
		cout << n << ", ";
	cout << endl;	

	using psi = pair<string, int>;

	set<psi> managers {{"Amelia", 29}, {"Noah", 25}, {"Olivia", 31},
		{"Sophia", 40}};
	managers.insert({"George", 35});

	psi person1 = {"Noah", 25};
	if (managers.find(person1) != managers.end())
		cout << person1.first << " is a manager!" << endl;
	else
		cout << person1.first << " is not a manager!" << endl;
	
	managers.erase({"Sophia", 40});
	managers.erase({"Noah", 30});

	for (const auto& m : managers)
		cout << m.first << "(" << m.second << ")" << endl;
}

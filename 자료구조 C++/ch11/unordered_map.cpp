#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
	unordered_map<string, int> fruits;
	fruits.insert({"apple", 1000});
	fruits.insert({"banana", 1500});
	fruits["orange"] = 3000;
	fruits["grape"] = 4000;
	fruits["lemon"] = 5000;

	fruits["apple"] = 2000;
	fruits.erase("grape");

	for (auto [name, price] : fruits)
		cout << name << " is " << price << " won." << endl;
}

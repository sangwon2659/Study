#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

int main()
{
	// car -> radio -> orange -> ear -> radio
	unordered_set<string> words;
	words.insert("car");
	words.insert("radio");
	words.insert("orange");
	words.insert("ear");
	
	string word = "radio";
	if (words.find(word) != words.end())
		cout << word << " is used!" << endl;
	else
		cout << word << " is NOT used!" << endl;

	vector<int> numbers {1, 5, 3, 1, 5, 7, 4, 5, 6, 3, 2, 7, 3, 6, 2};
	unordered_set<int> num_set(numbers.begin(), numbers.end());
	cout << num_set.size() << endl;

}

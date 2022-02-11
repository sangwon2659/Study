#include <iostream>
#include <string>

using namespace std;

string reverse(const string& str)
{
	if (str.length() == 0)
		return "";
	else
		return reverse(str.substr(1)) + str[0];
}

int main()
{
	string str = "Hello";
	cout << reverse(str) << endl;
}
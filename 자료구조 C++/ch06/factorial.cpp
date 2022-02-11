#include <iostream>

using namespace std;

long long factorial(int n)
{
	if (n == 0)
		return 1;
	else
		return n * factorial(n - 1);
}

int main()
{
	cout << factorial(5) << endl;  // 120
	cout << factorial(10) << endl; // 3628800
	cout << factorial(20) << endl; // 2432902008176640000
}
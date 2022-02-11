#include <iostream>

using namespace std;

long long fibo(int n)
{
	if (n <= 1)
		return n;
	else
		return fibo(n - 1) + fibo(n - 2);
}

int main()
{
	for (int i = 1; i <= 10; i++)
		cout << fibo(i) << ", ";
	cout << endl;
}
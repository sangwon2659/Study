#include <iostream>
#include <vector>

using namespace std;

int fibo1(int n)
{
	if (n <= 1)
		return n;

	return fibo1(n - 1) + fibo1(n - 2);
}

vector<int> memo(50, -1);

int fibo2(int n)
{
	if (n < 2)
		return n;

	if (memo[n] != -1)
		return memo[n];
	
	memo[n] = fibo2(n - 2) + fibo2(n - 1);
	return memo[n];
}

int fibo3(int n)
{
	vector<int> dp(n + 1, 0);
	dp[1] = 1;

	for (int i = 2; i <= n; i++)
		dp[i] = dp[i - 2] + dp[i - 1];

	return dp[n];
}

int main()
{
	int n = 5;
	cout << fibo1(n) << endl;
	cout << fibo2(n) << endl;
	cout << fibo3(n) << endl;
}
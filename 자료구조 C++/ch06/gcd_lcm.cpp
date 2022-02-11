#include <iostream>
#include <numeric>

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

int main()
{
	int gcd1 = gcd(10, 15);
	int lcm1 = lcm(10, 15);

	int gcd2 = std::gcd(10, 15);
	int lcm2 = std::lcm(10, 15);

	std::cout << gcd1 << ", " << gcd2 << std::endl;
	std::cout << lcm1 << ", " << lcm2 << std::endl;
}
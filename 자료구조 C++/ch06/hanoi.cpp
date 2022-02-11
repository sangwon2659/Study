#include <vector>
#include <iostream>

using namespace std;

void hanoi(int n, int from, int to, int by)
{
	if (n == 1) {
		cout << from << " -> " << to << endl;
	} else {
		hanoi(n - 1, from, by, to);
		cout << from << " -> " << to << endl;
		hanoi(n - 1, by, to, from);
	}
}

int main()
{
	hanoi(2, 1, 3, 2);
	//hanoi(3, 1, 3, 2);
}


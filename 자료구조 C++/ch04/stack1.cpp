#include <iostream>
#include <vector>

template <typename T>
class Stack
{
public:
	Stack() {}

	void push(const T& e) { v.push_back(e); }
	void pop() { v.pop_back(); }
	const T& top() const { return v.back(); }

	bool empty() const { return v.empty(); }
	int size() const { return v.size(); }

private:
	std::vector<T> v;
};

using namespace std;

int main()
{
	Stack<int> stk;
	stk.push(10);
	stk.push(20);
	stk.push(30);
	stk.pop();

	cout << stk.top() << endl;
	stk.push(40);

	while (!stk.empty()) {
		auto& e = stk.top();
		cout << e << ", ";
		stk.pop();
	}
	cout << endl;
}

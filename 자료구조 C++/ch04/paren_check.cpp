#include <iostream>
#include <stack>

using namespace std;

bool paren_check(const string& s)
{
	stack<char> stk;

	for (char c : s) {
		if (c == '(' || c == '{' || c == '[') {
			stk.push(c);
		} else {
			if (stk.empty() || 
				(stk.top() == '(' && c != ')') ||
				(stk.top() == '{' && c != '}') ||
				(stk.top() == '[' && c != ']'))
				return false;

			stk.pop();
		}
	}

	return stk.empty();
}

int main()
{
    // 올바른 괄호
	cout << paren_check("(){}[]") << endl;
	cout << paren_check("((((()))))") << endl;
	cout << paren_check("(){[()]}") << endl;

    // 올바르지 않은 괄호
	cout << paren_check("((({}))") << endl;
	cout << paren_check(")(") << endl;
	cout << paren_check("({)}") << endl;
}

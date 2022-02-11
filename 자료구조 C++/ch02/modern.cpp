#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// using
using uchar = unsigned char;
using pis = pair<int, string>;
using da10 = double[10];
using func = void (*)(int);

template <typename T>
using matrix1d = vector<T>;

void my_function(int n)
{
	cout << "my_function() is called!" << endl;
}

vector<int> odds()
{
	return {1, 3, 5, 7, 9};
}

struct Person
{
	string name;
	int age;
};

int main()
{
	// auto
	auto a1 = 10;		  // int
	auto a2 = 3.14f;	  // float
	auto a3 = "hello";	  // const char*
	auto a4 = "hello"s;	  // std::string
	auto a5 = sqrt(2.0);  // double
	auto a6 = odds();	  // vector<int>
	auto a7 = a6.begin(); // vector<int>::iterator
	auto lambda = [](int x) { return x * 2; };

	// using
	da10 arr {};
	matrix1d<float> vec(3);
	func fp = &my_function;

	// Range-based for
	vector<int> numbers {10, 20, 30};

	for (int n : numbers)
		cout << n << endl;

	for (auto& n : numbers)
		cout << n << endl;

	string str[] = {"I", "love", "you"};

	for (const auto& s : str)
		cout << s << " ";
	cout << endl;

	// lambda expression
	auto square = [](double a) { return a * a; };
	cout << "square(1.414) = " << square(1.414) << endl;

	vector<Person> students;
	students.push_back({"Kim", 20});
	students.push_back({"Lee", 30});
	students.push_back({"Park", 24});
	students.push_back({"Choi", 40});

	sort(students.begin(), students.end(), [](const Person& p1, const Person& p2) {
		return p1.name < p2.name;
	});

	for (const auto& p : students)
		cout << p.name << " : " << p.age << endl;

	// chrono library
	auto start = chrono::system_clock::now();

	// Do something!
	double s = 0;
	for (int i = 1; i <= 10000000; i++) {
		s += sqrt(double(i));
	}

	auto end = chrono::system_clock::now();
	auto msec = chrono::duration<double>(end - start).count() * 1000;
	cout << "Elapsed time: " << msec << "ms." << endl;
}

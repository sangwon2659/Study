#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person
{
public:
	string name;
	int age;

	bool operator<(const Person& p) const
	{
		return this->age < p.age;
	}

	void print() const
	{
		cout << name << ", " << age << endl;
	}
};

bool abs_cmp(const int a, const int b)
{
	return std::abs(a) < std::abs(b);
}

int main()
{
	// 배열의 정렬

	int arr[5] = {4, 2, 3, 5, 1};
	sort(arr, arr + 5); // 오름 차순, [1, 2, 3, 4, 5]
//	sort(begin(arr), end(arr)); // std::begin(), std::end()
//	sort(begin(arr), end(arr), greater<>()); // 내림 차순, [5, 4, 3, 2, 1]

	for (const auto& a : arr)
		cout << a << ", ";
	cout << endl;

	// 벡터의 정렬

	vector<string> vec = {"orange", "banana", "apple", "lemon"};
	sort(vec.begin(), vec.end()); // ["apple", "banana", "lemon", "orange"]
//	sort(vec.begin(), vec.end(), less<>()); // ["apple", "banana", "lemon", "orange"]
//	sort(vec.begin(), vec.end(), greater<>()); // ["orange", "lemon", "banana", apple"]
//	sort(begin(vec), end(vec));

	for (const auto& a : vec)
		cout << a << ", ";
	cout << endl;

	// 비교 방법 지정 예제

	struct AbsCmp {
		inline bool operator()(int a, int b) const
		{
			return std::abs(a) < std::abs(b);
		}
	};

	vector<int> nums = {10, 2, -3, 5, 7};
	sort(nums.begin(), nums.end(), AbsCmp());  // [2, -3, 5, 7, 10]
//	sort(nums.begin(), nums.end(), abs_cmp);  // [2, -3, 5, 7, 10]
//	sort(nums.begin(), nums.end(), [](int a, int b) {
//		return std::abs(a) < std::abs(b);
//	});  // [2, -3, 5, 7, 10]

	for (const auto& a : nums)
		cout << a << ", ";
	cout << endl;

	// 비교 연산자를 오버로딩한 클래스 객체의 정렬
	vector<Person> v;
	v.push_back({"Amelia", 29});
	v.push_back({"Noah", 25});
	v.push_back({"Olivia", 31});
	v.push_back({"Sophia", 40});
	v.push_back({"George", 35});

	sort(v.begin(), v.end());

	for (const auto& p : v)
		p.print();
}

#include <iostream>

#define MAX_QUEUE 10

template <typename T>
class CircularQueue
{
public:
	CircularQueue(int sz = MAX_QUEUE)
	{
		arr = new T[sz];
		front_idx = 0;
		rear_idx = -1;
		count = 0;
		capacity = sz;
	}

	~CircularQueue()
	{
		delete [] arr;
	}

	void enqueue(const T& e)
	{
		if (full()) {
			std::cout << "Overflow error!" << std::endl;
			return;
		}

		rear_idx = (rear_idx + 1) % capacity;
		arr[rear_idx] = e;
		count++;
	}

	void dequeue()
	{
		if (empty()) {
			std::cout << "Underflow error!" << std::endl;
			return;
		}

		front_idx = (front_idx + 1) % capacity;
		count--;
	}

	const T& front() const { return arr[front_idx]; }

	bool empty() const { return count == 0; }
	int full() const { return count == capacity; }
	int size() const { return count; }

private:
	T* arr;
	int front_idx;
	int rear_idx;
	int count;
	int capacity;
};

using namespace std;

int main()
{
	CircularQueue<int> q(5);

	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);  // full 상태
	q.dequeue();
	q.dequeue();    // 원소 2개 삭제
	q.enqueue(60);
	q.enqueue(70);  // full 상태
	q.enqueue(80);  // 오버플로우 에러!

	while (!q.empty()) {
		auto& e = q.front();
		cout << e << ", ";
		q.dequeue();
	}
	cout << endl;
}

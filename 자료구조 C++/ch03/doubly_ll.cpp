#include <iostream>

template <typename T>
struct Node
{
	T data;
	Node* prev;
	Node* next;
};

template <typename T>
class DoublyLinkedList
{
private:
	int count;
	Node<T>* header;
	Node<T>* trailer;

public:
	class iterator
	{
	private:
		Node<T>* ptr;

	public:
		iterator() : ptr(NULL) {}
		iterator(Node<T>* p) : ptr(p) {}

		T& operator*() { return ptr->data; }

		iterator& operator++()	// ++it
		{
			ptr = ptr->next;
			return *this;
		}

		iterator& operator--()	// --it
		{
			ptr = ptr->prev;
			return *this;
		}

		bool operator==(const iterator& it) const
		{
			return ptr == it.ptr;
		}

		bool operator!=(const iterator& it) const
		{
			return ptr != it.ptr;
		}

		friend class DoublyLinkedList;
	};

public:
	DoublyLinkedList()
	{
		count = 0;
		header = new Node<T> {T(), NULL, NULL};
		trailer = new Node<T> {T(), NULL, NULL};
		header->next = trailer;
		trailer->prev = header;
	}

	~DoublyLinkedList()
	{
		while (!empty()) {
			pop_front();
		}

		delete header;
		delete trailer;
	}

	iterator begin() const
	{
		return iterator(header->next);
	}

	iterator end() const
	{
		return iterator(trailer);
	}

	// pos가 가리키는 노드 앞에 val 값을 갖는 새로운 노드를 삽입
	void insert(const iterator& pos, const T& val)
	{
		Node<T>* p = pos.ptr;
		Node<T>* new_node = new Node<T> {val, p->prev, p};
		new_node->prev->next = new_node;
		new_node->next->prev = new_node;
		count++;
	}

	void push_front(const T& val)
	{
		insert(begin(), val);
	}

	void push_back(const T& val)
	{
		insert(end(), val);
	}

	// pos가 가리키는 노드를 삭제
	void erase(const iterator& pos)
	{
		Node<T>* p = pos.ptr;
		p->prev->next = p->next;
		p->next->prev = p->prev;
		delete p;
		count--;
	}

	void pop_front()
	{
		if (!empty())
			erase(begin());
	}

	void pop_back()
	{
		if (!empty())
			erase(--end());
	}

	iterator find(const T& val)
	{
		Node<T>* curr = header->next;

		while (curr->data != val && curr != trailer)
			curr = curr->next;

		return iterator(curr);
	}

	bool empty() const
	{
		return count == 0;
	}

	int size() const
	{
		return count;
	}
};

using namespace std;

int main()
{
	DoublyLinkedList<int> ll;
	ll.push_back(10);
	ll.push_back(20);
	ll.push_back(30);

	// ll: header -> 10 -> 20 -> 30 -> trailer

	auto it = ll.find(20);
	if (it != ll.end())
		ll.insert(it, 50);

	// ll: header -> 10 -> 50 -> 20 -> 30 -> trailer

	for (const auto& a : ll)
		cout << a << ", ";
	cout << endl;
}

#include <iostream>

struct Node
{
	int data;
	Node* prev;
	Node* next;
};

class DoublyLinkedList
{
private:
	int count;
	Node* header;
	Node* trailer;

public:
	DoublyLinkedList()
	{
		count = 0;
		header = new Node {0, NULL, NULL};
		trailer = new Node {0, NULL, NULL};
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

	// 노드 p 앞에 val 값을 갖는 새로운 노드를 삽입
	void insert(Node* p, int val)
	{
		Node* new_node = new Node {val, p->prev, p};
		new_node->prev->next = new_node;
		new_node->next->prev = new_node;
		count++;
	}

	void push_front(int val)
	{
		insert(header->next, val);
	}

	void push_back(int val)
	{
		insert(trailer, val);
	}

	// 노드 p를 삭제
	void erase(Node* p)
	{
		p->prev->next = p->next;
		p->next->prev = p->prev;
		delete p;
		count--;
	}

	void pop_front()
	{
		if (!empty())
			erase(header->next);
	}

	void pop_back()
	{
		if (!empty())
			erase(trailer->prev);
	}

	bool empty() const
	{
		return count == 0;
	}

	int size() const
	{
		return count;
	}

	void print_all() const
	{
		Node* curr = header->next;

		while (curr != trailer) {
			std::cout << curr->data << ", ";
			curr = curr->next;
		}

		std::cout << std::endl;
	}

	void print_reverse() const
	{
		Node* curr = trailer->prev;

		while (curr != header) {
			std::cout << curr->data << ", ";
			curr = curr->prev;
		}

		std::cout << std::endl;
	}
};

int main()
{
	DoublyLinkedList ll;
	ll.push_back(10);
	ll.push_back(20);
	ll.push_back(30);
	ll.print_all();
	ll.print_reverse();

	// ll: header -> 10 -> 20 -> 30 -> trailer

	ll.pop_front();
	ll.pop_back();
	ll.print_all();

	ll.push_front(100);
	ll.push_back(400);
	ll.print_all();
}

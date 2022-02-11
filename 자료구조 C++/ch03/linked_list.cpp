#include <iostream>

struct Node
{
	int data;
	Node* next;
};

class LinkedList
{
private:
	Node* head;

public:
	LinkedList() : head(NULL) {};

	~LinkedList()
	{
		while (!empty()) {
			pop_front();
		}
	}

	void push_front(int val)
	{
		Node* new_node = new Node {val, head};

		if (head != NULL)
			new_node->next = head;

		head = new_node;
	}

	void pop_front()
	{
		if (head == NULL)
			return;

		Node* first = head;
		head = head->next;
		delete first;
	}

	bool empty() const
	{
		return head == NULL;
	}

	void print_all() const
	{
		Node* curr = head;

		while (curr != NULL) {
			std::cout << curr->data << ", ";
			curr = curr->next;
		}

		std::cout << std::endl;
	}
};

int main()
{
	LinkedList ll;
	ll.push_front(10);
	ll.push_front(20);
	ll.push_front(30);
	ll.print_all();

	ll.pop_front();
	ll.print_all();

	ll.push_front(40);
	ll.print_all();
}


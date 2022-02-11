#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;

	Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

class BinarySearchTree
{
private:
	Node* root = nullptr;

public:
	~BinarySearchTree()
	{
		delete_tree(root);
	}

	void insert(int value)
	{
		if (!root)
			root = new Node(value);
		else
			insert_impl(root, value);
	}

	Node* find(int value)
	{
		return find_impl(root, value);
	}

	void inorder()
	{
		inorder_impl(root);
	}

	void erase(int value)
	{
		root = erase_impl(root, value);
	}

private:
	void insert_impl(Node* curr, int value)
	{
		if (value < curr->data) {
			if (!curr->left)
				curr->left = new Node(value);
			else
				insert_impl(curr->left, value);
		} else {
			if (!curr->right)
				curr->right = new Node(value);
			else
				insert_impl(curr->right, value);
		}
	}

	Node* find_impl(Node* curr, int value)
	{
		if (curr == nullptr)
			return nullptr;

		if (value == curr->data)
			return curr;
		else {
			if (value < curr->data)
				return find_impl(curr->left, value);
			else
				return find_impl(curr->right, value);
		}
	}

	void inorder_impl(Node* curr)
	{
		if (curr) {
			inorder_impl(curr->left);
			std::cout << curr->data << ", ";
			inorder_impl(curr->right);
		}
	}

	Node* successor(Node* node)
	{
		auto curr = node->right;
		while (curr && curr->left)
			curr = curr->left;
		return curr;
	}
	
	// 노드 삭제 후, 부모 노드 포인터가 가리켜야 할 노드의 주소를 반환
	Node* erase_impl(Node* node, int value)
	{
		if (!node)
			return nullptr;

		if (value < node->data)
			node->left = erase_impl(node->left, value);
		else if (value > node->data)
			node->right = erase_impl(node->right, value);
		else {
			if (node->left && node->right) {
				// 자식 노드가 둘 다 있는 경우
				auto succ = successor(node);
				node->data = succ->data;
				node->right = erase_impl(node->right, succ->data);
			} else {
				// 자식 노드가 전혀 없거나, 한쪽 자식만 있는 경우
				auto tmp = node->left ? node->left : node->right;
				delete node;
				return tmp;
			}
		}

		return node;
	}

	void delete_tree(Node* node)
	{
		if (node) {
			delete_tree(node->left);
			delete_tree(node->right);
			delete node;
		}
	}
};

int main()
{
	BinarySearchTree bst;
	bst.insert(10);
	bst.insert(14);
	bst.insert(5);
	bst.insert(7);
	bst.insert(18);
	bst.insert(4);
	bst.insert(6);
	bst.insert(20);
	bst.insert(16);
	bst.inorder(); cout << endl;

	if (bst.find(7))
		cout << "7 is found" << endl;
	else
		cout << "7 is not found" << endl;

	if (bst.find(15))
		cout << "15 is found" << endl;
	else
		cout << "15 is not found" << endl;

	bst.insert(9);
	bst.insert(12);
	bst.inorder(); cout << endl;

	bst.erase(4);
	bst.erase(5);
	bst.erase(14);
	bst.inorder(); cout << endl;

	bst.insert(15);
	bst.erase(10);
	bst.inorder(); cout << endl;
}

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node
{
	char data;
	Node* left;
	Node* right;

	Node(char d) : data(d), left(nullptr), right(nullptr) {}
};

void preorder(Node* node)
{
	if (node) {
		std::cout << node->data << ", ";
		preorder(node->left);
		preorder(node->right);
	}
}

void inorder(Node* node)
{
	if (node) {
		inorder(node->left);
		std::cout << node->data << ", ";
		inorder(node->right);
	}
}

void postorder(Node* node)
{
	if (node) {
		postorder(node->left);
		postorder(node->right);
		std::cout << node->data << ", ";
	}
}

void levelorder(Node* node)
{
	std::queue<Node*> q;
	q.push(node);

	while (!q.empty()) {
		auto curr = q.front();
		q.pop();

		std::cout << curr->data << ", ";
		if (curr->left) q.push(curr->left);
		if (curr->right) q.push(curr->right);
	}
}

void delete_tree(Node* node)
{
	if (node) {
		delete_tree(node->left);
		delete_tree(node->right);
		delete node;
	}
}

int main()
{
	/*
	    A
	 B     C
	D E     F
	*/
	Node* root = new Node('A');
	root->left = new Node('B');
	root->right = new Node('C');
	root->left->left = new Node('D');
	root->left->right = new Node('E');
	root->right->right = new Node('F');

	preorder(root); cout << endl;
	inorder(root); cout << endl;
	postorder(root); cout << endl;
	levelorder(root); cout << endl;

	delete_tree(root);
}

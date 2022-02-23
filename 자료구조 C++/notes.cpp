#include <iostream>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

void printVector(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

struct Person
{
    string name;
    int age;
};

template<typename T1, typename T2>
void printTwo(T1 a, T2 b)
{
    cout << "T1: " << a << endl;
    cout << "T2: " << b << endl;
}

#define MAX_QUEUE 10
template<typename T>
class CircularQueue
{
    private:
        T* arr;
        int front_idx;
        int rear_idx;
        int count;
        int capacity;
    public:
        CircularQueue(int sz = MAX_QUEUE)
        {
            arr = new T[sz];
            capacity = sz;
            count = 0;
            front_idx = 0;
            //-1로 초기화 해야 첫 enqueue() 때 rear_idx ++ 해도 index 0에 접근함
            rear_idx = -1;
        }
        ~CircularQueue()
        {
            delete arr;
        }
        void enqueue(const T& e)
        {
            if (full())
            {
                cout << "Overflow Error!" << endl;
                return;
            }

            //계속 돌아갈 수 있도록 % capacity 넣기
            rear_idx = (rear_idx + 1) % capacity;
            arr[rear_idx] = e;
            //원소 개수 tracking
            count ++;
        }
        void dequeue()
        {
            if(empty())
            {
                cout << "Underflow Error!" << endl;
                return;
            }

            //계속 돌아갈 수 있도록 % capacity 넣기
            front_idx = (front_idx + 1) % capacity;
            //원소 개수 tracking
            count--;
        }
        const T& front() const { return arr[front_idx]; }
        bool empty() const { return count == 0; }
        int full() const { return count == capacity; }
        int size() const { return count; }
};

string reverse(const string& str)
{
    if (str.length() == 0)
        return "";
    else
        return reverse(str.substr(1)) + str[0];
}

struct Node
{
	int data;
	Node* left;
	Node* right;

	Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

struct NodeChar
{
	char data;
	NodeChar* left;
	NodeChar* right;

	NodeChar(char d) : data(d), left(nullptr), right(nullptr) {}
};

void preorder(NodeChar* node)
{
	if (node) {
		std::cout << node->data << ", ";
		preorder(node->left);
		preorder(node->right);
	}
}

void inorder(NodeChar* node)
{
	if (node) {
		inorder(node->left);
		std::cout << node->data << ", ";
		inorder(node->right);
	}
}

void postorder(NodeChar* node)
{
	if (node) {
		postorder(node->left);
		postorder(node->right);
		std::cout << node->data << ", ";
	}
}

void levelorder(NodeChar* node)
{
	std::queue<NodeChar*> q;
	q.push(node);

	while (!q.empty()) {
		auto curr = q.front();
		q.pop();

		std::cout << curr->data << ", ";
		if (curr->left) q.push(curr->left);
		if (curr->right) q.push(curr->right);
	}
}

void delete_tree(NodeChar* node)
{
	if (node) {
		delete_tree(node->left);
		delete_tree(node->right);
		delete node;
	}
}

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

class MaxHeap
{
private:
	vector<int> vec;

public:
	MaxHeap() : vec(1) {}

	void push(int value)
	{
		vec.push_back(value);
		heapify_up(vec.size() - 1);
	}
	void pop()
	{
		vec[1] = vec.back();
		vec.pop_back();
		heapify_down(1);
	}
	int top() const { return vec[1]; }
	void clear() { vec.clear(); vec.push_back(0); }
	int size() { return vec.size() - 1; }
	bool empty() { return vec.size() == 1; }
	void print()
	{
		for (auto n : vec)
			cout << n << ", ";
		cout << endl;
	}

private:
	int parent(int i) { return i / 2; }
	int left(int i) { return 2 * i; }
	int right(int i) { return 2 * i + 1; }
	void heapify_up(int i)
	{
		if (i > 1 && vec[i] > vec[parent(i)]) {
			swap(vec[i], vec[parent(i)]);
			heapify_up(parent(i));
		}
	}
	void heapify_down(int i)
	{
		int largest = i;

		if (left(i) < vec.size() && vec[left(i)] > vec[largest]) {
			largest = left(i);
		}

		if (right(i) < vec.size() && vec[right(i)] > vec[largest]) {
			largest = right(i);
		}

		if (largest != i) {
			swap(vec[i], vec[largest]);
			heapify_down(largest);
		}
	}
};

struct Person_pq
{
    string name;
    int age;
    bool operator < (const Person_pq& Person_pq_) const {
        return age < Person_pq_.age;
    }
};

class hash_set
{
private:
	int sz;
	std::vector<int> data;

public:
	hash_set(int n) : sz(n), data(sz, -1) {}
	int hash(int key)
	{
		return key % sz;
	}
	void insert(int value)
	{
		data[hash(value)] = value;
	}
	bool find(int value)
	{
		return (data[hash(value)] == value);
	}
	void erase(int value)
	{
		data[hash(value)] = -1;
	}
	void print()
	{
		for (auto n : data)
			std::cout << n << ", ";
		std::cout << std::endl;
	}
};

class hash_set_chaining
{
private:
	int sz;
	std::vector<std::list<int>> data;

public:
	hash_set_chaining(int n) : sz(n), data(sz) {}
	int hash(int key)
	{
		return key % sz;
	}
	void insert(int value)
	{
		data[hash(value)].push_back(value);
	}
	bool find(int value)
	{
		auto& entries = data[hash(value)];
		return std::find(entries.begin(), entries.end(), value) != entries.end();
	}
	void erase(int value)
	{
		auto& entries = data[hash(value)];
		auto it = std::find(entries.begin(), entries.end(), value);

		if (it != entries.end()) {
			entries.erase(it);
		}
	}
	void print()
	{
		for (int i = 0; i < sz; i++) {
			std::cout << i << ": ";
			for (auto n : data[i]) {
				std::cout << n << ", ";
			}
			cout << " ";
		}
	}
};

int main()
{
    //////////////////Vector//////////////////
    cout << "//////////////////Vector//////////////////" << endl;
    vector<int> v(5);
    v.push_back(10);
    v.push_back(2);
    v.push_back(4);
    sort(v.begin(), v.end());
    printVector(v);
    //4th index 자리에 insert
    v.insert(v.begin() + 4, 100);
    printVector(v);
    //4th and 5th index 자리 element erase
    v.erase(v.begin() + 3, v.begin() + 5);
    printVector(v);
    //front(), back(), pop_back(), empty() 등이 더 있음

    //2-dimensional vector
    const int SIZE = 4;
    vector<vector<int>> map_(SIZE, vector<int>(SIZE));

    for (int r = 0; r < SIZE; r++)
    {
        for (int c = 0; c < SIZE; c++)
        {
            cout << map_[r][c] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    //////////////////Lambda//////////////////
    cout << "//////////////////Lambda//////////////////" << endl;
    auto square = [](int a) {return a * a;};
    cout << "square of 2 is: " << square(2) << endl;

    vector<Person> students;
    students.push_back({"Kim", 24});
    students.push_back({"John", 26});
    students.push_back({"Alex", 25});
    //오름차순
    sort(students.begin(), students.end(), 
        [](const Person& p1, const Person& p2)
        {
            return p1.age < p2.age;
        });
    for (int i = 0; i < students.size(); i++)
    {
        cout << "Student name: " << students[i].name << " // ";
        cout << "Student age: " << students[i].age << endl;
    }
    cout << endl;

    //////////////////Template//////////////////
    cout << "//////////////////Template//////////////////" << endl;
    int a = 3;
    float b = 2.145;
    printTwo(a, b);
    //클래스 템플릿 만드는 방법은 CircularQueue 참고
    cout << endl;

    //////////////////Single LinkedList//////////////////
    cout << "//////////////////Single LinkedList//////////////////" << endl;
    forward_list<int> single_list;
    int SIZE_ = 10;
    for (int i = 0; i < SIZE_; i++) single_list.push_front(i);
    for (int j : single_list) cout << j << " ";
    cout << endl;

    cout << "Number of nodes: " << distance(single_list.begin(), single_list.end()) << endl;    
    single_list.remove(4);
    for (int j : single_list) cout << j << " ";
    cout << endl;
    single_list.remove_if([](int a){return a > 5;});
    for (int j : single_list) cout << j << " ";
    cout << endl;
    //next라는 함수를 쓰면 반복자의 다음 노드 반복자에 접근 가능
    single_list.insert_after(next(single_list.begin()), 20);
    //반복자 앞에 *를 붙이면 해당 값으로도 접근 가능
    cout << *next(single_list.begin()) << endl;
    for (int j : single_list) cout << j << " ";
    cout << endl;
    single_list.erase_after(single_list.begin());
    for (int j : single_list) cout << j << " ";
    cout << endl;
    //pop_front() 등이 더 있음
    cout << endl;

    //////////////////Doubly LinkedList//////////////////
    cout << "//////////////////Doubly LinkedList//////////////////" << endl;
    list<int> double_list;
    for (int i = 0; i < SIZE_; i++) double_list.push_front(i);
    double_list.push_back(20);
    double_list.push_back(40);
    for (int j : double_list) cout << j << " ";
    cout << endl;
    cout << "Last element in Doubly LinkedList: " << double_list.back() << endl;
    //front(), begin(), end(), insert(), erase(), pop_front(), pop_back(), size() 등이 더 있음
    cout << endl;

    //////////////////Stack//////////////////
    cout << "//////////////////Stack//////////////////" << endl;
    stack<int> s;
    for (int i = 0; i < SIZE_; i++) s.push(i);
    cout << "Element on the top of the stack: " << s.top() << endl;
    cout << "Size of the stack: " << s.size() << endl;
    cout << "Elements in the stack: "
    ;
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    cout << endl;

    //////////////////Queue//////////////////
    cout << "//////////////////Queue//////////////////" << endl;
    queue<int> q;
    for (int i = 0; i < SIZE_; i++) q.push(i);
    //queue는 top()이 아닌 front()
    //stack은 수직으로 있고 queue는 누워있는 거라고 생각하자
    cout << "Element on the front of the queue: " << q.front() << endl;
    cout << "Size of the queue: " << q.size() << endl;
    cout << "Elements in the queue: ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    cout << endl;

    //////////////////Circular Queue//////////////////
    cout << "//////////////////Circular Queue//////////////////" << endl;
    //default size of circular queue set to 10
    CircularQueue<int> cq(4);
    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cq.enqueue(4);
    cq.dequeue();
    cout << cq.front() << endl;
    while (!cq.empty())
    {
        cout << cq.front() << " ";
        cq.dequeue();
    }
    cout << endl;
    //full(), size() 등도 있음
    cout << endl;

    /////////////////Deque//////////////////
    cout << "//////////////////Deque//////////////////" << endl;
    deque<int> dq;
    for (int i = 0; i < SIZE_; i++) dq.push_front(i);
    dq.push_back(20);
    cout << "Element on the front of the deque: " << dq.front() << endl;
    cout << "Element on the back of the deque: " << dq.back() << endl;
    dq.pop_front();
    cout << "Element on the front of the deque: " << dq.front() << endl;
    dq.pop_back();
    cout << "Element on the back of the deque: " << dq.back() << endl;
    cout << "Size of the deque: " << dq.size() << endl;
    cout << "Elements in the deque: ";
    while (!dq.empty())
    {
        cout << dq.front() << " ";
        dq.pop_front();
    }
    cout << endl;
    cout << endl;

    /////////////////Recursive//////////////////
    cout << "//////////////////Recursive//////////////////" << endl;
    cout << "Reversing the input string" << endl;
    cout << reverse("Hello") << endl;
    cout << endl;

    /////////////////Sorting & Search Algorithm//////////////////
    cout << "//////////////////Sorting & Search Algorithm//////////////////" << endl;
    //버블 정렬, 선택 정력, 삽입 정렬 (비효율)
    //버블: 정렬되지 않은 부분에서 인접한 두 원소의 크기를 비교하여 교환하는 작업 반복
    //선택: 정렬되지 않은 원소들 중에서 최소값 원소를 찾아 맨 왼쪽 원소과 교환
    //삽입: 정렬되지 않은 부분의 첫 번째 원소를 정렬된 부분의 알맞은 위치에 삽입하는 과정 반복 
    //병합 정렬, 퀵 정렬 (효율)
    //병합: 1.입력 배열을 두 개의 부분 배열로 분할  2.부분 배열은 재귀적으로 정렬 3.부분 배열 병합(이때 병합된 배열의 원소가 정렬순서에 부합되도록 순서 조정)
    //퀵: 1.특정 원소를 피벗으로 선택하고, 주어진 배열을 피벗보다 작은 부분과 큰 부분으로 분할 2.분할된 부분 배열에 대해 재귀적으로 퀵 정렬 분할 작업 반복
    //STL sort 사용법
    vector<int> v_;
    v = {5, 7, 10, 20, 15, 3, 6};
    for (int i : v) cout << i << " ";
    cout << endl;
    //내림차순
    sort(v.begin(), v.end(), greater<>());
    for (int j : v) cout << j << " ";
    cout << endl;
    v_ = {-6, -3, 0, 6, -2, 10, 12, -3};
    sort(v_.begin(), v_.end(), [](int a, int b) { return abs(a) < abs(b); });
    for (int k : v_) cout << k << " ";
    cout << endl;

    //탐색은 선형탐색 & 이진탐색
    vector<int> v__ = {10, 5, 20, 16, 40, 13, 76, 0, 31, 2};
    int target = 40;
    //이진탐색은 std::binary_search 존재 (bool type)
    //비교 함수 comp를 마지막 매개변수로 지정할 수도 있음
    cout << binary_search(v__.begin(), v__.end(), target) << endl;
    cout << endl;

    /////////////////Binary Tree & BST//////////////////
    cout << "//////////////////Binary Tree & BST//////////////////" << endl;
    //트리 자체에 대한 용어 
    //차수(degree): 부(하위) 트리의 간선 개수
    //레벨(level): 루트를 0으로 놓고 내려가면서 ++
    //높이(height): Leaf를 기준으로 0으로 놓고 올라가면서 ++
    //서브트리(subtree): 하나를 루트를 가질 수 있도록 묶어서 표현된 트리의 일부
    
    //이진 트리
    //이진 트리는 노드가 최대 두 개의 자식을 갖는 트리 
    //(연결 리스트로 구현하는 게 편함)
    //각각의 자식 노드는 Left Child와 Right Child
    //Full/정 이진 트리: (자식노드가 0개 또는 2개), Perfect/포화: (자식노드 모두 2개),  
    //Complete/완전: (왼쪽부터 완전히 채워진), Balanced/균형: (모든 노드의 서브트리 간의 높이 차이가 1이하),
    //Skewed/편향: (리프 노드를 제외한 모든 노드가 하나의 자식 노드만 갖는)
    //순회 알고리즘: DFS & BFS (순회라는 건 정해진 순서에 의해 트리의 모든 노드를 한번씩 방문하는 작업)
    //Depth First Search:
    //전위 순회 (preorder traversal)
    //중위 순회 (inordeer traversal)
    //후위 순회 (postorder traversal)
    //Breadth First Search:
    //레벨 순서 순회 (level order traversal)
    //탐색은 DFS or BFS 방식에 따라 하고, 삽입은 아무대나 하고, 삭제도 delete만 하면 됨 
    	/*
	    A
	 B     C
	D E     F
	*/
    NodeChar* root = new NodeChar('A');
	root->left = new NodeChar('B');
	root->right = new NodeChar('C');
	root->left->left = new NodeChar('D');
	root->left->right = new NodeChar('E');
	root->right->right = new NodeChar('F');
    cout << "Binary Tree: " << endl;
    cout << "Preorder: ";
    preorder(root); cout << endl;
    cout << "Inorder: ";
	inorder(root); cout << endl;
    cout << "Postorder: ";
	postorder(root); cout << endl;
    cout << "Levelorder: ";
	levelorder(root); cout << endl;
	delete_tree(root);
    cout << endl;

    //이진 탐색 트리(Binary Search Tree) -> 효율적인 자료 탐색을 위한 구성
    //(연결 리스트로 구현하는 게 편함)
    //모든 노드에 대해 왼쪽 자식 노드의 키 값은 해당 노드보다 작고 오른쪽 자식 노드의 키 값은 해당 노드보다 크도록 구성된 이진 트리
    //가정 -> 중복값 노드 없음
    //탐색은 원하는 값에 따라 노드의 오른쪽으로 갈 건지 왼쪽으로 갈 건지 정해서 탐색하면 됨 (매우 효율적) 
    //삽입도 원하는 값에 따라 노드의 오른쪽으로 진행할지 왼쪽으로 할지 정하면서 적절한 위치에 삽입하면 됨
    //삭제는 이진 탐색 트리의 형태를 유지하기 위해서 다음 3가지의 경우의 수로 나누어서 삭제 진행
    //1.자식 노드가 없는 경우 2.자식 노드가 하나만 있는 경우 3.자식 노드가 두 개 있는 경우
    //문제점: 한쪽으로 치우진 형태로 구성될 수가 있다 (취지 벗어나는 것)
    //그래서 AVL 트리, 레드-블랙 트리(red-black tree), B 트리, splay 트리 등 존재
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
    cout << "Binary Search Tree: " << endl;
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
    cout << endl;

    //std::set
    //레드 블랙 트리 이용하여 구현됨
    //#include <set> 필요
    //set는 중복되는 데이터는 insert 불가 (중복되도 되는 상태로 하려면 std::multiset 사용해야 함)
    //std::set은 데이터를 자동으로 정렬해 주는데, 정렬되지 않은 상태로 저장하려면 std::unordered_set 사용해야 함
    //std::set는 comp 비교 함수 지원함
    cout << "Set" << endl;
    set<int> set1 = {1, 5, 10, -1, 6, 20};
    set1.insert(42);
    for (int i = 0; i < 10; i++) set1.insert(1);
    cout << "Elements in set: ";
    for (int j : set1) cout << j << " ";
    cout << endl;
    set<int, greater<>> set2 = {1, 5, 10, -1, 6, 20, 42};
    cout << "Elements in set when greater<> used: ";
    for (int k : set2) cout << k << " ";
    cout << endl;
    //set.find(원소)의 경우에는 해당 원소를 찾으면 그 원소의 위치에 대한 반복자를 반환하고 찾지 못 하면 set.end()에 해당하는 반복자 반환한다
    if (set1.find(5) != set1.end()) cout << "5 is in the set" << endl;
    cout << endl;

    cout << "Map" << endl;
    using psi = pair<string, int>;
    set<psi> managers {{"Amelia", 29}, {"Noah", 25}, {"Olivia", 31},
		{"Sophia", 40}};
	//pair 이렇게도 가능
    managers.insert(make_pair("George", 35));
    psi person1 = {"Noah", 25};
	if (managers.find(person1) != managers.end())
		cout << person1.first << " is a manager!" << endl;
	else
		cout << person1.first << " is not a manager!" << endl;
    managers.erase({"Sophia", 40});
	managers.erase({"Noah", 30});
    cout << "Managers in the set: ";
    for (const auto& m : managers)
		cout << m.first << "(" << m.second << ") ";
    cout << endl;
    //참고로 psi라는 데이터 타입은 첫번째 입력 데이터 타입에 대해 정렬을 자동으로 해주고
    //만약 동일한 게 있다면 두번째 데이터 타입을 기준으로 정렬함
    //begin(), size(), empty() 등도 있음

    //std::map
    //키만 저장하는 std::set와는 다르게 std::map은 키와 벨류 둘다 저장
    //레드 블랙 트리 이용하여 구현됨
    //#include <map> 필요
    //정렬은 키 값을 기준으로 정렬됨
    //std::multimap, std::unordered_map도 존재
    //comp 비교 함수 지원함
    //관련 멤버함수 std::set과 동일 BUT operator[] 추가적으로 존재
    //operator[]는 특정 키에 해당하는 원소의 값을 참조로 반환하는데
    //해당 키의 원소가 없으면 새로운 원소를 기본값으로 생성하여 참조를 반환함
    map<string, int> fruits;
	fruits.insert({"apple", 1000});
	fruits.insert({"banana", 1500});
	//이렇게 하면 0으로 초기화 해서 삽입
    fruits["orange"];
	cout << fruits["apple"] << endl;
    fruits["apple"] = 2000;
	fruits.erase("grape");
    cout << "Information in the map: " << endl;
	for (auto [name, price] : fruits)
		cout << name << " is " << price << " won." << endl;
    cout << endl;

    //////////////////Heap//////////////////
    cout << "//////////////////Heap//////////////////" << endl;
    //Heap은 완전 이진 트리의 한 형태로서 힙 속성을 만족하는 구조
    //(배열로 구현하는 게 편함)
    //1.최대 힙: 부모 노드의 키 값은 항상 자식 노드의 키 값보다 크거나 같다
    //2.최소 힙: 부모 노드의 키 값은 항상 자식 노드의 키 값보다 작거나 같다
    //힙은 1st index부터 원소 넣는다 (이래야 왼쪽 자식, 오른쪽 자식 그리고 부모 노드를 계산하기 쉬워짐)
    //노드 번호 m을 기준으로
    //왼쪽 자식의 번호: 2 * m
    //오른쪽 자식의 번호: 2 * m + 1
    //부모 노드의 번호: m // 2
    //삽입 -> 트리의 마지막 자리에 새로운 원소를 임시로 저장하고 부모 노드와 키 값을 비교하여 위로, 위로 이동
    //삭제는 최대 값을 삭제하는 것이기에 사실상 루트 노드를 삭제하는 것 
    //-> 트리 마지막 자리 노드를 임시로 루트 노드의 자리에 배치하고 자식 노드들과의 값 비교를 하여 아래로, 아래로 이동 
    //(내리는 건 더 큰 키 값을 가지는 자식 쪽으로)
    MaxHeap heap;
	heap.push(10);
	heap.push(5);
	heap.push(15);
	heap.push(7);
	heap.push(3);
	heap.push(9);
	heap.push(14);
	heap.push(8);
	heap.push(2);
	heap.push(4);
	heap.print();
	while (!heap.empty()) {
		cout << heap.top() << ", ";
		heap.pop();
	}
	cout << endl;
    //<algorithm>에 make_heap이라는 게 정의되어 있긴 함 (참고)
    cout << endl;

    //////////////////Priority Queue//////////////////
    cout << "//////////////////Priority Queue//////////////////" << endl;
    //#include <queue>를 넣어서 사용
    priority_queue<int> pq;
    pq.push(1);
    pq.push(54);
    pq.push(20);
    pq.push(-1);
    pq.push(-64);
    pq.push(100);
    cout << "Elements in the priority queue: ";
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    //Struct을 사용하면 비교할 수 있는 comp 비교 함수를 지정해줘야함
    priority_queue<Person_pq> pq_;
    pq_.push({"Jack", 23});
    pq_.push({"Alex", 24});
    pq_.push({"John", 20});
    pq_.push({"James", 21});
    pq_.push({"Michael", 22});
    //comp 비교 함수에 따라 가장 값이 큰 애 출력
    cout << pq_.top().age << endl;
    cout << endl;

    //////////////////Hashing//////////////////
    cout << "//////////////////Hashing//////////////////" << endl;
    //각각의 데이터를 고유한 숫자 값으로 표현하고, 이를 이용하여 특정 데이터의 존재 여부를 확인하거나 또는 원본 데이터를 추출하는 작업
    //hash(x) = x % n 
    //hash: 해시함수 -> 보통 함수의 출력은 고정된 범위의 정수로 매핑됨 (실수 해시 함수, 문자열 해시 함수 등이 있음) 
    //x: 키 -> 입력
    //x % n: 해시 값 -> 해시 함수의 출력으로, 보통 해시 테이블의 인덱스로 사용됨 (해시 코드 또는 해시라고도 부름)
    //추가적인 용어
    //해시 테이블 -> 입력 데이터가 저장되는 배열 (key로만 구성된 경우 hash set, key와 value로 구성된 경우 hash map이라고도 함) 
    //버킷 -> 해시 테이블에서 하나의 데이터가 저장된 공간 (slot이라고도 함)
    //BST를 사용하면 O(log n) 복잡도 BUT 해싱 잘 사용하면 O(1) 가능
    hash_set num_set(7);
    num_set.insert(10); // 3
    num_set.insert(15); // 1
    num_set.insert(20); // 6
    num_set.insert(100); // 2
    cout << "Vanilla Hash" << endl;
    num_set.print();
    int value = 10;
    if (num_set.find(value))
        cout << value << " is found!" << endl;
    else
        cout << value << " is NOT found!" << endl;
    //2를 넣으면 기존에 들어가 있던 10이 대체되는 Collision(충돌) 현상발생
    num_set.insert(2);
    num_set.print();
    value = 100;
    if (num_set.find(value))
        cout << value << " is found!" << endl;
    else
        cout << value << " is NOT found!" << endl;
    cout << endl;

    //충돌 -> 해시 함수가 서로 다른 키에 대해 같은 해시 값을 반환함으로써, 다수의 키가 같은 해시 값을 갖게 되는 현상 (chaining, open addressing 등으로 해결 가능) 
    //1.Chaining
    //해시 테이블의 특정 위치에서 하나의 키를 저장하는 것이 아니라 연결 리스트를 저장하는 기법
    //새로 삽입된 키에 의해 충돌이 발생하면 리스트에 새로운 키를 추가
    //부하율(Load Factor) -> 해시 테이블에서 각각의 리스트에 저장되는 키의 평균 개수 or 적재율
    //부하율 = n / m, where n: 해시 테이블에 저장할 전체 키의 개수 m: 해시 테이블 크기 (연결 리스트 개수)
    hash_set_chaining num_set_(7);
    num_set_.insert(10); // 3
    num_set_.insert(15); // 1
    num_set_.insert(20); // 6
    num_set_.insert(100); // 2
    num_set_.insert(2);
    cout << "Hash with Chaining" << endl;
    num_set_.print();
    cout << endl;
    value = 100;
    if (num_set_.find(value))
        cout << value << " is found with chaining!" << endl;
    else
        cout << value << " is NOT found!" << endl;
    cout << endl;

    //2.Open Addressing
    //해시 충돌이 발생할 경우, 해시 테이블에서 다른 비어 있는 버킷을 찾아 데이터를 저장하는 방식
    //해시 테이블의 크기가 데이터 개수보다 커야 함
    //새로운 위치 탐사(Probing) 방식
    //1.선형 탐사(Linear Probing) 2.제곱 탑사(Quadratic Probing) 3.이중 해싱(Double Hashing)
    //선형 탐사(Linear Probing)
    //h(key)가 사용중이면 h(key) + 1, h(key) + 2 이런식으로 넘어가면서 빈자리 찾기
    //Clustering이 있는 경우 비효율적
    //제곱 탑사(Quadratic Probing)
    //h(key)가 사용중이면 h(key) + 1^2, h(key) + 2^2, h(key) + 3^2 이런 식으로 쭉쭉 넘어가면서 빈자리 찾기

    //std::unordered_set
    //#include <unordered_set> 필요
    //unordered_set는 중복되는 데이터는 insert 불가 (중복되도 되는 상태로 하려면 std::unordered_multiset 사용해야 함)
	//car -> radio -> orange -> ear -> radio
    cout << "Unordered Set" << endl;
	unordered_set<string> words;
	words.insert("car");
	words.insert("radio");
	words.insert("orange");
	words.insert("ear");
	string word = "radio";
	if (words.find(word) != words.end())
		cout << word << " is used!" << endl;
	else
		cout << word << " is NOT used!" << endl;
	vector<int> numbers {1, 5, 3, 1, 5, 7, 4, 5, 6, 3, 2, 7, 3, 6, 2};
    //numbers라는 vector에 있는 원소들을 numbers.begin(), numbers.end()로 unordered_set<int> num_set__에 추가하면 반복되는 애들은 무시됨
	unordered_set<int> num_set__(numbers.begin(), numbers.end());
	cout << num_set__.size() << endl;
    cout << endl;

    //std::unordered_map
    //키만 저장하는 std::set와는 다르게 std::map은 키와 벨류 둘다 저장
    //#include <unordered_map> 필요
    //unordered_map는 중복되는 데이터는 insert 불가 (중복되도 되는 상태로 하려면 std::unordered_multimap 사용해야 함)
    cout << "Unordered Map" << endl;
    unordered_map<string, int> fruits_;
	fruits_.insert({"apple", 1000});
	fruits_.insert({"banana", 1500});
	fruits_["orange"] = 3000;
	fruits_["grape"] = 4000;
	fruits_["lemon"] = 5000;
	fruits_["apple"] = 2000;
	fruits_.erase("grape");
	for (auto [name, price] : fruits_)
		cout << name << " is " << price << " won." << endl;
    cout << endl;

    //////////////////Graph//////////////////
    cout << "//////////////////Graph//////////////////" << endl;

    cout << endl;

    //////////////////Dynamic Programming//////////////////
    cout << "//////////////////Dynamic Programming//////////////////" << endl;

    cout << endl;

    //////////////////Extra//////////////////
    cout << "//////////////////Extra//////////////////" << endl;
    //개념
    //Sequence Container (순차 컨테이너)
    //vector, array, deque, list, forward_list
    //Associative Container (연관 컨테이너)
    //set, multiset, map, multimap
    //Unordered Associative Container (순서없는 연관 컨테이너)
    //unordered_set, unordered_multiset, unordered_map, unordered_multimap
    //Container Adaptors (컨테이너 어댑터)
    //stack, queue, priority_queue

    //For inputs with spaces;
    //char input[100];
    //cin.getline(input, size(input));

    //Dividing string
    //str.substr(1) 이렇게 하면 str에 있는 element의 두번째 element ~ end 반환
    //#include <string> 필요

    //Swap elements
    //swap(a[1], a[2]) 이렇게 하면 둘을 swap

    //내림차순 정렬
    //sort(v.begin(), v.end(), greater<>());
    //#include <algorithm> 필요
    //sort(v_.begin(), v_.end(), [](int a, int b) { return abs(a) < abs(b); });
    //이런 식으로 원하는 비교 방법 지정도 가능
    //<로 하면 오름차순 >로 하면 내림차순

    return 0;
}



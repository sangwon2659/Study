#include <iostream>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <list>
#include <stack>
#include <queue>
#include <string>

using namespace std;

struct Person
{
    string name;
    int age;
};

void printVector(vector<int>);

template<typename T1, typename T2>
void printTwo(T1, T2);

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
        ~CircularQueue();
        void enqueue(const T&);
        void dequeue();
        const T& front() const { return arr[front_idx]; }
        bool empty() const { return count == 0; }
        int full() const { return count == capacity; }
        int size() const { return count; }
};

string reverse(const string&);

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
    vector<vector<int>> map(SIZE, vector<int>(SIZE));

    for (int r = 0; r < SIZE; r++)
    {
        for (int c = 0; c < SIZE; c++)
        {
            cout << map[r][c] << " ";
        }
        cout << endl;
    }
    
    //////////////////Lambda//////////////////
    cout << "//////////////////Lambda//////////////////" << endl;
    auto square = [](int a) {return a * a;};
    cout << "square of 2 is: " << square(2) << endl;

    vector<Person> students;
    students.push_back({"Kim", 24});
    students.push_back({"John", 26});
    students.push_back({"Alex", 25});
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

    //////////////////Template//////////////////
    cout << "//////////////////Template//////////////////" << endl;
    int a = 3;
    float b = 2.145;
    printTwo(a, b);
    //클래스 템플릿 만드는 방법은 CircularQueue 참고

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

    //////////////////CircularQueue//////////////////
    cout << "//////////////////CircularQueue//////////////////" << endl;
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

    /////////////////Recursive//////////////////
    cout << "//////////////////Recursive//////////////////" << endl;
    cout << "Reversing the input string" << endl;
    cout << reverse("Hello") << endl;

    /////////////////SortingAlgorithm//////////////////
    cout << "//////////////////SortingAlgorithm//////////////////" << endl;
    //버블 정렬, 선택 정력, 삽입 정렬 (비효율)
    //병합 정렬, 퀵 정렬 (효율)
    //등이 있다
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
    vector<int> data = {10, 5, 20, 16, 40, 13, 76, 0, 31, 2};
    int target = 40;
    //이진탐색은 std::binary_search 존재
    //비교 함수 comp를 마지막 매개변수로 지정할 수도 있음
    cout << binary_search(data.begin(), data.end(), target) << endl;


    /////////////////BinaryTree//////////////////
    cout << "//////////////////Binary Tree//////////////////" << endl;
    //이진 트리는 노드가 최대 두 개의 자식을 갖는 트리
    //각각의 자식 노드는 Left Child와 Right Child
    //full(자식노드가 0개 또는 2개), perfect(자식노드 모두 2개),  
    //complete(왼쪽부터 완전히 채워진), balanced(모든 노드의 서브트리 간의 높이 차이가 1이하),
    //skewed(리프 노드를 제외한 모든 노드가 하나의 자식 노드만 갖는)

    //////////////////Extra//////////////////
    cout << "//////////////////Extra//////////////////" << endl;
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


void printVector(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

template<typename T1, typename T2>
void printTwo(T1 a, T2 b)
{
    cout << "T1: " << a << endl;
    cout << "T2: " << b << endl;
}

template<typename T>
CircularQueue<T>::~CircularQueue()
{
    delete arr;
}

template<typename T>
void CircularQueue<T>::enqueue(const T& e)
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

template<typename T>
void CircularQueue<T>::dequeue()
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

string reverse(const string& str)
{
    if (str.length() == 0)
        return " ";
    else
        return reverse(str.substr(1)) + str[0];
}

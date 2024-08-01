#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
public:
    Node *head;
    Node *tail;

public:
    LinkedList(/* args */);
    ~LinkedList();
    void push_front(int data);
    void push_back(int data);
    void insert(int data, int position);
    void print();
};

LinkedList::LinkedList(/* args */)
{
    head = nullptr;
    tail = nullptr;
}

LinkedList::~LinkedList()
{
    while (head != nullptr)
    {
        Node *tmp = head;
        head = head->next;
        delete tmp;
    }
    cout << "Destroyed!" << endl;
}

void LinkedList::push_front(int data)
{
    Node *newNode = new Node;
    if (newNode == nullptr)
        throw bad_alloc();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    if (tail == nullptr)
        tail = newNode;
}

void LinkedList::push_back(int data)
{

    Node *newNode = new Node;
    if (newNode == nullptr)
        throw bad_alloc();
    newNode->data = data;
    newNode->next = nullptr;
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

void LinkedList::insert(int data, int position)
{
    // Kiểm tra vị trí chèn hợp lệ
    if (position < 0)
    {
        throw std::out_of_range("Position cannot be negative");
    }

    // Tạo một nút mới
    Node *newNode = new Node;
    if (newNode == nullptr)
    {
        throw std::bad_alloc();
    }
    newNode->data = data;
    newNode->next = nullptr;

    // Xử lý trường hợp chèn vào đầu danh sách
    if (position == 0)
    {
        newNode->next = head;
        head = newNode;
        // Nếu danh sách ban đầu trống, cập nhật tail
        if (tail == nullptr)
        {
            tail = newNode;
        }
        return;
    }

    // Di chuyển đến vị trí trước vị trí chèn
    Node *tmp = head;
    for (int i = 0; i < position - 1; i++)
    {
        if (tmp == nullptr || tmp->next == nullptr)
        {
            throw std::out_of_range("Position out of range");
        }
        tmp = tmp->next;
    }

    // Chèn nút mới vào vị trí
    newNode->next = tmp->next;
    tmp->next = newNode;

    // Nếu chèn vào cuối danh sách, cập nhật tail
    if (newNode->next == nullptr)
    {
        tail = newNode;
    }
}

void LinkedList::print()
{
    Node *tmp = head;
    while (tmp != nullptr)
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

bool cmp(Node a, Node b) {
    return a.data <= b.data ? true : false;
}

int main()
{
    LinkedList *list = new LinkedList;
    list->push_front(0);
    list->push_front(1);
    list->push_front(2);
    list->push_front(3);
    list->push_back(4);
    list->push_back(5);
    list->insert(7, 2);
    sort(list->head, list->tail, cmp);
    list->print();
    delete list;
    return 0;
}

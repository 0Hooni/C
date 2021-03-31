#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int e)
    {
        data = e;
        next = NULL;
    }
};

class SinglyLinkedList
{
public:
    Node *head;
    Node *tail;
    int size;
    SinglyLinkedList()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    bool empty()
    {
        if (size == 0)
            return true;
        else
            return false;
    }
    void addTail(int e)
    {
        Node *newNode = new Node(e);
        if (empty())
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    int removeTail()
    {
        Node *tmp;
        if (empty())
            return -1;
        else if (size == 1)
        {
            tmp = tail;
            int tmpData = tail->data;
            head = NULL;
            tail == NULL;
            delete tmp;
            size--;
            return tmpData;
        }
        else
        {
            Node *tmp = head;
            for (int i = 2; i < size; i++)
                tmp = tmp->next;
            int tailData = tail->data;
            delete tmp->next;
            tail = tmp;
            size--;
            return tailData;
        }
    }
};

class Stack
{
public:
    SinglyLinkedList *stack;
    Stack()
    {
        stack = new SinglyLinkedList();
    }
    bool empty()
    {
        if (stack->size == 0)
            return true;
        else
            return false;
    }
    int top()
    {
        if (empty())
            return -1;
        else
        {
            return stack->tail->data;
        }
    }
    void push(int e) { stack->addTail(e); }
    int pop() { return stack->removeTail(); }
    int size() { return stack->size; }
};

int main()
{
    Stack *s = new Stack();

    int n = 0;
    cin >> n;

    while (n--)
    {
        string cmd = "";
        cin >> cmd;

        if (cmd == "empty")
        {
            cout << s->empty() << endl;
        }
        else if (cmd == "top")
        {
            cout << s->top() << endl;
        }
        else if (cmd == "push")
        {
            int data;
            cin >> data;
            s->push(data);
        }
        else if (cmd == "pop")
        {
            cout << s->pop() << endl;
        }
        else if (cmd == "size")
        {
            cout << s->size() << endl;
        }
    }

    return 0;
}
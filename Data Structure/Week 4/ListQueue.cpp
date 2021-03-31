#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int e)
    {
        data = e;
        next = NULL;
    }

    Node()
    {
        data = 0;
        next = NULL;
    }
};

class SinglyLinkedList
{
public:
    int size;
    Node *head;
    Node *tail;

    SinglyLinkedList()
    {
        size = 0;
        head = NULL;
        tail = NULL;
    }

    void addTail(int data)
    {
        Node *newNode = new Node(data);
        if (size == 0)
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

    void removeFront()
    {
        Node *tmp = head;
        head = head->next;
        delete tmp;
        size--;
    }
};

class Queue
{
public:
    SinglyLinkedList *queue;
    int qSize = 0;

    Queue()
    {
        queue = new SinglyLinkedList();
    }

    bool isEmpty()
    {
        if (qSize == 0)
            return true;
        else
            return false;
    }

    void enqueue(int data)
    {
        queue->addTail(data);
        qSize++;
    }

    void dequeue()
    {
        queue->removeFront();
        qSize--;
    }

    int size() { return qSize; }

    int front() { return queue->head->data; }

    int rear() { return queue->tail->data; }
};

int main()
{
    Queue *q = new Queue();
    int s;
    cin >> s; //lower than 100

    int n;
    cin >> n; //number of TestCase

    while (n--)
    {
        string cmd = "";
        cin >> cmd; //input command

        if (cmd == "enqueue")
        {
            int data;
            cin >> data; //input data
            if (q->size() >= s)
                cout << "Full" << endl;
            else
                q->enqueue(data);
        }
        else if (cmd == "dequeue")
        {
            if (q->isEmpty())
                cout << "Empty" << endl;
            else
            {
                cout << q->front() << endl;
                q->dequeue();
            }
        }
        else if (cmd == "size")
        {
            cout << q->size() << endl;
        }
        else if (cmd == "isEmpty")
        {
            cout << q->isEmpty() << endl;
        }
        else if (cmd == "front")
        {
            cout << q->front() << endl;
        }
        else if (cmd == "rear")
        {
            cout << q->rear() << endl;
        }
    }

    return 0;
}

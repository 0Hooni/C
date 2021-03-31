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
        data = -1;
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
    int size;

    SinglyLinkedList()
    {
        head = NULL;
        size = 0;
    }

    bool empty()
    {
        if (size == 0)
            return true;
        else
            return false;
    }

    void addFront(int e)
    {
        Node *newNode = new Node(e);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void removeFront()
    {
        Node *tmp = head;
        cout << tmp << endl;
        head = head->next;
        delete tmp;
        size--;
    }

    int front()
    {
        if (empty())
            return -1;
        else
            return head->data;
    }
};

int main()
{
    SinglyLinkedList *sll = new SinglyLinkedList();
    int n = 0;
    cin >> n;

    while (n--)
    {
        string cmd = "";
        cin >> cmd;

        if (cmd == "addFront")
        {
            int element = 0;
            cin >> element;
            sll->addFront(element);
        }
        else if (cmd == "removeFront")
        {
            if (sll->empty())
                cout << "-1" << endl;
            else
                sll->removeFront();
        }
        else if (cmd == "front")
            cout << sll->front() << endl;
        else if (cmd == "empty")
            cout << sll->empty() << endl;
    }

    return 0;
}
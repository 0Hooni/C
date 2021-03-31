#include <iostream>
#include <string>

using namespace std;

#define MAX_SIZE 10000

class Array
{
public:
    int array[MAX_SIZE];
    int top;
    Array()
    {
        for (int i = 0; i < MAX_SIZE; i++)
            array[i] = 0;
        top = -1;
    }
};

class Queue
{
public:
    Array *queue;
    Queue()
    {
        queue = new Array();
    }
    void enqueue(int data) { queue->array[++queue->top] = data; }
    void dequeue()
    {
        for (int i = 1; i < queue->top + 1; i++)
            queue->array[i - 1] = queue->array[i];
        queue->array[queue->top--] = 0;
    }
    int size() { return queue->top + 1; }
    bool isEmpty()
    {
        if (size() == 0)
            return true;
        else
            return false;
    }
    int front() { return queue->array[0]; }
    int rear() { return queue->array[queue->top]; }
};

int main()
{
    Queue *q = new Queue();
    int s;
    cin >> s; //size of queue

    int n;
    cin >> n; //size of TestCase

    while (n--)
    {
        string cmd = "";
        cin >> cmd; //input command

        if (cmd == "enqueue")
        {
            int data;
            cin >> data;
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
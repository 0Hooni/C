#include <iostream>
#include <string>

using namespace std;

#define ARR_SIZE 10000

class Array
{
public:
    int arr[ARR_SIZE];
    Array()
    {
        for (int i = 0; i < ARR_SIZE; i++)
            arr[i] = 0;
    }
};

class Stack
{
public:
    Array *stack;
    int t; //pointing index of top
    Stack()
    {
        stack = new Array();
        t = -1;
    }
    bool empty()
    {
        if (t == -1)
            return true;
        else
            return false;
    }
    int top()
    {
        if (empty())
            return t;
        else
            return stack->arr[t];
    }
    void push(int x)
    {
        stack->arr[++t] = x;
    }
    int pop()
    {
        if (empty())
            return t;
        else
        {
            int topData = stack->arr[t];
            stack->arr[t--] = 0;
            return topData;
        }
    }
    int size()
    {
        return this->t + 1;
    }
};

int main()
{
    Stack *s = new Stack();
    int n;
    cin >> n;

    while (n--)
    {
        string cmd = "";
        cin >> cmd;

        if (cmd == "empty")
            cout << s->empty() << endl;
        else if (cmd == "top")
            cout << s->top() << endl;
        else if (cmd == "push")
        {
            int data;
            cin >> data;
            s->push(data);
        }
        else if (cmd == "pop")
            cout << s->pop() << endl;
        else if (cmd == "size")
            cout << s->size() << endl;
    }
}
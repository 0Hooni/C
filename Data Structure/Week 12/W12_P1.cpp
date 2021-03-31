#include <iostream>
#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2

using namespace std;

class cell
{
public:
    int key;
    int value;
    int flag;
    cell()
    {
        key = -1;
        value = -1;
        flag = NOITEM;
    }
};

class DoubleHashing
{
private:
    cell *hashArr;
    int arrSize;
    int curSize;

public:
    DoubleHashing(int size)
    {
        this->arrSize = size;
        hashArr = new cell[arrSize];
        curSize = 0;
    }

    int hashfunc(int key) { return key % arrSize; }
    int hashfunc2(int key) { return (17 - (key % 17)); }

    void find(int key)
    {
        int probing = 1;
        int initial_idx = hashfunc(key) % arrSize;
        int curIdx = (hashfunc(key) + (probing - 1) * hashfunc2(key)) % arrSize;
        bool firstOpr = true;

        while (hashArr[curIdx].flag == ISITEM || hashArr[curIdx].flag == AVAILABLE)
        {
            if (hashArr[curIdx].key == key)
            {
                cout << "find " << key << endl;
                return;
            }
            else if (curIdx == initial_idx && !firstOpr)
            {
                cout << "loop" << endl;
                return;
            }
            probing += 1;
            firstOpr = false;
            curIdx = (hashfunc(key) + (probing - 1) * hashfunc2(key)) % arrSize;
        }
        cout << "don't find " << key << endl;
    }

    void put(int key, int value)
    {
        int probing = 1;
        int initial_idx = hashfunc(key) % arrSize;
        int curIdx = (hashfunc(key) + (probing - 1) * hashfunc2(key)) % arrSize;
        bool firstOpr = true;

        if (isFull())
        {
            cout << "Full" << endl;
        }
        else
        {
            while (hashArr[curIdx].flag == ISITEM)
            {
                if (curIdx == initial_idx && !firstOpr)
                {
                    cout << "loop" << endl;
                    break;
                }
                probing += 1;
                firstOpr = false;
                curIdx = (hashfunc(key) + (probing - 1) * hashfunc2(key)) % arrSize;
            }
            hashArr[curIdx].key = key;
            hashArr[curIdx].value = value;
            hashArr[curIdx].flag = ISITEM;
        }
        curSize++;
    }
    void erase(int key)
    {
        int probing = 1;
        int initial_idx = hashfunc(key) % arrSize;
        int curIdx = (hashfunc(key) + (probing - 1) * hashfunc2(key)) % arrSize;
        bool firstOpr = true;

        if (isEmpty())
        {
            cout << "Full" << endl;
        }
        else
        {
            while (hashArr[curIdx].flag == ISITEM || hashArr[curIdx].flag == AVAILABLE)
            {
                if (hashArr[curIdx].key == key)
                {
                    hashArr[curIdx].flag = AVAILABLE;
                    hashArr[curIdx].key = -1;
                    hashArr[curIdx].value = -1;
                    break;
                }
                else if (curIdx == initial_idx && !firstOpr)
                {
                    cout << "loop" << endl;
                    break;
                }
                probing += 1;
                firstOpr = false;
                curIdx = (hashfunc(key) + (probing - 1) * hashfunc2(key)) % arrSize;
            }
        }
        curSize--;
    }
    bool isFull() { return (curSize == arrSize); }
    bool isEmpty() { return (curSize == 0); }
    void print()
    {
        for (int i = 0; i < arrSize; i++)
            cout << hashArr[i].value << " ";
    }
};

int main()
{
    DoubleHashing *ds;
    int T = 0;
    cin >> T; //number of TestCase

    while (T--)
    {
        int P = 0;
        cin >> P; //size of Arr
        ds = new DoubleHashing(P);

        int Q = 0;
        cin >> Q; //input time;
        while (Q--)
        {
            int input = 0;
            cin >> input;
            ds->put(input, input);
        }
        ds->print();
        cout << endl;
    }

    return 0;
}
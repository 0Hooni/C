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

class LinearHashTable
{
private:
    cell *hashArr;
    int arrSize;
    int curSize;

public:
    LinearHashTable(int size)
    {
        this->arrSize = size;
        hashArr = new cell[arrSize];
        curSize = 0;
    }

    int hashfunc(int key)
    {
        return key % arrSize;
    }
    void find(int key)
    {
        int probing = 1;
        int initial_idx = hashfunc(key) % arrSize;
        int curIdx = hashfunc(key) % arrSize;
        bool firstOpr = true;

        while (hashArr[curIdx].flag == ISITEM || hashArr[curIdx].flag == AVAILABLE)
        {
            if (hashArr[curIdx].key == key)
            {
                cout << "True " << probing << endl;
                return;
            }
            else if (curIdx == initial_idx && !firstOpr)
            {
                cout << "loop" << endl;
                return;
            }
            probing += 1;
            firstOpr = false;
            curIdx = (hashfunc(key) + probing - 1) % arrSize;
        }
        cout << "False " << probing << endl;
    }
    void put(int key, int value)
    {
        int probing = 1;
        int initial_idx = hashfunc(key) % arrSize;
        int curIdx = hashfunc(key) % arrSize;
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
                curIdx = (hashfunc(key) + probing - 1) % arrSize;
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
        int curIdx = hashfunc(key) % arrSize;
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
                curIdx = (hashfunc(key) + probing - 1) % arrSize;
            }
        }
        curSize--;
    }

    bool isFull() { return (curSize == arrSize); }
    bool isEmpty() { return (curSize == 0); }
    void print()
    {
        for (int i = 0; i < arrSize; i++)
            cout << "index is " << i << ", and value is " << hashArr[i].value << endl;
    }
};

int main()
{
    int T = 0; //number of TestCase
    cin >> T;
    LinearHashTable *lt;

    while (T--)
    {
        int P = 0; //size of Arr
        cin >> P;
        lt = new LinearHashTable(P);

        int putTime = 0;
        cin >> putTime; //inserting Time
        while (putTime--)
        {
            int input = 0;
            cin >> input;
            lt->put(input, input);
        }
        int findingTime = 0;
        cin >> findingTime; //  finding Time
        while (findingTime--)
        {
            int key;
            cin >> key;
            lt->find(key); //  
        }
    }
    return 0;
}
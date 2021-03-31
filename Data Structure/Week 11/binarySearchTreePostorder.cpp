#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *leftChild;
    Node *rightChild;
    Node *parent;

    Node()
    {
        this->leftChild = NULL;
        this->rightChild = NULL;
        this->parent = NULL;
    }

    Node(int data)
    {
        this->leftChild = NULL;
        this->rightChild = NULL;
        this->parent = NULL;
        this->data = data;
    }
};

class binarySearchTree
{
private:
    Node *root;

public:
    binarySearchTree() { this->root = NULL; }

    void insert(int inputData)
    {
        Node *newNode = new Node(inputData);
        Node *saveNode = NULL;

        if (root == NULL)
        {
            root = newNode;
        }
        else
        {
            Node *curNode = root;
            while (curNode != NULL)
            {
                saveNode = curNode;
                if (curNode->data == inputData)
                {
                    cout << "Duplication" << endl;
                    return;
                }
                else if (curNode->data > inputData)
                {
                    curNode = curNode->leftChild;
                }
                else
                {
                    curNode = curNode->rightChild;
                }
            }
            if (saveNode->data > inputData)
            {
                newNode->parent = saveNode;
                saveNode->leftChild = newNode;
            }
            else
            {
                newNode->parent = saveNode;
                saveNode->rightChild = newNode;
            }
        }
    }

    Node *find(int inputData)
    {
        Node *curNode = root;

        while (curNode != NULL)
        {
            if (curNode->data == inputData)
                return curNode;
            else if (curNode->data > inputData)
                curNode = curNode->leftChild;
            else
                curNode = curNode->rightChild;
        }
        return NULL;
    }

    Node *min_findNode(Node *_Node)
    {
        Node *curNode = _Node;
        Node *saveNode = NULL;

        while (curNode != NULL)
        {
            saveNode = curNode;
            curNode = curNode->leftChild;
        }
        return saveNode;
    }

    Node *max_findNode(Node *_Node)
    {
        Node *curNode = _Node;
        Node *saveNode = NULL;

        while (curNode != NULL)
        {
            saveNode = curNode;
            curNode = curNode->rightChild;
        }
        return saveNode;
    }

    void erase(int data)
    {
        Node *curNode = find(data);
        int numOfChild = bool(curNode->leftChild) + bool(curNode->rightChild);

        if (numOfChild == 0)
        {
            if (curNode == root)
                root = NULL;
            else
            {
                if (curNode->parent->data > curNode->data)
                    curNode->parent->leftChild = NULL;
                else
                    curNode->parent->rightChild = NULL;
            }
            delete curNode;
        }
        else if (numOfChild == 2)
        {
            Node *minNode = min_findNode(curNode->rightChild);
            int data = minNode->data;
            erase(minNode->data);
            curNode->data = data;
        }
        else if (numOfChild == 1)
        {
            if (curNode == root)
            {
                if (curNode->leftChild != NULL)
                    root = curNode->leftChild;
                else
                    root = curNode->rightChild;
            }
            else
            {
                Node *curParent = curNode->parent;
                Node *child = (curNode->leftChild) ? curNode->leftChild : curNode->rightChild;

                if (curNode->data > child->data)
                {
                    curParent->leftChild = child;
                    child->parent = curParent;
                }
                else
                {
                    curParent->rightChild = child;
                    child->parent = curParent;
                }
            }
            delete curNode;
        }
    }

    void preorderPrint(Node *curNode)
    {
        if (curNode != NULL)
        {
            cout << curNode->data << " ";
            preorderPrint(curNode->leftChild);
            preorderPrint(curNode->rightChild);
        }
    }

    void preorder()
    {
        preorderPrint(root);
        cout << endl;
    }

    void postorderPrint(Node *curNode)
    {
        if (curNode != NULL)
        {
            postorderPrint(curNode->leftChild);
            postorderPrint(curNode->rightChild);
            cout << curNode->data << " ";
        }
    }

    void postorder()
    {
        postorderPrint(root);
        cout << endl;
    }
};

int main()
{
    binarySearchTree *bst;
    int T = 0;
    cin >> T;

    while (T--)
    {
        bst = new binarySearchTree();
        int size = 0;

        int P = 0;
        cin >> P;
        size += P;
        //insert Node
        while (P--)
        {
            int N = 0;
            cin >> N;
            bst->insert(N);
        }

        //delete Node
        int Q = 0;
        cin >> Q;
        size -= Q;
        while (Q--)
        {
            int N = 0;
            cin >> N;
            bst->erase(N);
        }

        if (size == 0)
            cout << "Empty" << endl;
        else
            bst->postorder();
    }

    return 0;
}
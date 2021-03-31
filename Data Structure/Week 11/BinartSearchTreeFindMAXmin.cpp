#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* leftChild;
    Node* rightChild;
    Node* parent;

    Node(){
        this->leftChild = NULL;
        this->rightChild = NULL;
        this->parent = NULL;
    }

    Node(int data) {
        this->leftChild = NULL;
        this->rightChild = NULL;
        this->parent = NULL;
        this->data = data;
    }
};

class binarySearchTree{
private:
    Node* root;
public:
    binarySearchTree() {this->root = NULL;}

    void insert(int inputData){
        Node* newNode = new Node(inputData);
        Node* saveNode = NULL;

        if(root == NULL) {root = newNode;}
        else{
            Node* curNode = root;
            while(curNode != NULL){
                saveNode = curNode;
                if(curNode->data == inputData) { cout<<"Duplication"<<endl; return; }
                else if(curNode->data > inputData){
                    curNode = curNode->leftChild;
                }
                else { curNode = curNode->rightChild; }
            }
            if(saveNode->data > inputData ){
                newNode->parent = saveNode;
                saveNode->leftChild = newNode;
            }
            else{
                newNode->parent = saveNode;
                saveNode->rightChild = newNode;
            }
        }
    }

    Node* find(int inputData){
        Node* curNode = root;

        while(curNode != NULL){
            if(curNode->data == inputData) return curNode;
            else if(curNode->data > inputData) curNode = curNode->leftChild;
            else curNode = curNode->rightChild;
        }
        return NULL;
    }

    Node* min_findNode(Node* _Node){
        Node* curNode = _Node;
        Node* saveNode = NULL;

        while (curNode != NULL){
            saveNode = curNode;
            curNode = curNode->leftChild;
        }
        return saveNode;
    }

    Node* max_findNode(Node* _Node){
        Node* curNode = _Node;
        Node* saveNode = NULL;

        while (curNode != NULL){
            saveNode = curNode;
            curNode = curNode->rightChild;
        }
        return saveNode;
    }

    void erase(int data){
        Node* curNode = find(data);
        int numOfChild = bool(curNode->leftChild)+bool(curNode->rightChild);

        if(numOfChild == 0){
            if(curNode == root)
                root = NULL;
            else{
                if(curNode->parent->data>curNode->data)
                    curNode->parent->leftChild=NULL;
                else
                    curNode->parent->rightChild=NULL;
            }
            delete curNode;
        }
        else if(numOfChild == 2){
            Node* minNode = min_findNode(curNode->rightChild);
            int data = minNode->data;
            erase(minNode->data);
            curNode->data = data;
        }
        else if(numOfChild == 1){
            if(curNode == root){
                if(curNode->leftChild != NULL)
                    root=curNode->leftChild;
                else
                    root=curNode->rightChild;
            }
            else {
                Node *curParent = curNode->parent;
                Node* child = (curNode->leftChild)?curNode->leftChild : curNode->rightChild;

                if(curNode->data > child->data){
                    curParent->leftChild = child;
                    child->parent = curParent;
                }
                else{
                    curParent->rightChild = child;
                    child->parent = curParent;
                }
            }
            delete curNode;
        }
    }

    void preorderPrint(Node* curNode){
        if(curNode != NULL){
            cout<< curNode->data <<" ";
            preorderPrint(curNode->leftChild);
            preorderPrint(curNode->rightChild);
        }
    }

    void preorder(){
        preorderPrint(root);
        cout<<endl;
    }
};

int main(){
    binarySearchTree* bst = new binarySearchTree();

    int T;
    cin>>T;

    while(T--){
        int P;
        cin>>P;
        bst = new binarySearchTree();
        while(P--){
            int N=0;
            cin>>N;
            bst->insert(N);
        }
        int x = 0;
        cin>>x;

        Node* findNode = bst->find(x);
        cout<<bst->min_findNode(findNode)->data<<" ";
        cout<<bst->max_findNode(findNode)->data<<endl;
    }
}
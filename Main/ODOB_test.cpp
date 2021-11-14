#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(){
        data = 0;
        Node* left = NULL;
        Node* right = NULL;
    }
    Node(int _data){
        this->data = _data;
        this->left = NULL;
        this->right = NULL;
    }
};
class BST{
private:
    Node* root;
    int size;
public:
    BST(){
        this->root = NULL;
        size = 0;
    }
    void insert(int data){
        Node* newNode = new Node(data);
        if(size == 0){
            root = newNode;
            size++;
        } else{
            Node* curPlace = this->root;
            while (curPlace != NULL){
                if(data < curPlace->data) {
                    if(curPlace->left == NULL) {
                        curPlace->left = newNode;
                        break;
                    }
                    curPlace = curPlace->left;
                }
                else {
                    if(curPlace->right == NULL){
                        curPlace->right = newNode;
                        break;
                    }
                    curPlace = curPlace->right;
                }
            }
        }
    }
    void postOrder(Node* curNode){
        if(curNode->left != NULL) postOrder(curNode->left);
        if (curNode->right != NULL) postOrder(curNode->right);
        cout << curNode->data << "\n";
    }
    Node* whoIsRoot(){return this->root;}
};

int main(){
    BST* tree = new BST();
    while (true){
        int n; cin >> n;
        if(cin.eof()) break;
        else tree->insert(n);
    }
    tree->postOrder(tree->whoIsRoot());
}
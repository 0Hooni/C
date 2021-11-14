#include <iostream>
#include <string>
#include <vector>
using namespace std;

enum Color{ red, black };
struct AppData{
    int application;
    int storage;
    int price;
    string name;
    AppData() {
        this->application = 0;
        this->name = "";
        this->storage = 0;
        this->price = 0;
    }
    AppData(int a, string n, int s, int p){
        this->application = a;
        this->name = n;
        this->storage = s;
        this->price = p;
    }
};  //app data structure
struct Node{
    Node* left;
    Node* right;
    Node* parent;
    AppData data;   //app info data
    int depth;
    Color color = red;

    Node(){
        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;
        this->data = AppData();
        this->depth = 0;
        this->color = red;
    }
    Node(AppData _data){
        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;
        this->data = _data;
        this->depth = 0;
        this->color = red;
    }
};
class RBT{
private:
    Node* root;
public:
    RBT(){
        this->root = nullptr;
    }
    //insert Node
    void addApp(int _id, string _name, int _storage, int _price){
        Node* isIsNew = searchApp(_id);
        if(isIsNew != nullptr) return;  //check this data is already inserted in tree

        AppData newApp = AppData(_id, _name, _storage, _price);
        Node* newNode = new Node(newApp);   //make Node for insert tree

        //insert(case : first insert, not first)
        if(this->root == nullptr) {
            newNode->color = black;
            this->root = newNode;
        }
        //else case -> insert new Node in tree base on BST rule
        else{
            Node* current = this->root;
            Node* curParent = nullptr;
            while (current != nullptr){
                curParent = current;
                if(newNode->data.application < current->data.application)
                    current = current->left;
                else current = current->right;
            }
            //insert newNode
            if(newNode->data.application > curParent->data.application)
                curParent->right = newNode;
            else curParent->left = newNode;
            //pairing new Node and his parent
            newNode->parent = curParent;

            //check double red appear & fix
            checkDoubleRed(newNode);
        }
    }

    void checkDoubleRed(Node* cur){
        //check double red while recoloring and restructuring
        while (cur != this->root && cur->parent->color == red){
            Node* grandPar = cur->parent->parent;
            Node* uncle = nullptr;
            //check who is uncle Node
            if(cur->parent == grandPar->left) uncle = grandPar->right;
            else uncle = grandPar->left;

            //recoloring(if uncle Node color is red)
            if(uncle != nullptr && uncle->color == red){
                grandPar->color = red;
                uncle->color = black;
                cur->parent->color = black;
                //check double red appear
                cur = grandPar;
            }

            //restructuring(if uncle Node color is black)
            else {
                bool rotateSide;
                //decide rotate side(left or right) base on uncle's position
                //true : rotate right, false : rotate left
                if(cur->parent == grandPar->left) rotateSide = true;
                else rotateSide = false;

                //change curved case to flat case
                if(cur == (rotateSide ? cur->parent->right : cur->parent->left)){
                    cur = cur->parent;
                    if(rotateSide) rotateLeft(cur);
                    else rotateRight(cur);
                }

                grandPar->color = red;
                cur->parent->color = black;
                if(rotateSide) rotateRight(grandPar);
                else rotateLeft(grandPar);
            }
        }
        //root color always be black
        this->root->color = black;
    }
    void rotateLeft(Node* cur){
        Node* tmp = cur->right;
        cur->right = tmp->left;
        //move children
        if(tmp->left != nullptr) tmp->left->parent = cur;
        tmp->parent = cur->parent;

        if(!cur->parent) this->root = tmp;
        else if(cur == cur->parent->left) cur->parent->left = tmp;
        else cur->parent->right = tmp;
        cur->parent = tmp;
        tmp->left = cur;
    }
    void rotateRight(Node* cur){
        Node* tmp = cur->left;
        cur->left = tmp->right;
        //move children
        if(tmp->right != nullptr) tmp->right->parent = cur;

        //move midNode(par) to center of three(grand, par, child) Node
        tmp->parent = cur->parent;

        //case of cur node position and repair parent
        if(!cur->parent) this->root = tmp;
        else if(cur == cur->parent->left) cur->parent->left = tmp;
        else cur->parent->right = tmp;
        cur->parent = tmp;
        tmp->right = cur;
    }


    Node* searchApp(int _id){
        Node* resNode = this->root;
        //search tree based on id(key) to find app
        while (resNode != nullptr){
            //if _id less than now key -> go left, else go right
            //root->data.application    <- now key
            if(resNode->data.application < _id){    //case of go right
                resNode = resNode->right;
            }
            else if(resNode->data.application > _id){   //case of go left
                resNode = resNode->left;
            }
            else break; //_id == resNode
        }
        //if _id not in tree -> return NULLNode
        return resNode;
    }
    int searchDepth(int _id){
        Node* resNode = this->root;
        int nowDepth = 0;
        //search tree based on id(key) to find app
        while (resNode != nullptr){
            //if _id less than now key -> go left, else go right
            //root->data.application    <- now key
            if(resNode->data.application < _id){    //case of go right
                resNode = resNode->right;
                nowDepth++;
            }
            else if(resNode->data.application > _id){   //case of go left
                resNode = resNode->left;
                nowDepth++;
            }
            else break; //_id == resNode
        }
        //if _id not in tree -> return NULLNode
        return nowDepth;
    }

    void updateApp(int _id, string _name, int _storage, int _price){
        Node* search = searchApp(_id);  //find app in store
        //if _id not in store
        if(search == nullptr) cout << "NULL\n";
        //update application
        else{
            AppData tempForUpdate = AppData(_id, _name, _storage, _price);
            search->data = tempForUpdate;
            cout << searchDepth(_id) << "\n";
        }
    }
    void inorder(Node* currentNode, int s, int e, int p){
        if(currentNode){
            inorder(currentNode->left, s, e, p);
            double discountPercent = (double)(100-p)/(double)100;
            //if now ID's value between s, e -> discount
            if(s <= currentNode->data.application
            && currentNode->data.application <= e)
                currentNode->data.price
                = currentNode->data.price*discountPercent;
            inorder(currentNode->right, s, e, p);
        }
    }
    void discountApp(int start, int end, int percent){
        //traversal 을 통해서 범위 내의 key 값이면 discount process 진행
        inorder(this->root, start, end, percent);
    }

};

int main(){
    int t; cin >> t;
    RBT* store = new RBT();
    while (t--){
        char cmd; cin >> cmd;
        int A, S, P;  //Application, Storage, Price
        string N;  //Name
        if(cmd == 'I'){
            cin >> A >> N >> S >> P;
            store->addApp(A, N, S, P);
            cout << store->searchDepth(A) << "\n";
        }
        else if(cmd == 'F'){
            cin >> A;
            Node* find = store->searchApp(A);
            if (find == nullptr) cout << "NULL\n"; //when find node not in tree
            else {
                cout << store->searchDepth(A) << " " << find->data.name << " "
                << find->data.storage << " " << find->data.price << "\n";
            }
        }
        else if(cmd == 'R'){
            cin >> A >> N >> S >> P;
            store->updateApp(A, N, S, P);
            //출력형식은 updateApp 함수 내부에 구현됐음
        }
        else if(cmd == 'D'){
            int x, y;
            cin >> x >> y >> P;
            store->discountApp(x, y, P);
        }
    }
}
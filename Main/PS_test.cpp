#include <iostream>
#include<vector>
#include<string>
using namespace std;
enum class Color {
    Red, Black
};
/*
노드를 생성
left : 왼쪽 자식 노드
right : 오른쪽 자식 노드
parent : 부모노드
color : 노드 색깔 (Black, Red)
App : ID, Name ,용량, 가격 저장
*/
struct Node {
    Node* left = nullptr;
    Node* right = nullptr;
    Node* parent = nullptr;
    Color color = Color::Black;
    struct App {
        int ID = 0;
        string Name = "";
        int Size = 0;
        int price = 0;
    }app;
};
typedef Node* node;
class Tree {
    node root;
    node leafNode;
public:
    /*
     어플리케이션 정보를 입력하는 함수

     x : 삽일 할 위치 노드
     p : 부모노드
     n : 삽입될 새 노드
     새 노드가 insert될때 Red로 설정한다.

    */
    Tree(){
        this->root = nullptr;
        this->leafNode = nullptr;
    }
    void insert(int A, string N, int S, int P) {
        node n = new Node();
        node x = this->root;
        node p = nullptr;
        n->left = leafNode;
        n->right = leafNode;
        n->parent = nullptr;
        n->app = { A,N,S,P };
        n->color = Color::Red;

        //노드가 처음 삽일떄 위치를 app의 ID를 기준으로 찾아준다.
        while (x != leafNode) {
            p = x;
            if (x->app.ID < A) {
                x = x->right;
            }
            else if (x->app.ID > A) {
                x = x->left;
            }
            else {
                show(x);
                return;
            }


        }

        n->parent = p;
        /*
        p가 null값이면 n은 루트노드
        p의 키값보다 크면 오른쪽 , 작으면 왼쪽에 노드를 연결해준다.
        */
        if (p == nullptr) { //루트노드일경우
            root = n;
        }
        else if (n->app.ID > p->app.ID) {
            p->right = n;
        }
        else {
            p->left = n;
        }
        /*
        n이 루트노드면 Color는 Black으로 해주고 깊이 출력 후 return
        n의 부모노드가 root노드면 n이 red여도 레드블랙트리에 어긋나지 않으므로 그냥 return 해준다.
        그외의 경우에는 레드 블랙 트리의 조건을 고려하기 위해 Fix 함수를 실행
        */
        if (n->parent == nullptr) {
            n->color = Color::Black;
            show(n);
            return;
        }
        else if (n->parent->parent == nullptr) {
            show(n);
            return;
        }
        else {
            Fix(n);
        }
        show(n);
        return;
    }
    /*
    레드블랙트리의 조건을 만족시키는 함수
    grandparent , uncle 노드 생성
    왼쪾으로 돌지 오른쪽으로 돌지 정하기 위헤 locate 변수 사용
    */
    void Fix(node n) {
        while (n != root && n->parent->color == Color::Red) {
            node grandparent = n->parent->parent;
            node uncle;
            bool locate;

            if (n->parent == grandparent->left) {
                uncle = grandparent->right;
                locate = true;
            }
            else {
                uncle = grandparent->left;
                locate = false;
            }
            /* recoloring
            *  부모노드와 uncle노드를 Black색으로 바꿔주고
            * grandparent 노드의 색을 Red로 바꿔준다.
            * grandparent 를 n으로 설정해준다
            */
            if (uncle != leafNode && uncle->color == Color::Red) {
                n->parent->color = Color::Black;
                uncle->color = Color::Black;
                grandparent->color = Color::Red;
                n = grandparent;
            }
            /* restructing
             n을 n의 부모노드로 설정해주고 locate 해당 방향으로 회전 시켜준다.
             회전 함수 종료 후 설정된n의 부모노드 색을 Black,
             grandparent로 설정되었던 노드 색을 Red로 설정해준다.
             이후 grandparent기준으로 locate에 해당되는 방향으로 회전시켜준다.
            */
            else {
                if (n == (locate ? n->parent->right : n->parent->left)) {
                    n = n->parent;
                    if (locate == true) {
                        TurnLeft(n);
                    }
                    else {
                        TurnRight(n);
                    }
                }
                n->parent->color = Color::Black;
                grandparent->color = Color::Red;
                if (locate == true) {
                    TurnRight(grandparent);
                }
                else {
                    TurnLeft(grandparent);
                }
            }
        }
        root->color = Color::Black; //루트노드는 항상 Black
    }
    /*
    restructing 오른쪽방향으로 회전
    n은 현재 기준 노드의 부모노드
    t는 n의 왼쪽자식노드, t의 오른쪽 자식 노드를 n의 왼쪽 자식노드로 연결
    n의 부모노드가 없으면 t가 루트노드이며
    n이 왼쪽자식 노드인 경우에는 t를 n의 부모노드의 왼쪽으로 이동 후 연결시켜준다.
    */
    void TurnRight(node n) {
        node t;
        t = n->left;
        n->left = t->right;
        if (t->right != leafNode)
        {
            t->right->parent = n;
        }
        t->parent = n->parent;

        if (!n->parent)
        {
            root = t;
        }
        else if (n == n->parent->left)
        {
            n->parent->left = t;
        }
        else
        {
            n->parent->right = t;
        }
        n->parent = t;
        t->right = n;
    }
    /*restructing -왼쪽으로 회전*/
    void TurnLeft(node n) {
        node t;
        t = n->right;
        n->right = t->left;
        if (t->left != leafNode)
        {
            t->left->parent = n;
        }
        t->parent = n->parent;

        if (!n->parent)
        {
            root = t;
        }
        else if (n == n->parent->left)
        {
            n->parent->left = t;
        }
        else
        {
            n->parent->right = t;
        }
        n->parent = t;
        t->left = n;
    }
    /*
    * insert해준 노드의 깊이를 탐색하는 함수이다.
    */
    void show(node n)
    {
        int sum = 0;
        while (n != root) {
            if (n->parent == root) {
                sum++;
                break;
            }
            n = n->parent;
            sum++;
        }
        cout << sum << "\n";
    }
    /*애플리케이션 검색
    * 루트노드를 중심으로 ID를 찾아 내려간다.
    * 만약 찾으면 깊이와 정보를 출력한다.
    * 못찾는경우 NULL출력
    */
    void searchApp(int A) {
        node x = this->root;
        int depth = 0;
        while (x != leafNode) {   //x가 leaf노드가 아니면 알맞은 위치로 이동 시킨다.
            if (x->app.ID < A) {
                x = x->right;
                depth++;
            }
            else if (x->app.ID > A) {
                x = x->left;
                depth++;
            }
            else {
                //찾으면 깊이 출력
                cout << depth << " " << x->app.Name << " " << x->app.Size << " " << x->app.price << "\n";
                return;
            }

        }
        cout << "NULL" << "\n";
        return;
    }
    /* 애플리케이션 업데이트
    * 루트노드(x)를 기준으로 시작하여 ID를 찾는다.
    * 찾았을 경우 정보를 업데이트하고 depth를 출력한 후 return 한다.
    * 찾지 못했을 경우 NULL출력
    */
    void updateApp(int A, string N, int S, int P) {
        node x = this->root;
        int depth = 0;
        while (x != leafNode) {   //x가 leaf노드가 아니면 알맞은 위치로 이동 시킨다.
            if (x->app.ID < A) {
                x = x->right;
                depth++;
            }
            else if (x->app.ID > A) {
                x = x->left;
                depth++;
            }
            else {
                x->app.Name = N;
                x->app.Size = S;
                x->app.price = P;
                cout << depth << "\n";
                return;
            }

        }
        cout << "NULL" << "\n";
        return;
    }
    /* 애플리케이션 할인
    * 전위순회를 사용해 트리를 탐색한다.
    * 이때 현재 노드가 x보다 작은경우 해당 노드의 왼쪽자식은 더이상 탐색하지 않고 리턴한다.
    * 만약 해당 노드에 오른쪽 자식이 있을경우에는 오른쪽 자식 노드를 기준으로 순회한다.
    * 현재노드가 y보다 큰경우에는 해당노드의 오른쪽자식을 더이상 탐색하지 않고 리턴한다.
    * 만약 해당 노드에 왼쪽자식이 있을경우에는 왼쪽자식노드를 기준으로 순회 한다.
    */
    void discountApp(int x, int y, int P) {
        checkfirst(this->root, x, y, P);

    }
    void checkfirst(node current, int x, int y, int P) {
        if (current== leafNode) {
            return;
        }
        else if (current->app.ID < x) {
            if (current->right!=leafNode) {
                checkfirst(current->right, x, y, P);;
            }
            return;
        }
        else if (current->app.ID > y) {
            if (current->left!=leafNode) {
                checkfirst(current->left, x, y, P);
            }
            return;
        }
        checkfirst(current->left, x, y, P);
        current->app.price = (current->app.price * (100 - P)) / 100;

        checkfirst(current->right, x, y, P);
    }



};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num;
    int A, S, P, x, y;
    string N;
    char R;
    cin >> num;
    Tree* T = new Tree();
    for (int i = 0; i < num; i++) {
        cin >> R;
        if (R == 'I') {
            cin >> A >> N >> S >> P;
            T->insert(A, N, S, P);

        }
        else if (R == 'F') {
            cin >> A;
            T->searchApp(A);
        }
        else if (R == 'R') {
            cin >> A >> N >> S >> P;
            T->updateApp(A, N, S, P);
        }
        else if (R == 'D') {
            cin >> x >> y >> P;
            T->discountApp(x, y, P);
        }
    }
}
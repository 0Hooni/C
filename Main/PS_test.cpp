/*
* C++ 이용하여 Red Black Tree 구현하기
*
* 목적 : Red Black Tree 공부 하기 위해 작성했으며,
*       C++ 이용하여 작성하시는 분들에게 도움이 되고자 했다.
*
* 설명 : key 값은 int만 가능 하며 중복 key는 허용 x
*       이중 연결 리스트로 구현
*       Red / Black은 식별하기 쉽게 enum이용 했으며, bool 이용시 데이터 크기 절약
*
*       class RBTree
*
*       변수 :   root node => root노드는 항상 black
*               leaf node => 끝에 해당하는 노드들은 leaf node들을 가지고 있다.
*                            leaf node라는 것만 알면 되기 때문에 새로운 노드 삽입 때마다 leaf node를 생성 해줄 필요없이
*                            모든 말단 노드들은 이 leaf node를 가리키는 식으로 구현
*                            leaf node는 항상 black
*
*       생성자 : RBTREE =>  node 구조체 생성후
*                          색은 black 초기화
*                          모든 자식은 nullptr로 초기화.
*
*       함수 :   IsKey => key값이 있는지 검사하는 함수
*               Insert => 삽입 함수
*               InsertFixUp => 삽입 후 규칙 깨졌을 시 재조정 함수
*               Delete => 삭제 함수
*               DeleteFixUp => 삭제 후 규칙 깨졌을 시 재조정 함수
*               Transplant => 삭제 시 이용하며, 삭제할 노드의 자식 노드를 부모노드에 연결해주는 함수
*               RotateRight(x) => x기준 오른쪽으로 회전
*               RotateLeft(x) => x기준 왼쪽으로 회전
*
*               Inorder,Preorder,Postorder => 순회 함수
*               tree_minimum(x), tree_maximum(x) => 노드 x 기준으로 가장 왼쪽, 오른쪽 return 함수
*
*               DisplayMenu, SelectMenu => 초기 Menu판 print 함수
*               Insert_helper,Delete_helper,order_helper,print_helper => 각각 수행시 입력받고 조건 에러 처리 위한 함수 와 tree print 해주는 함수
*
*       InsertFixUp과 DeleteFixUp에서 각 case에 대한 설명은 github에 적어 놓았다.
*
* 작성자 : gowoonsori
* github : https://github.com/gowoonsori/my-tech/tree/master/dataStructure/Tree
* 해당 source gist : https://gist.github.com/gowoonsori/a725e29ef1880f0592fe5760f4908c6b
*/

#include <iostream>

    enum Color
            {
        RED,
        BLACK
            };
    struct node
            {
        int key;
        node *left = nullptr;
        node *right = nullptr;
        node *parent = nullptr;
        Color color = BLACK;
            };

    typedef node *NodePtr;

    class RBTREE
            {
            private:
                NodePtr root;     //루트 노드
                NodePtr leafNode; //단말노드

                //key값이 있는지 없는지 검사 있으면 pointer 값, 없으면 nullptr
                NodePtr IsKey(int item)
                {
                    NodePtr t = root;
                    NodePtr parent = NULL;

                    /*key값을 찾거나 없다면 break*/
                    while (t != NULL && t->key != item)
                    {
                        parent = t;
                        t = (item < parent->key) ? parent->left : parent->right;
                    }
                    return t;
                }

                void Insert(int item)
                {
                    // cur : 삽입할 곳 찾기위한 포인터 | curPar : 삽입할 곳의 부모노드
                    NodePtr cur = this->root, curPar = nullptr;
                    NodePtr newNode = new node();
                    newNode->key = item;
                    newNode->color = RED;
                    newNode->parent = nullptr;
                    newNode->left = leafNode;
                    newNode->right = leafNode;

                    /*BST의 일반 삽입 연산*/
                    while (cur != leafNode)
                    {
                        curPar = cur;
                        if (cur->key < item)
                            cur = cur->right;
                        else
                            cur = cur->left;
                    }

                    newNode->parent = curPar;

                    if (curPar == nullptr)
                        root = newNode;
                    else if (newNode->key > curPar->key)
                        curPar->right = newNode;
                    else
                        curPar->left = newNode;

                    //z가 root노드라면
                    if (newNode->parent == nullptr)
                    {
                        newNode->color = BLACK;
                        return;
                    }
                    // z의 부모노드가 root노드라면 Fix Up 필요없이 red컬러로 붙여주면 된다.
                    if (newNode->parent->parent == nullptr)
                    {
                        return;
                    }
                    InsertFixUp(newNode);

                    return;
                }

                void InsertFixUp(NodePtr cur)
                {
                    /*root 노드가 아니고 부모 색이 red라면*/
                    while (cur != root && cur->parent->color == RED)
                    {
                        NodePtr grandparent = cur->parent->parent;
                        NodePtr uncle = (cur->parent == grandparent->left) ? grandparent->right : grandparent->left;
                        bool side = (cur->parent == grandparent->left) ? true : false; //if p[cur]가 p[p[cur]]의 왼쪽 자식이면 1 / 오른쪽이면 0

                        /*case 1*/
                        if (uncle && uncle->color == RED)
                        {
                            cur->parent->color = BLACK;
                            uncle->color = BLACK;
                            grandparent->color = RED;
                            cur = grandparent;
                        }

                        /*case 2
                            side == true ) p[cur]는 p[p[cur]]의 왼쪽 자식 인 경우이다.
                            side == false ) p[cur]는 p[p[cur]]의 오른쪽 자식 인 경우이다. */
                        else
                        {
                            /*case 2-1*/
                            if (cur == (side ? cur->parent->right : cur->parent->left))
                            {
                                cur = cur->parent;
                                side ? RotateLeft(cur) : RotateRight(cur);
                            }
                            /*case 2-2*/
                            cur->parent->color = BLACK;
                            grandparent->color = RED;
                            side ? RotateRight(grandparent) : RotateLeft(grandparent);
                        }
                    }
                    root->color = BLACK;
                }

                /*cur를 중심으로 왼쪽으로 회전*/
                void RotateLeft(NodePtr cur)
                {
                    NodePtr tmp;

                    tmp = cur->right;
                    cur->right = tmp->left;
                    if (tmp->left != leafNode)
                    {
                        tmp->left->parent = cur;
                    }
                    tmp->parent = cur->parent;

                    if (!cur->parent)
                    {
                        root = tmp;
                    }
                    else if (cur == cur->parent->left)
                    {
                        cur->parent->left = tmp;
                    }
                    else
                    {
                        cur->parent->right = tmp;
                    }
                    cur->parent = tmp;
                    tmp->left = cur;
                }
                /*tmp를 중심으로 오른쪽으로 회전*/
                void RotateRight(NodePtr cur)
                {
                    NodePtr tmp;

                    tmp = cur->left;
                    cur->left = tmp->right;
                    if (tmp->right != leafNode)
                    {
                        tmp->right->parent = cur;
                    }
                    tmp->parent = cur->parent;

                    if (!cur->parent)
                    {
                        root = tmp;
                    }
                    else if (cur == cur->parent->left)
                    {
                        cur->parent->left = tmp;
                    }
                    else
                    {
                        cur->parent->right = tmp;
                    }
                    cur->parent = tmp;
                    tmp->right = cur;
                }

                /*show tree*/
                void print_helper(NodePtr root, std::string indent, bool last)
                {
                    // print the tree structure on the screen
                    if (root != leafNode)
                    {
                        std::cout << indent;
                        if (last)
                        {
                            std::cout << "R----";
                            indent += "     ";
                        }
                        else
                        {
                            std::cout << "L----";
                            indent += "|    ";
                        }

                        std::string sColor = (root->color == RED) ? "RED" : "BLACK";
                        std::cout << root->key << "(" << sColor << ")" << std::endl;
                        print_helper(root->left, indent, false);
                        print_helper(root->right, indent, true);
                    }
                }

                /*중위순회*/
                void Inorder(NodePtr target)
                {
                    if (target == leafNode)
                        return;
                    Inorder(target->left);
                    std::cout << target->key << " ";
                    Inorder(target->right);
                }
                /*후위순회*/
                void Postorder(NodePtr target)
                {
                    if (target == leafNode)
                        return;
                    Postorder(target->left);
                    Postorder(target->right);
                    std::cout << target->key << " ";
                }
                /*전위순회*/
                void Preorder(NodePtr target)
                {
                    if (target == leafNode)
                        return;
                    std::cout << target->key << " ";
                    Preorder(target->left);
                    Preorder(target->right);
                }

            public:
                RBTREE()
                {
                    leafNode = new node;
                    leafNode->color = BLACK;
                    leafNode->left = nullptr;
                    leafNode->right = nullptr;
                    leafNode->parent = nullptr;
                    root = leafNode;
                }
                //최솟값 찾기
                NodePtr tree_minimum(NodePtr x)
                {
                    while (x->left != leafNode)
                    {
                        x = x->left;
                    }
                    return x;
                }
                //최댓값 찾기
                NodePtr tree_maximum(NodePtr x)
                {
                    while (x->right != leafNode)
                    {
                        x = x->right;
                    }
                    return x;
                }

                void DisplayMenuBoard()
                {
                    std::cout << "               Menu " << std::endl;
                    std::cout << "          1. Insert Key     " << std::endl;
                    std::cout << "          2. Delete Key     " << std::endl;
                    std::cout << "          3. Show Tree      " << std::endl;
                    std::cout << "          4. choose order   " << std::endl;
                    std::cout << "          5. show Menu      " << std::endl;
                    std::cout << "          6. clear Display  " << std::endl;
                    std::cout << "          7. exit           " << std::endl;
                    std::cout << std::endl;
                }
                void SelectMenu()
                {
                    DisplayMenuBoard();
                    int i = -1;

                    while (i != 8)
                    {
                        std::cout << "--> select   :   ";
                        std::cin >> i;
                        switch (i)
                        {
                            case 1:
                                Insert_helper();
                                break;
                                case 2:
                                    Delete_helper();
                                    break;
                                    case 3:
                                        print_helper(root, "", true);
                                        break;
                                        case 4:
                                            Order_helper();
                                            break;
                                            case 5:
                                                DisplayMenuBoard();
                                                break;
                                                case 6:
                                                    system("cls");
                                                    DisplayMenuBoard();
                                                    break;
                                                    case 7:
                                                        return;
                                                    default:
                                                        std::cout << " !!! Wrong entered !!!\n"
                                                        << std::endl;
                        }
                    }
                }

                void Insert_helper()
                {
                    int item;
                    std::cout << "Key to insert  :  ";
                    std::cin >> item;
                    if (IsKey(item))
                    {
                        std::cout << "!!! " << item << " is already exists !!!\n";
                        return;
                    }
                    Insert(item);
                }
                void Delete_helper()
                {
                    int item;
                    std::cout << "Key to delete  :  ";
                    std::cin >> item;
                    return;
                }
                void Order_helper()
                {
                    int i;
                    std::cout << "         == Order Menu ==" << std::endl;
                    std::cout << "          1. PreOrder" << std::endl;
                    std::cout << "          2. InOrder" << std::endl;
                    std::cout << "          3. PostOrder" << std::endl;
                    std::cout << "          4. exit" << std::endl;
                    std::cout << " --> select  :  ";

                    std::cin >> i;
                    switch (i)
                    {
                        case 1:
                            Preorder(this->root);
                            std::cout << std::endl;
                            break;
                            case 2:
                                Inorder(this->root);
                                std::cout << std::endl;
                                break;
                                case 3:
                                    Postorder(this->root);
                                    std::cout << std::endl;
                                    break;
                                    case 4:
                                        return;
                                    default:
                                        std::cout << " !!! Wrong enter !!!\n"
                                        << std::endl;
                                        break;
                    }
                    return;
                }
            };

    int main()
    {
        RBTREE tree;
        tree.SelectMenu();

        return 0;
    }


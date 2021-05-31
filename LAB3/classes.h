#ifndef classes_h
#define classes_h
#include <iostream>
using namespace std;

template <typename T> //Node class
class Node {
private:
    T data;
    unsigned char height;
    Node<T>* left;
    Node<T>* right;
    Node() {
        left = right = nullptr;
        height = 1;
    };
public:
    T getData() {
        return data;
    }
    void changeData(T newData);
    void push(Node<T>*& root, T data);
    void printPLK(Node<T>*& root);
    void printKLP(Node<T>*& root);
    void printKPL(Node<T>*& root);
    void printLPK(Node<T>*& root);
    void printPKL(Node<T>*& root);
    void printLKP(Node<T>*& root);
    void cleanMemory(Node<T>*& root);
    void deleteNode(Node<T>*& root, T key);
    Node<T>* getSubTree(Node<T>*& root, T key);
    void assembleTree(Node<T>*& var, Node<T>* root, T Key);
    void copyNode(Node<T>*& target, Node<T>* root);
    void setStringPLK(Node<T>*& root, string& buff);
    void setStringKLP(Node<T>*& root, string& buff);
    void checkPresence(Node<T>* root, T key, bool& check);
    void compareNodes(Node<T>* root1, Node<T>* root2, bool& check);
    void checkNodePresence(Node<T>* root1, Node<T>* root2, bool& check);
    void addNode(Node<T>*& target, Node<T>* root);
    void map(Node<T>*& root, void (*f)(Node<T>*& root));
    void where(Node<T>* root, bool (*f)(Node<T>* root));
    unsigned char h(Node<T>* p);
    int bfactor(Node<T>* p);
    void fixheight(Node<T>* p);
    Node<T>* rotateright(Node<T>* p);
    Node<T>* rotateleft(Node<T>* p);
    Node<T>* balance(Node<T>* p);
    Node<T>* insert(Node<T>*&p, T data);
    void map1(Node<T>*& root, void (*f)(Node<T>*& root, T i));


};

//��������� ������ � ����
template <typename T>
void Node<T>::changeData(T newData) {
    data = newData;
}

template <typename T>
void Node<T>::fixheight(Node<T>* p)
{
    unsigned char hl = h(p->left);
    unsigned char hr = h(p->right);
    p->height = (hl > hr ? hl : hr) + 1;
}

template <typename T>
int Node<T>::bfactor(Node<T>* p)
{
    return h(p->right) - h(p->left);
}

template <typename T>
unsigned char Node<T>::h(Node<T>* p)
{
    return p ? p->height : 0;
}

template <typename T>
Node<T>* Node<T>::rotateright(Node<T>* p) // ������ ������� ������ p
{
    Node* q = p->left;
    p->left = q->right;
    q->right = p;
    fixheight(p);
    fixheight(q);
    return q;
}

template <typename T>
Node<T>* Node<T>::rotateleft(Node<T>* q) // ����� ������� ������ q
{
    Node<T>* p = q->right;
    q->right = p->left;
    p->left = q;
    fixheight(q);
    fixheight(p);
    return p;
}

template <typename T>
Node<T>* Node<T>::balance(Node<T>* p) // ������������ ���� p
{
    fixheight(p);
    if (bfactor(p) == 2)
    {
        if (bfactor(p->right) < 0)
            p->right = rotateright(p->right);
        return rotateleft(p);
    }
    if (bfactor(p) == -2)
    {
        if (bfactor(p->left) > 0)
            p->left = rotateleft(p->left);
        return rotateright(p);
    }
    return p; // ������������ �� �����
}
//������� �������� � ������
template <typename T>
Node<T>*  Node<T>::insert(Node<T>*&p, T data) // ������� ����� k � ������ � ������ p
{
    if (p == nullptr) {
        p = new Node<T>;
        p->data = data;
        p->left = p->right = nullptr;
        return p;
    }
    else if (data < p->data)
        p->left=insert(p->left, data);
    else
        p->right=insert(p->right, data);

    return balance(p);
}
template <typename T>
void Node<T>::push(Node<T>*&root, T data) {
    //���� ���� ������
    if (root == nullptr) {
        root = new Node<T>;
        root->data = data;
        root->left = root->right = nullptr;
    }
    //���� � ���� ���� ��������
    else if (data > root->data) 
        root->push(root->right, data);
    else 
        root->push(root->left, data);
}



//�������������� ������ � ������� ������� ���
template <typename T>
void Node<T>::printPLK(Node<T>*& root) {
    if (root != nullptr) {
        root->right->printPLK(root->right);
        root->left->printPLK(root->left);
        cout << root->data << " ";
    }
}

//�������������� ������ � ������� ������� ���
template <typename T>
void Node<T>::printKLP(Node<T>*& root) {
    if (root != nullptr) {
        cout << root->data << " ";
        root->left->printKLP(root->left);
        root->right->printKLP(root->right);
    }
}

//�������������� ������ � ������� ������� ���
template <typename T>
void Node<T>::printLPK(Node<T>*& root) {
    if (root != nullptr) {
        root->left->printLPK(root->left);
        root->right->printLPK(root->right);
        cout << root->data << " ";
    }
}
//�������������� ������ � ������� ������� ���
template <typename T>
void Node<T>::printKPL(Node<T>*& root) {
    if (root != nullptr) {
        cout << root->data << " ";
        root->right->printKPL(root->right);
        root->left->printKPL(root->left);
    }
}
//�������������� ������ � ������� ������� ���
template <typename T>
void Node<T>::printLKP(Node<T>*& root) {
    if (root != nullptr) {
        root->left->printLKP(root->left);
        cout << root->data << " ";
        root->right->printLKP(root->right);
    }
}
//�������������� ������ � ������� ������� ���
template <typename T>
void Node<T>::printPKL(Node<T>*& root) {
    if (root != nullptr) {
        root->right->printPKL(root->right);
        cout << root->data << " ";
        root->left->printPKL(root->left);
    }
}

//����������� ���
template <typename T>
void Node<T>::copyNode(Node<T>*& target, Node<T>* root) {
    if (root != nullptr) {
        target = new Node<T>;
        target->data = root->data;
        target->left = target->right = nullptr;
        target->left->copyNode(target->left, root->left);
        target->right->copyNode(target->right, root->right);
    }
}

//��������� ������ � ���� ��������� ������
template <typename T>
void Node<T>::setStringPLK(Node<T>*& root, string& buff) {
    if (root != nullptr) {
        root->right->getStringPLK(root->right, buff);
        root->left->getStringPLK(root->left, buff);
        buff += to_string(root->data) + " ";
    }
}

template <typename T>
void Node<T>::setStringKLP(Node<T>*& root, string& buff) {
    if (root != nullptr) {
        buff += to_string(root->data) + " ";
        root->left->getStringPLK(root->left, buff);
        root->right->getStringPLK(root->right, buff);
    }
}

//�������� ���������
template <typename T>
void Node<T>::deleteNode(Node<T>*& root, T key) {
    if (root != nullptr) {
        if (root->data == key) {
            root->right->cleanMemory(root->right);
            root->left->cleanMemory(root->left);
        }
        else {
            root->right->deleteNode(root->right, key);
            root->left->deleteNode(root->left, key);
        }
    }
}

//������� ������
template <typename T>
void Node<T>::cleanMemory(Node<T>*& root) {
    if (root != nullptr) {
        root->right->cleanMemory(root->right);
        root->left->cleanMemory(root->left);
        delete root;
        root = nullptr;
    }
}

//��������� ���������
template <typename T>
Node<T>* Node<T>::getSubTree(Node<T>*& root, T key) {
    Node<T>* var = nullptr;
    var->assembleTree(var, root, key);
    return var;
}

//������ � ��������� ���������
template <typename T>
void Node<T>::assembleTree(Node<T>*& var, Node<T>* root, T key) {
    if (root != nullptr) {
        if (root->data == key) {
            var->copyNode(var, root);
        }
        else {
            var->assembleTree(var, root->right, key);
            var->assembleTree(var, root->left, key);
        }
    }
}

//�������� ������� ��������
template <typename T>
void Node<T>::checkPresence(Node<T>* root, T key, bool& check) {
    if (root != nullptr) {
        if (root->data == key) {
            check = true;
        }
        else {
            root->right->checkPresence(root->right, key, check);
            root->left->checkPresence(root->left, key, check);
        }
    }
}

//��������� ��������
template <typename T>
void Node<T>::compareNodes(Node<T>* root1, Node<T>* root2, bool& check) {
    if ((root1 != nullptr) * (root2 != nullptr)) {
        if (root1->data == root2->data) {
            check = true;
            root1->right->compareNodes(root1->right, root2->right, check);
            root1->left->compareNodes(root1->left, root2->left, check);
        }
        else {
            check = false;
        }
    }
}

//�������� ������� ���������
template <typename T>
void Node<T>::checkNodePresence(Node<T>* root1, Node<T>* root2, bool& check) {
    if (root2 != nullptr) {
        if (root1->data == root2->data) {
            root1->compareNodes(root1, root2, check);
        }
        else {
            root2->right->checkNodePresence(root1, root2->right, check);
            root2->left->checkNodePresence(root1, root2->left, check);
        }
    }
}

//������� ��������
template <typename T>
void Node<T>::addNode(Node<T>*& target, Node<T>* root) {
    if (target == nullptr) {
        target->copyNode(target, root);
    }
    else if (root->data > target->data) {
        target->right->addNode(target->right, root);
    }
    else {
        target->left->addNode(target->left, root);
    }
}
 

template <typename T>
void Node<T>::map(Node<T>*& root, void (*f)(Node<T>*& root)) {
    if (root != nullptr) {
        root->right->map(root->right, f);
        root->left->map(root->left, f);
        f(root);
    }
}

//map function

//int

void intPlus(Node<int>*& root) {
    root->changeData(root->getData() + 5);
}

void intMinus(Node<int>*& root) {
    root->changeData(root->getData() - 10);
}

//double

void doublePlus(Node<double>*& root) {
    root->changeData(root->getData() + 5);
}

void doubleMinus(Node<double>*& root) {
    root->changeData(root->getData() - 10);
}

//string

void stringChangeRegister(Node<string>*& root) {
    int i = 0;
    string u = root->getData();
    while (u[i] != '\0') {
        if (isupper(u[i])) {
            u[i] = tolower(u[i]);
        }
        else if (isupper(u[i]) == 0) {
            u[i] = toupper(u[i]);
        }
        i++;
    }
    root->changeData(u);
}

void stringMakeLess(Node<string>*& root) {
    string u = root->getData();
    u[sizeof(u) - 1] = '\0';
    root->changeData(u);
}

//where
template <typename T>
void Node<T>::where(Node<T>* root, bool (*f)(Node<T>* root)) {
    if (root != nullptr) {
        root->right->where(root->right, f);
        root->left->where(root->left, f);
        if (f(root)) {
            cout << root->data << " ";
        }
    }
}

/*Where functions*/

//int

bool intIfEven(Node<int>* root) {
    if (root->getData() % 2 == 0) {
        return true;
    }
    else {
        return false;
    }
}

bool intIfOdd(Node<int>* root) {
    if (root->getData() % 2 != 0) {
        return true;
    }
    else {
        return false;
    }
}

//double

bool doubleIfLargerThanTen(Node<double>* root) {
    if (root->getData() > 10) {
        return true;
    }
    else {
        return false;
    }
}

bool doubleIfLesserThanZero(Node<double>* root) {
    if (root->getData() < 0) {
        return true;
    }
    else {
        return false;
    }
}

//string

bool stringIfLargerThanEight(Node<string>* root) {
    int i = 0;
    string u = root->getData();
    while (u[i] != '\0') {
        i++;
    }
    if (i + 1 >= 8) {
        return true;
    }
    else {
        return false;
    }
}

bool stringIfLesserThanSix(Node<string>* root) {
    int i = 0;
    string u = root->getData();
    while (u[i] != '\0') {
        i++;
    }
    if (i + 1 < 6) {
        return true;
    }
    else {
        return false;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

template <typename T> //Tree class ��� �������� ��� �����
class Tree {
private:
    Node<T>* root;
public:
    Tree() { root = nullptr; };
    //void push(T data);
    void addTree(Tree<T> tree);
    void printPLK();
    void printKLP();
    void printKPL();
    void printLPK();
    void printPKL();
    void printLKP();
    void map(void (*f)(Node<T>*& root));
    void where(bool (*f)(Node<T>* root));
    void deleteNode(T key);
    string getStringPLK();
    string getStringKLP();
    void deleteTree();
    Node<T>* getRoot();
    void getSubTree(Tree<T> tree, T key);
    bool checkPresence(T key);
    bool compareTrees(Tree<T> tree);
    bool checkPresence(Tree<T> tree);
    void insert(Tree<T> tree,T data);
    void push(T data);
};

//������ ��� ��������
template <typename T>
void Tree<T>::insert(Tree<T> tree,T data) // ������� ����� k � ������ � ������ p
{
    root = tree.root->insert(tree.root, data);
    //root->insert( root, data);
   // root->insert(root,data);
}

template <typename T>
void Tree<T>::push(T data) {
    root->push(root, data);
}

template <typename T>
void Tree<T>::addTree(Tree<T> tree) {
    root->addNode(root, tree.root);
}

template <typename T>
void Tree<T>::printPLK() {
    root->printPLK(root);
    cout << endl;
}

template <typename T>
void Tree<T>::printLPK() {
    root->printLPK(root);
    cout << endl;
}

template <typename T>
void Tree<T>::printKLP() {
    root->printKLP(root);
    cout << endl;
}

template <typename T>
void Tree<T>::printLKP() {
    root->printLKP(root);
    cout << endl;
}

template <typename T>
void Tree<T>::printPKL() {
    root->printPKL(root);
    cout << endl;
}

template <typename T>
void Tree<T>::printKPL() {
    root->printKPL(root);
    cout << endl;
}

template <typename T>
Node<T>* Tree<T>::getRoot() {
    return root;
}

template <typename T>
void Tree<T>::map(void (*f)(Node<T>*& root)) {
    root->map(root, f);
}

template <typename T>
void Tree<T>::where(bool (*f)(Node<T>* root)) {
    root->where(root, f);
}

template <typename T>
void Tree<T>::deleteNode(T key) {
    root->deleteNode(root, key);
}

template <typename T>
string Tree<T>::getStringPLK() {
    string buff = "";
    root->setStringPLK(root, buff);
    return buff;
}

template <typename T>
string Tree<T>::getStringKLP() {
    string buff = "";
    root->setStringKLP(root, buff);
    return buff;
}

template <typename T>
void Tree<T>::getSubTree(Tree<T> tree, T key) {
    root = tree.root->getSubTree(tree.root, key);
}

template <typename T>
void Tree<T>::deleteTree() {
    root->cleanMemory(root);
}

template <typename T>
bool Tree<T>::checkPresence(T key) {
    bool check = false;
    root->checkPresence(root, key, check);
    return check;
}

template <typename T>
bool Tree<T>::compareTrees(Tree<T> tree) {
    bool check = false;
    root->compareNodes(root, tree.root, check);
    return check;
}

template <typename T>
bool Tree<T>::checkPresence(Tree<T> tree) {
    bool check = false;
    root->checkNodePresence(tree.root, root, check);
    return check;
}

#endif /* main_classes */
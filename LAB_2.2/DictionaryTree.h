#ifndef node_hpp
#define node_hpp
#include <iostream>
#include <stdio.h>
template<typename TK, typename TV>
struct node
{
    TK key;
    TV data;
    node<TK, TV>* rson;
    node<TK, TV>* lson;
    unsigned char heigt;
};

template<typename TK, typename TV>
class DictionaryTree: public IDictionary<TK, TV> {
private:
    node<TK, TV>* root;

public:
    unsigned char height_tree() {
        return root->heigt;
    }

    DictionaryTree() {
        root = nullptr;
    }

    TK* GetKeys() {
        TK* keys = new TK[SizeTree(root, 0)];
        return GetKeysTree(root, 0, keys);
    }

    TV* GetValues() {
        TV* val = new TV[SizeTree(root, 0)];
        return GetValuesTree(root, 0, val);
    }

    bool ContainsKey(TK key) {
        if (findnoderec(key, root) != nullptr)
            return true;
        else
            return false;
    }

    node<TK, TV>* find(TK key) {
        return findnoderec(key, root);
    }

    int GetSize() {
        return SizeTree(root, 0);
    }

    void Print() {
        printTreerev(root, 1);
    }

    TV Get(TK key) {
        node<TK, TV>* a = find(key);
        return a->data;
    }

    void Add(TK key, TV vall) {
        root=insert(root, key, vall);
    }

    virtual ~DictionaryTree() = default;

protected:
    void printTreerev(node<TK, TV>* top, int level) {
        if (top) {
            printTreerev(top->lson, level + 1);
            cout << top->key <<"[page: "<<top->data <<"]"<< std::endl;
            printTreerev(top->rson, level + 1);
        }
    }

    node<TK, TV>* balance(node<TK, TV>* now_node) {
        fix_height(now_node);
        if (bfactor(now_node) == 2)
        {
            if (bfactor(now_node->rson) < 0)
                now_node->rson = rotateright(now_node->rson);
            return rotateleft(now_node);
        }
        if (bfactor(now_node) == -2)
        {
            if (bfactor(now_node->lson) > 0)
                now_node->lson = rotateleft(now_node->lson);
            return rotateright(now_node);
        }
        return now_node;
    }

    char bfactor(node<TK, TV>* now_node) {
        return height(now_node->rson) - height(now_node->lson);
    }

    node<TK, TV>* rotateright(node<TK, TV>* now_node) {
        node<TK, TV>* new_node = now_node->lson;
        now_node->lson = new_node->rson;
        new_node->rson = now_node;
        fix_height(now_node);
        fix_height(new_node);
        return new_node;
    }

    node<TK, TV>* rotateleft(node<TK, TV>* now_node) {
        node<TK, TV>* new_node = now_node->rson;
        now_node->rson = new_node->lson;
        new_node->lson = now_node;
        fix_height(now_node);
        fix_height(new_node);
        return new_node;
    }

    unsigned char height(node<TK, TV>* now_node) {
        if (now_node != nullptr) {
            return now_node->heigt;
        }
        else return 0;
    }

    void fix_height(node<TK, TV>* now_node) {
        now_node->heigt = 1 + std::max(height(now_node->lson), height(now_node->rson));
    }

    node<TK, TV>* insert(node<TK, TV>* root, TK key, TV val){
        if (root == nullptr) {
            root = new node<TK, TV>;
            root->key = key;
            root->data = val;
            root->lson = root->rson = nullptr;
            return root;
        }
        else if (key < root->key)
            root->lson = insert(root->lson, key, val);
        else
            root->rson = insert(root->rson, key, val);

        return balance(root);
    }

    node<TK, TV>* findnoderec(TK key, node<TK, TV>* now) {
        if (key == now->key) {
            return now;
        }
        else if (key > now->key)
        {
            if (now->rson == nullptr) {
                return nullptr;
            }
            return findnoderec(key, now->rson);
        }
        else if (key < now->key)
        {
            if (now->lson == nullptr) {
                return nullptr;
            }
            return findnoderec(key, now->lson);
        }
    }

    int SizeTree(node<TK, TV>* root, int size) {
        if (root) {
            size = size + 1;
            SizeTree(root->lson, size);
            SizeTree(root->rson, size);
        }
        else
            return size;
    }

    TK* GetKeysTree(node<TK, TV>* root, int i, TK* keys ) {
        if (root != nullptr) {
            keys[i] = root->key;
            i = i + 1;
            GetKeysTree(root->lson, i, keys);
            GetKeysTree(root->rson, i, keys);
        }
        else
            return keys;
    }

    TV* GetValuesTree(node<TK, TV>* root, int i, TV* val) {
        if (root != nullptr) {
            val[i] = root->data;
            i = i + 1;
            GetValuesTree(root->lson, i, val);
            GetValuesTree(root->rson, i, val);
        }
        else
            return val;
    }

};
#endif
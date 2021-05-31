#include "TypeFunction.h"

bool typeChoice(int type) {
    if ((type == 1) + (type == 2) + (type ==3)) {
        return false;
    }
    else {
        return true;
    }
}

int main(int argc, const char* argv[]) {
    int type;
    cout << "Type:\n 1.Int\n 2.Double\n 3.String\n ";
    cin >> type;
    while (typeChoice(type)) {
        cout << "Wrong choice!" << endl;
        cout << "Type: ";
        cin >> type;
    }

    switch (type) {
    case 1: {
        Tree<int> tree;
        intUI(tree);
        tree.deleteTree();
    }
    case 2: {
        Tree<double> tree;
        doubleUI(tree);
        tree.deleteTree();
    }
    case 3: {
        Tree<string> tree;
        stringUI(tree);
        tree.deleteTree();
    }
    }
    return 0;
}

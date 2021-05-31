#ifndef TypeFunction_h
#define TypeFunction_h
#include "classes.h"
#include <random>
#include <string>

void choicer(int n1, int n2, int& c) {
    cout << "Your choice: ";
    cin >> c;
    while ((c < n1) + (c > n2)) {
        cout << "Wrong choice!" << endl;
        cout << "Your choice: ";
        cin >> c;
    }
}

double randDouble(double n1, double n2) {
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(n1, n2);
    return dist(mt);
}

int randInt(int n1, int n2) {
    return round(randDouble(n1, n2));
}

string randString(int n1, int n2) {
    int N = randInt(n1, n2);
    string buf = "abcdefghijklmnopqrstuvwxyz";
    string result = "";
    for (int i = 0; i < N; i++) {
        result += buf[randInt(0, 27)];
    }
    return result;
}

void intUI(Tree<int> tree) {
    int N, c, data;
    c = 1;


    while (c != 0) {
        cout << "Menu:" << endl;
        cout << "1. Create tree" << endl;
        cout << "2. Print tree" << endl;
        cout << "3. Get subtree" << endl;
        cout << "4. Check presence" << endl;
        cout << "5. Map" << endl;
        cout << "6. Where" << endl;
        cout << "7. Delete subtree" << endl;
        cout << "8. Merge trees" << endl;
        cout << "0. Exit" << endl << endl;
        choicer(0, 8, c);
        switch(c){
        case 0: {
            cout << "Goodbye";
            c = 0;
            break;
        }

        case 1: {
            tree.deleteTree();
            cout << "1. Manually" << endl;
            cout << "2. Automatic" << endl;
            choicer(1, 2, c);

            cout << "N: ";
            cin >> N;
            while (N <= 0) {
                cout << "Wrong choice!" << endl;
                cout << "N: ";
                cin >> N;
            }

            switch (c) {
            case 1: {
                cout << "Data: ";

                for (int i = 0; i < N; i++) {
                    cin >> data;
                    tree.insert(tree,data);
                }
                cout << "Your tree (Root - Left - Right):" << endl;
                tree.printKLP();
                break;
            }
            case 2: {
                for (int i = 0; i < N; i++) {
                    tree.insert(tree,(randInt(-100, 100)));
                }
                cout << "Your tree (Root - Left - Right):" << endl;
                tree.printKLP();
                break;
            }

            }
            c = 1;
            break;
        }

        case 2: {
            cout << "How to print:" << endl;
            cout << "1. Right - Left - Root" << endl;
            cout << "2. Left - Right - Root" << endl;
            cout << "3. Root - Left - Right" << endl;
            cout << "4. Root - Right - Left" << endl;
            cout << "5. Left - Root - Right" << endl;
            cout << "6. Right - Root - Left" << endl;
            choicer(1, 6, c);

            cout << "Your tree:" << endl;
            switch (c) {
            case 1: {
                tree.printPLK();
                break;
            }
            case 2: {
                tree.printLPK();
                break;
            }
            case 3: {
                tree.printKLP();
                break;
            }
            case 4: {
                tree.printKPL();
                break;
            }
            case 5: {
                tree.printLKP();
                break;
            }
            case 6: {
                tree.printPKL();
                break;
            }
            }
            c = 2;
            break;
        }
        case 3: {
            cout << "Get subtree from which root?: ";
            cin >> data;
            Tree<int> var;
            var.getSubTree(tree, data);
            cout << "Your subtree (Root - Left - Right):" << endl;
            var.printKLP();
            var.deleteTree();
            break;
        }
        case 4: {
            cout << "1. Check root presence" << endl;
            cout << "2. Check tree presence" << endl;
            choicer(1, 2, c);

            switch(c){
            case 1: {
                cout << "What root to check?: ";
                cin >> data;
                cout << "Presence: " << to_string(tree.checkPresence(data)) << endl;
                break;
            }
            case 2: {
                Tree<int> var;
                cout << "Create tree to check" << endl;
                cout << "N: ";
                cin >> N;
                while (N <= 0) {
                    cout << "Wrong choice!" << endl;
                    cout << "N: ";
                    cin >> N;
                }
                cout << "Data: ";
                for (int i = 0; i < N; i++) {
                    cin >> data;
                    var.insert(tree,data);
                }
                cout << "Presence: " << to_string(tree.checkPresence(var)) << endl;
                break;
            }
            }
            c = 4;
            break;
        }
        case 5: {
            cout << "1. +5" << endl;
            cout << "2. -10" << endl;
            choicer(1, 2, c);
            switch (c) {
            case 1: {
                tree.map(intPlus);
                cout << "Your tree (Root - Left - Right):" << endl;
                tree.printKLP();
                break;
            }
            case 2: {
                tree.map(intMinus);
                cout << "Your tree (Root - Left - Right):" << endl;
                tree.printKLP();
                break;
            }
            }
            c = 5;
            break;
        }
        case 6: {
            cout << "1. Check even elements" << endl;
            cout << "2. Check odd elements" << endl;
            choicer(1, 2, c);

            cout << "Result:" << endl;
            switch (c) {
            case 1: {
                tree.where(intIfEven);
                break;
            }
            case 2: {
                tree.where(intIfOdd);
                break;
            }
            }
            cout << endl;
            c = 6;
            break;
        }
        case 7: {
            cout << "Root to delete: ";
            cin >> data;
            tree.deleteNode(data);
            cout << "Your tree (Root - Left - Right):" << endl;
            tree.printKLP();
            break;
        }
        case 8: {
            cout << "Creating new tree to merge" << endl;
            Tree<int> var;
            cout << "N: ";
            cin >> N;
            while (N <= 0) {
                cout << "Wrong choice!" << endl;
                cout << "N: ";
                cin >> N;
            }
            cout << "Data: ";
            for (int i = 0; i < N; i++) {
                cin >> data;
                var.push(data);
            }
            tree.addTree(var);
            var.deleteTree();
            break;
        }
        }
        cout << endl;
    }
    tree.deleteTree();
}

void doubleUI(Tree<double> tree) {
    double data;
    int N, c = 1;

    while (c != 0) {
        cout << "Menu:" << endl;
        cout << "1. Create tree" << endl;
        cout << "2. Print tree" << endl;
        cout << "3. Get subtree" << endl;
        cout << "4. Check presence" << endl;
        cout << "5. Map" << endl;
        cout << "6. Where" << endl;
        cout << "7. Delete subtree" << endl;
        cout << "8. Merge trees" << endl;
        cout << "0. Exit" << endl << endl;
        choicer(0, 8, c);

        switch (c) {
        case 1: {
            tree.deleteTree();
            cout << "1. Manually" << endl;
            cout << "2. Automatic" << endl;
            choicer(1, 2, c);

            cout << "N: ";
            cin >> N;
            while (N <= 0) {
                cout << "Wrong choice!" << endl;
                cout << "N: ";
                cin >> N;
            }

            switch (c) {
            case 1: {
                cout << "Data: ";

                for (int i = 0; i < N; i++) {
                    cin >> data;
                    tree.insert(tree,data);
                }
                cout << "Your tree (Root - Left - Right):" << endl;
                tree.printKLP();
                break;
            }
            case 2: {
                for (int i = 0; i < N; i++) {
                    tree.insert(tree,(randDouble(-100, 100)));
                }
                cout << "Your tree (Root - Left - Right):" << endl;
                tree.printKLP();
                break;
            }
            }

            c = 1;
            break;
        }
        case 2: {
            cout << "How to print:" << endl;
            cout << "1. Right - Left - Root" << endl;
            cout << "2. Left - Right - Root" << endl;
            cout << "3. Root - Left - Right" << endl;
            cout << "4. Root - Right - Left" << endl;
            cout << "5. Left - Root - Right" << endl;
            cout << "6. Right - Root - Left" << endl;
            choicer(1, 6, c);

            cout << "Your tree:" << endl;
            switch (c) {
            case 1: {
                tree.printPLK();
                break;
            }
            case 2: {
                tree.printLPK();
                break;
            }
            case 3: {
                tree.printKLP();
                break;
            }
            case 4: {
                tree.printKPL();
                break;
            }
            case 5: {
                tree.printLKP();
                break;
            }
            case 6: {
                tree.printPKL();
                break;
            }
            }
            c = 2;
            break;
        }
        case 3: {
            cout << "Get subtree from which root?: ";
            cin >> data;
            Tree<double> var;
            var.getSubTree(tree, data);
            cout << "Your subtree (Root - Left - Right):" << endl;
            var.printKLP();
            var.deleteTree();
            break;
        }
        case 4: {
            cout << "1. Check root presence" << endl;
            cout << "2. Check tree presence" << endl;
            choicer(1, 2, c);

            switch (c) {
            case 1: {
                cout << "What root to check?: ";
                cin >> data;
                cout << "Presence: " << to_string(tree.checkPresence(data)) << endl;
                break;
            }
            case 2: {
                Tree<double> var;
                cout << "Create tree to check" << endl;
                cout << "N: ";
                cin >> N;
                while (N <= 0) {
                    cout << "Wrong choice!" << endl;
                    cout << "N: ";
                    cin >> N;
                }
                cout << "Data: ";
                for (int i = 0; i < N; i++) {
                    cin >> data;
                    var.insert(tree,data);
                }
                cout << "Presence: " << to_string(tree.checkPresence(var)) << endl;
                break;
            }
            }
            c = 4;
            break;
        }
        case 5: {
            cout << "1. +5" << endl;
            cout << "2. -10" << endl;
            choicer(1, 2, c);
            int i;
            switch (c) {
            case 1: {
                tree.map(doublePlus);
                cout << "Your tree (Root - Left - Right):" << endl;
                tree.printKLP();
                break;
            }
            case 2: {
                cout << "Enter a number:" << endl;
                cin >> i;
                tree.map(doubleMinus);
                cout << "Your tree (Root - Left - Right):" << endl;
                tree.printKLP();
                break;
            }
            }
            c = 5;
            break;
        }
        case 6: {
            cout << "1. > 10" << endl;
            cout << "2. < 0" << endl;
            choicer(1, 2, c);

            cout << "Result:" << endl;

            switch (c) {
            case 1: {
                tree.where(doubleIfLargerThanTen);
                break;
            }
            case 2: {
                tree.where(doubleIfLesserThanZero);
                break;
            }
            }
            cout << endl;
            c = 6;
            break;
        }
        case 7: {
            cout << "Root to delete: ";
            cin >> data;
            tree.deleteNode(data);
            cout << "Your tree (Root - Left - Right):" << endl;
            tree.printKLP();
            break;
        }
        case 8: {
            cout << "Creating new tree to merge" << endl;
            Tree<double> var;
            cout << "N: ";
            cin >> N;
            while (N <= 0) {
                cout << "Wrong choice!" << endl;
                cout << "N: ";
                cin >> N;
            }
            cout << "Data: ";
            for (int i = 0; i < N; i++) {
                cin >> data;
                var.push(data);
            }
            tree.addTree(var);
            var.deleteTree();
            break;
        }
        }
        cout << endl;
    }
    tree.deleteTree();
}

void stringUI(Tree<string> tree) {
    string data;
    int N, c = 1;

    while (c != 0) {
        cout << "Menu:" << endl;
        cout << "1. Create tree" << endl;
        cout << "2. Print tree" << endl;
        cout << "3. Get subtree" << endl;
        cout << "4. Check presence" << endl;
        cout << "5. Map" << endl;
        cout << "6. Where" << endl;
        cout << "7. Delete subtree" << endl;
        cout << "8. Merge trees" << endl;
        cout << "0. Exit" << endl << endl;
        choicer(0, 8, c);

        switch (c) {
        case 1: {
            tree.deleteTree();
            cout << "1. Manually" << endl;
            cout << "2. Automatic" << endl;
            choicer(1, 2, c);

            cout << "N: ";
            cin >> N;
            while (N <= 0) {
                cout << "Wrong choice!" << endl;
                cout << "N: ";
                cin >> N;
            }

            switch (c) {
            case 1: {
                cout << "Data: ";
                for (int i = 0; i < N; i++) {
                    cin >> data;
                    tree.push(data);
                }
                cout << "Your tree (Root - Left - Right):" << endl;
                tree.printKLP();
                break;
            }
            case 2: {
                for (int i = 0; i < N; i++) {
                    tree.push(randString(4, 10));
                }
                cout << "Your tree (Root - Left - Right):" << endl;
                tree.printKLP();
                break;
            }
            }

            c = 1;
            break;
        }
        case 2: {
            cout << "How to print:" << endl;
            cout << "1. Right - Left - Root" << endl;
            cout << "2. Left - Right - Root" << endl;
            cout << "3. Root - Left - Right" << endl;
            cout << "4. Root - Right - Left" << endl;
            cout << "5. Left - Root - Right" << endl;
            cout << "6. Right - Root - Left" << endl;
            choicer(1, 6, c);

            cout << "Your tree:" << endl;
            switch (c) {
            case 1: {
                tree.printPLK();
                break;
            }
            case 2: {
                tree.printLPK();
                break;
            }
            case 3: {
                tree.printKLP();
                break;
            }
            case 4: {
                tree.printKPL();
                break;
            }
            case 5: {
                tree.printLKP();
                break;
            }
            case 6: {
                tree.printPKL();
                break;
            }
            }
            c = 2;
            break;
        }
        case 3: {
            cout << "Get subtree from which root?: ";
            cin >> data;
            Tree<string> var;
            var.getSubTree(tree, data);
            cout << "Your subtree (Root - Left - Right):" << endl;
            var.printKLP();
            var.deleteTree();
            break;
        }
        case 4: {
            cout << "1. Check root presence" << endl;
            cout << "2. Check tree presence" << endl;
            choicer(1, 2, c);

            switch (c) {
            case 1: {
                cout << "What root to check?: ";
                cin >> data;
                cout << "Presence: " << to_string(tree.checkPresence(data)) << endl;
                break;
            }
            case 2: {
                Tree<string> var;
                cout << "Create tree to check" << endl;
                cout << "N: ";
                cin >> N;
                while (N <= 0) {
                    cout << "Wrong choice!" << endl;
                    cout << "N: ";
                    cin >> N;
                }
                cout << "Data: ";
                for (int i = 0; i < N; i++) {
                    cin >> data;
                    var.insert(tree, data);
                }
                cout << "Presence: " << to_string(tree.checkPresence(var)) << endl;
                break;
            }
            }
            c = 4;
            break;
        }
        case 5: {
            cout << "1. Change register" << endl;
            cout << "2. Make string less" << endl;
            choicer(1, 2, c);

            switch (c) {
            case 1: {
                tree.map(stringChangeRegister);
                cout << "Your tree (Root - Left - Right):" << endl;
                tree.printKLP();
                break;
            }
            case 2: {
                tree.map(stringMakeLess);
                cout << "Your tree (Root - Left - Right):" << endl;
                tree.printKLP();
                break;
            }
            }
            c = 5;
            break;
        }
        case 6: {
            cout << "1. Size of string >= 8" << endl;
            cout << "2. Size of string < 6" << endl;
            choicer(1, 2, c);

            cout << "Result:" << endl;
            switch (c) {
            case 1: {
                tree.where(stringIfLargerThanEight);
                break;
            }
            case 2: {
                tree.where(stringIfLesserThanSix);
                break;
            }
            }
            cout << endl;
            c = 6;
            break;
        }
        case 7: {
            cout << "Root to delete: ";
            cin >> data;
            tree.deleteNode(data);
            cout << "Your tree (Root - Left - Right):" << endl;
            tree.printKLP();
            break;
        }
        case 8: {
            cout << "Creating new tree to merge" << endl;
            Tree<string> var;
            cout << "N: ";
            cin >> N;
            while (N <= 0) {
                cout << "Wrong choice!" << endl;
                cout << "N: ";
                cin >> N;
            }
            cout << "Data: ";
            for (int i = 0; i < N; i++) {
                cin >> data;
                var.push( data);
            }
            tree.addTree(var);
            var.deleteTree();
            break;
        }
        }
        cout << endl;
    }
    tree.deleteTree();
}

#endif /* UI_hpp */
#include "classes.h"
#include <iostream>
#include <ctime>                    
using namespace std;

int main(int argc, char* argv[])
{
    Tree<int> tree;
      const int array_size = 100001;
    int array[array_size];
        for (int i = 0; i < array_size; i++) {
            array[i] = rand() % 100;
        }
    srand(time(0));
    for (int counter = 0; counter < array_size; counter++)
    {
        tree.insert(tree,array[counter] );
        if (counter % 10000 == 0) {
            cout << counter << endl;
            cout << clock()/ 1000.0  << endl;
            cout << " " << endl;
        }

    }
    system("pause");
    tree.deleteTree();
    //cout << "runtime = " << clock() / 1000.0 << endl; // גנולÿ נאבמעû ןנמדנאללû                  
    //system("pause");
    return 0;
}
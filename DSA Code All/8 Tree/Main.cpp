#include <iostream>
#include <conio.h>
#include "Tree.h"
using namespace std;

int main()
{
    Tree t;

    t.insert(50);
    t.insert(30);
    t.insert(70);
    t.insert(20);
    t.insert(40);
    t.insert(60);
    t.insert(80);

    cout << "Inorder Traversal:" << endl;
    t.display();

    cout << endl << "Searching 40:" << endl;
    if (t.search(40) != NULL)
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    cout << endl << "Removing 20:" << endl;
    t.removeNode(20);

    cout << "Tree after deletion:" << endl;
    t.display();

	getch();
    return 0;
}

#include <iostream>
#include "DoubleyLinkList.h"
using namespace std;

int main()
{
	DoubleLinkedList list;
    int choice, data, target;

    do
    {
        cout << "\n1. Insert at Head";
        cout << "\n2. Insert at Tail";
        cout << "\n3. Insert before Target";
        cout << "\n4. Remove";
        cout << "\n5. Search";
        cout << "\n6. Print Forward";
        cout << "\n7. Print Reverse";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:

            cin >> data;
            list.insertAtHead(data);
            break;
        
		case 2:

            cin >> data;
            list.insertAtTail(data);
            break;

        case 3:
            cin >> target >> data;
            list.insertAtTarget(target, data);
            break;

        case 4:
            cin >> data;
            list.remove(data);
            break;

        case 5:
            cin >> data;
            cout << (list.search(data) ? "Found\n" : "Not Found\n");
            break;

        case 6:
            list.printAll();
            break;

        case 7:
            list.printReverse();
            break;

        }

    } while (choice != 0);

    return 0;
}

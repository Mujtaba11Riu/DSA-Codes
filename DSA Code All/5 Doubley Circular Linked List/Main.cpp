#include <iostream>
#include "List.h"
#include <conio.h>
using namespace std;

int main(){

	List l;

	l.insertAtHead(20);
	l.insertAtTail(30);
	l.insertAtTail(40);

	cout << "\nPrint List\n\n";
	l.print();

	l.insertAtTarget(30, 35);
	cout << "\nAfter insert at target\n\n";
	l.print();

	l.removeNode(30);
	cout << "\nAfter delete\n\n";
	l.print();

	cout << "\nReverse Print\n\n";
	l.printReverse();


	getch();
	return 0;
}

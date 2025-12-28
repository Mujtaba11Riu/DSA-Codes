#include <iostream>
#include <conio.h>
#include "List.h"
using namespace std;


using namespace std;

int main (){

	List l;

	l.insertAtHead(20);
	l.insertAtTail(30);
	l.insertAtTail(40);

	cout<<"\nPrint List\n\n";
	l.print();

	l.insertAtTarget(30, 35);
	cout<<"\nPrint List After insert at target\n\n";
	l.print();


	l.removeNode(30);
	cout<<"\nPrint List After Delete\n\n";
	l.print();

	cout<<"\nPrint List After Insert at head and tail\n\n";
	l.insertAtHead(10);
	l.insertAtTail(50);
	l.print();

	_getch();
	return 0;
}

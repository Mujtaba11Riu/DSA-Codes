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

	cout<<"Print List\n";
	l.print();

	l.insertAtTarget(30, 35);
	cout<<"Print List After insert at target\n";
	l.print();


	l.removeNode(30);
	cout<<"Print List After Delete\n";
	l.print();



	getch();
	return 0;
}

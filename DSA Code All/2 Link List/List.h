#include <iostream>
#include <conio.h>
#include "Node.h"
using namespace std;


class List {

	Node* head;
	Node* tail;

public:

	List();


	bool isEmpty();
	void insertAtHead(int);
	void insertAtTail(int);
	void insertAtTarget(int, int);

	Node* search(int);
	void removeNode(int);

	void print();
};





#include "Node.h"

using namespace std;

class DoubleLinkedList

{

private:
   
	Node *head;
    Node *tail;

public:

	DoubleLinkedList();

    bool isEmpty();
    void insertAtTail(int);
    void insertAtHead(int);
    void insertAtTarget(int, int);
    void remove(int);
    
	Node *search(int);
    void printAll();
    void printReverse();

};
#include <iostream>
#include <conio.h>

using namespace std;

class Node
{

private:
    
	int data;

    Node *next;
    Node *previous;

public:

    Node();
    Node(int);

    int getData();
    void setData(int);

    Node *getNext();
    void setNext(Node *);
    Node *getPrevious();
	void setPrevious(Node *);

};

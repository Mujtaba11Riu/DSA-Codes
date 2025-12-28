#include <iostream>
using namespace std;

class QueueNode {

private:

	int data;
	QueueNode* next;

public:

	QueueNode(int);
	void setData(int);
	int getData();
	QueueNode* getNext();
	void setNext(QueueNode*);

};


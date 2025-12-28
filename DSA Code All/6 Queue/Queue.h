#include <iostream>
#include "QueueNode.h"

using namespace std;

class Queue {

private:

	QueueNode* front;
	QueueNode* rear;

public:

	Queue();
	void enqueue(int);
	void dequeue();
	bool isEmpty();
	void display();

};

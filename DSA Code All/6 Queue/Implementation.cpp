#include"Queue.h"

using namespace std;

//Queue Node Implimentation

QueueNode::QueueNode(int data) 
{
	this->data = data;
	this->next = NULL;
}
void QueueNode::setData(int data) {
	this->data = data;
}

void QueueNode::setNext(QueueNode* next) {
	this->next = next;
}

int QueueNode::getData() {
	return this->data;
}

QueueNode* QueueNode::getNext() {
	return this->next;
}


//Queue Implimentation


Queue::Queue() {

	this->front = NULL;
	this->rear = NULL;

}

bool Queue::isEmpty() {

	if (this->front == NULL) {
		return true;
	}

	else
	{
		return false;
	}

}


void Queue::enqueue(int data) {

	if (isEmpty()) {
		QueueNode* temp = new QueueNode(data);
		front = temp;
		rear = temp;
	}

	else {

		QueueNode* temp = new QueueNode(data);
		rear->setNext(temp);
		rear = temp;

	}
}


void Queue::dequeue() {

	if (isEmpty()) {

		cout << "Queue is Empty" << endl;
	}
	else {

		QueueNode* temp = front;
		front = front->getNext();
		temp->setNext(NULL);

		delete temp;
	}
}


void Queue::display() {

	if (isEmpty()) {
		cout << "Queue is Empty" << endl;
	}

	else {
		QueueNode* temp = front;
		while (temp != NULL) {
			cout << temp->getData() << endl;
			temp = temp->getNext();

		}
	}
}
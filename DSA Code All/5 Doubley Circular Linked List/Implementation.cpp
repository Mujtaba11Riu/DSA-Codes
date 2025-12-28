#include <iostream>
#include "List.h"
using namespace std;

// ================= Node ================= 

Node::Node(){
	data = 0;
	next = NULL;
	prev = NULL;
}

Node::Node(int data){
	this->data = data;
	next = NULL;
	prev = NULL;
}

void Node::setData(int data){
	this->data = data;
}

int Node::getData(){
	return data;
}

void Node::setNext(Node* next){
	this->next = next;
}

Node* Node::getNext(){
	return next;
}

void Node::setPrev(Node* prev){
	this->prev = prev;
}

Node* Node::getPrev(){
	return prev;
}


// ================= List ================= 

List::List()

{

	head = NULL;
	tail = NULL;
}

bool List::isEmpty()
{
	if (head == NULL){
		return true;
	}
	else{
		return false;
	}
}


//insert at tail 

void List::insertAtTail(int data){

	Node* temp = new Node(data);

	if (isEmpty()){

		head = temp;
		tail = temp;

		head->setNext(head);
		head->setPrev(head);
	}

	else
	{

		temp->setNext(head);
		temp->setPrev(tail);

		tail->setNext(temp);
		head->setPrev(temp);

		tail = temp;
	}
}


// insert at head 

void List::insertAtHead(int data){

	if (isEmpty()){
		insertAtTail(data);
	}
	else{

		Node* temp = new Node(data);

		temp->setNext(head);
		temp->setPrev(tail);

		head->setPrev(temp);
		tail->setNext(temp);

		head = temp;
	}
}


//search 

Node* List::search(int tofind){

	if (isEmpty()){
		return NULL;
	}

	Node* temp = head;

	do{
		if (temp->getData() == tofind){
			return temp;
		}

		temp = temp->getNext();

	} while (temp != head);

	return NULL;
}


// insert at target 

void List::insertAtTarget(int tofind, int data){

	Node* target = search(tofind);

	if (target == NULL){
		cout << "Not Found!";
	}

	else if (target == tail){
		insertAtTail(data);
	}

	else{

		Node* temp = new Node(data);
		Node* nextNode = target->getNext();

		temp->setNext(nextNode);
		temp->setPrev(target);

		target->setNext(temp);
		nextNode->setPrev(temp);
	}
}


//remove node 

void List::removeNode(int data){

	if (isEmpty()){
		cout << "List is empty!";
		return;
	}


	Node* targetNode = search(data);

	if (targetNode == NULL){
		cout << "Not Found!";
		return;
	}


	if (head == tail){
		delete head;
		head = NULL;
		tail = NULL;
	}


	else if (targetNode == head){

		head = head->getNext();
		head->setPrev(tail);
		tail->setNext(head);

		delete targetNode;
	}


	else if (targetNode == tail){

		tail = tail->getPrev();
		tail->setNext(head);
		head->setPrev(tail);

		delete targetNode;
	}
	else{

		Node* p = targetNode->getPrev();
		Node* n = targetNode->getNext();

		p->setNext(n);
		n->setPrev(p);

		delete targetNode;
	}
}


//forward 

void List::print(){

	if (isEmpty()){
		return;
	}

	Node* temp = head;

	do{
		cout << temp->getData() << endl;
		temp = temp->getNext();
	} while (temp != head);
}



// reverse 

void List::printReverse(){

	if (isEmpty()){
		return;
	}

	Node* temp = tail;

	do{
		cout << temp->getData() << endl;
		temp = temp->getPrev();
	} while (temp != tail);
}

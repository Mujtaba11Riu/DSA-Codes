#include <iostream>
#include <conio.h>
#include "List.h"
using namespace std;


using namespace std;



Node::Node(){
	data = 0;
	next = NULL;
}

Node::Node(int data){
	
	this->data=data;
	next=NULL;

}

void Node::setData(int data){
	this->data=data;

}


int Node::getData(){
	return data;
}

void Node::setNext(Node* next){
	this->next=next;
}

Node* Node::getNext(){
	return next;
}



//Linked list

List::List(){

	head=NULL;
	tail=NULL;

}

bool List::isEmpty(){
	if (head == NULL){
		return true;
	}
	else {
		return false;
	}
}

void List::insertAtTail(int data ){

	if(isEmpty()){

		Node* temp = new Node (data);
		head=temp;
		tail=temp;

	}

	else {

		Node* temp= new Node(data);
		tail->setNext(temp);
		tail=temp;
}

}



void List::insertAtHead(int data){
	if (isEmpty()){

		insertAtTail(data);
	}
	else{
		Node* temp = new Node (data);
		temp->setNext(head);
		head=temp;
	}


}


Node* List::search(int tofind){

	Node* temp = head;

	while(temp!=NULL){
		if(temp->getData()==tofind){
			return temp;}
		else {
			temp=temp->getNext();
		}
	}
	return NULL;
	
}


void List::insertAtTarget(int tofind , int data){
	Node* target =search(tofind);

	if (target==NULL){
		cout<<"Not Found!";
	}
	else if (target==tail){
		insertAtTail(data);
	}

	else{

		Node* temp=new Node(data);
		temp->setNext(target->getNext());
		target->setNext(temp);


	}
}



void List::removeNode(int data){


	Node * targetNode=head;

	Node* prev = NULL;

	while(targetNode!=NULL){
		if(targetNode->getData()==data){
		break;
		}
		else{
			prev=targetNode;
			targetNode=targetNode->getNext();
		}
	}

	if (targetNode==NULL){
		cout<<"Not Fount!";
	}
	else if (targetNode==head) {
		head=targetNode->getNext();
		targetNode->setNext(NULL);

		delete targetNode;
	}
	else if (targetNode==tail){
		tail=prev;
		prev->setNext(NULL);

		delete targetNode;
	}

	else{
		prev->setNext(targetNode->getNext());
		targetNode->setNext(NULL);

		delete targetNode;
	}




}


void List::print(){

	Node* temp=head;

	while(temp!=NULL){
		cout<<temp->getData()<<endl;
		temp=temp->getNext();



	}

}
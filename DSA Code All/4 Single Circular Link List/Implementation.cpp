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


//insert at tail

void List::insertAtTail(int data ){

	if(isEmpty()){

		Node* temp = new Node (data);
		head=temp;
		tail=temp;
		tail->setNext(head);
		

	}

	else {

		Node* temp= new Node(data);
		tail->setNext(temp);
		tail=temp;
		tail->setNext(head);
		
}

}



void List::insertAtHead(int data){
	if (isEmpty())
	{

		insertAtTail(data);
	}
	else
	{
		Node* temp = new Node (data);
		temp->setNext(head);
		head=temp;
		tail->setNext(head);
		
	}


}


Node* List::search(int tofind){

	if(isEmpty()){

		return NULL;
	}
	
	Node* temp=head;

	do{
		if(temp->getData()==tofind){
			return temp;
		}

		temp=temp->getNext();


	}while(temp!=head);

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

	if (isEmpty()){

		cout<<"List is empty!";
		return;
	}



	Node * targetNode=head;
	Node* prev = tail;


	do{
		
		if(targetNode->getData()==data){
		break;

		}
			prev=targetNode;
			targetNode=targetNode->getNext();
		
	}while(targetNode!=head);





	if (targetNode==NULL){
		cout<<"Not Fount!";
	}


	else if (targetNode==head) {
		head=targetNode->getNext();
		tail->setNext(head);
		targetNode->setNext(NULL);

		delete targetNode;
	}


	else if (targetNode==tail){
		tail=prev;
		tail->setNext(head);
		targetNode->setNext(NULL);

		delete targetNode;
	}

	else
	
	{
		prev->setNext(targetNode->getNext());
		targetNode->setNext(NULL);

		delete targetNode;
	}




}


void List::print(){

	if (isEmpty()){
		return;
	}

	Node* temp = head;

	do{

		cout<<temp->getData()<<endl;
		temp=temp->getNext();

	}while(temp!=head);
	
	
}
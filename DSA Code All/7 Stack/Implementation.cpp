#include <iostream>
#include "Stack.h"
using namespace std;


/* ================= Node ================= */

Node::Node(){
	data = -1;
}

Node::Node(int data){
	this->data = data;
}

int Node::getData(){
	return data;
}

void Node::setData(int data){
	this->data = data;
}


/* ================= Stack ================= */

Stack::Stack(){
	top = -1;
}

bool Stack::isEmpty(){
	if (top == -1){
		return true;
	}
	else{
		return false;
	}
}

bool Stack::isFull(){
	if (top == 99){
		return true;
	}
	else{
		return false;
	}
}

void Stack::push(int data){

	if (isFull()){
		cout << "Stack Overflow!" << endl;
	}
	else{
		top++;
		arr[top].setData(data);
	}
}

void Stack::pop(){

	if (isEmpty()){
		cout << "Stack Underflow!" << endl;
	}
	else{
		arr[top].setData(-1);
		top--;
	}
}

void Stack::display(){

	if (isEmpty()){
		cout << "Stack is Empty!" << endl;
	}
	else{
		for (int i = top; i >= 0; i--){
			cout << arr[i].getData() << endl;
		}
	}
}

int Stack::search(int data){

	if (isEmpty()){
		return -1;
	}
	else{
		for (int i = top; i >= 0; i--){
			if (arr[i].getData() == data){
				return i;
			}
		}
	}
	return -1;
}

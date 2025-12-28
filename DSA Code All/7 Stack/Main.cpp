#include <iostream>
#include <conio.h>
#include "Stack.h"
using namespace std;

int main(){

	Stack s;

	cout << "Check stack empty or not:" << endl;
	if (s.isEmpty()){
		cout << "Stack is Empty" << endl;
	}
	else{
		cout << "Stack is NOT Empty" << endl;
	}

	cout << "\nPush elements:" << endl;
	s.push(10);
	s.push(20);
	s.push(30);

	cout << "\nDisplay stack:" << endl;
	s.display();

	cout << "\nCheck stack full or not:" << endl;
	if (s.isFull()){
		cout << "Stack is Full" << endl;
	}
	else{
		cout << "Stack is NOT Full" << endl;
	}

	cout << "\nSearch element 20:" << endl;
	int pos = s.search(20);
	if (pos != -1){
		cout << "20 found at index " << pos << endl;
	}
	else{
		cout << "20 not found" << endl;
	}

	cout << "\nPop element:" << endl;
	s.pop();

	cout << "\nDisplay after pop:" << endl;
	s.display();

	cout << "\nSearch element 50:" << endl;
	pos = s.search(50);
	if (pos != -1){
		cout << "50 found at index " << pos << endl;
	}
	else{
		cout << "50 not found" << endl;
	}

	getch();
	return 0;
}

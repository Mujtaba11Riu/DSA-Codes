#include"Queue.h"
#include <conio.h>
using namespace std;

int main() {

	Queue q1;
	
	q1.enqueue(1);
	q1.enqueue(2);
	q1.enqueue(3);
	cout << "Queue Data" << endl;
	q1.display();
	q1.dequeue();
	cout << "After Dequeue Queue Data" << endl;
	q1.display();
	
	
	getch();
	return 0;

}
#include"Course.h"
#include <conio.h>
using namespace std;

int main() {

	
	course c1(2237,"CyberSecurity");
	
	c1.enrollstudent(1, "A");
	
	c1.enrollstudent(2, "B");
	
	c1.enrollstudent(3, "C");
	
	cout << "Student List" << endl;
	
	c1.display();
	
	c1.dropstudent(2);
	
	cout << "After Drop Student List" << endl;
	
	c1.display();



	getch();
	return 0;
}
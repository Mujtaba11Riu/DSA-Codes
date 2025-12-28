#include"Student.h"

using namespace std;

class course {

private:
    
	int courseid;
	string coursename;
	int capacity;
	int count;
	student* students;


public:


	course(int, string);
	void setcourseid(int);
	void setcoursename(string);
	int getcourseid();
	string getcoursename();
	void enrollstudent(int , string);
	void resize();
	void dropstudent(int);
	void shift(int);
	int search(int);
	void display();

};
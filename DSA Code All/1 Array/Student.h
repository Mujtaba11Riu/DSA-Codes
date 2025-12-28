#include<iostream>
#include <conio.h>

using namespace std;


class student {

private:

	int id;
	string name;

public:

	student();
	student(int, string);
	void setId(int);
	void setName(string);
	int getId();
	string getName();

};
	

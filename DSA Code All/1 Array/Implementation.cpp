#include"Course.h"
#include<iostream>
#include<string>
using namespace std;

// Student class implementation

student::student() {
	id = 0;
	name = "";
}

student::student(int id, string name) {
	this->id = id;
	this->name = name;
}

void student::setId(int id) {
	this->id = id;
}

void student::setName(string name) {
	this->name = name;
}

int student::getId() {
	return id;
}

string student::getName() {
	return name;
}

// Course class implementation

course::course(int courseid, string coursename) {

	this->courseid = courseid;
	this->coursename = coursename;
	capacity = 3;
	count = 0;
	students = new student[capacity];
}

void course::setcourseid(int courseid) {

	this->courseid = courseid;
}

void course::setcoursename(string coursename) {

	this->coursename = coursename;
}

int course::getcourseid() {

	return courseid;
}

string course::getcoursename() {

	return coursename;
}

void course::enrollstudent(int id, string name) {

	if (count == capacity) {
		resize();
		students[count].setId(id);
		students[count].setName(name);
		count++;

	}

	else {
		students[count].setId(id);
		students[count].setName(name);
		count++;
	}
}


void course::resize() {
	capacity = capacity + 3;
	student* newstudents = new student[capacity];
	for (int i = 0;i < count;i++) {
		newstudents[i].setId(students[i].getId());
		newstudents[i].setName(students[i].getName());
	}

	delete students;
	students = newstudents;
}


int course::search(int tosearch) {
	for (int i = 0;i < count;i++) {
		if (students[i].getId() == tosearch) {
			return i;
		}
	}

	return -1;
}


void course::dropstudent(int todrop) {
	int index = search(todrop);
		if (index == -1) {
			cout << "Not found" << endl;
			return;
		}
		else {
			students[index].setId(-1);
			students[index].setName("");
			shift(index);
			students[count - 1].setId(-1);
			students[count - 1].setName("");
			count--;

		}
}



void course::shift(int index) {
	for (int i = index;i < count - 1;i++) {
		students[i].setId(students[i + 1].getId());
		students[i].setName(students[i + 1].getName());
	}

}



void course::display() {

	cout << "Course ID  " << getcourseid() << endl;
	cout << "Course Name    " << getcoursename() << endl;
	for (int i = 0;i < count;i++) {
		cout << "Student ID   "<< i+1<<" -- " << students[i].getId()<<endl;
		cout << "Student Name   " << i+1 << " -- " << students[i].getName()<<endl;
	}
}


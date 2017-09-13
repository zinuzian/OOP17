#pragma once

#include <string>

using namespace std;

class Student {
	string name;
	string stud_id;
	string dept;
	string age;
	string tel;
public:
	Student(string n, string sid, string d, string a, string t);
	Student();
	string getName();
	string getSid();
	string getDept();
	string getAge();
	string getTel();
	string(Student::*getter[5])(void);
};

class SIManager {
	Student* list;
	int size;
	string filename;
public:
	SIManager(string dir);
	bool insert();
	Student* search();
	bool erase(string sid);
	int showMenu();
	int getSize();
	void printList(string input, int m);
};
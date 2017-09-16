#pragma once
#include <iostream>
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
	void printMe();
};

class SIManager {
	Student* list;
	int size;
	string filename;
public:
	typedef string(Student::*func)();
	SIManager(string dir);
	bool insert();
	void search();
	bool erase(string sid);
	int showMenu();
	Student* match(string input, int m);
	void printList(string input, int m);
	bool saveList();
};
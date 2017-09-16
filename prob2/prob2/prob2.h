#pragma once
#include <iostream>
#include <string>

using namespace std;

class Student {
	//All of student's data are stored as string since it's easy to compare and can store space(' '). 
	string name;	
	string stud_id;	
	string dept;
	string age;
	string tel;
	int widths[5];	//This array is used for printing data of student itself. (width of each strings)
public:
	Student(string n, string sid, string d, string a, string t);	//instantiate student object with given parameters.
	Student();	//instantiate student object with "none" as name
	//Since member variables are private, we need getter functions.
	string getName();
	string getSid();
	string getDept();
	string getAge();
	string getTel();
	string(Student::*getter[5])(void);	//Array of function pointer. Each of them stores address of getter functions. This is used in printMe() function.
	void printMe();	//Print student object's data. Each getter functions are called.
};

class SIManager {
	Student* list;		//When SIManager is instantiated, this variable is going to store students as array of Student. list is always sorted by name.
	int size;			//Stores number of students
	string filename;	//Stores argv[1] for updating text file(saveList())
public:
	typedef string(Student::*func)();	//Since array of function pointer is hard to read, I made a new type
	SIManager(string dir);	//Instantiate SIManager. Load data from text file and make list as array of Student and parse data written in text file. If file doesn't exists, make new file. After list is constructed, sort list by qsort().
	bool insert();	//Insert new student into the list. Make Student object and paste it to list[size]. 
	void search();	//Search student by several options. 
	bool erase(string sid);	//sid is student id that user input. Finds student who matches it and delete him from list and text file. If there's no student matches sid, shows error message. File saving failure also shows error message.
	int showMenu();	//Prints menu list and read user's input and returns it.
	Student* match(string input, int m);	//Finds student who matches given input and returns address of him. nullptr is returned if there's no student matches condition. m is number which represents getter function index. 
	void printList(string input, int m);	//Used in search function. m is number which user input as searching option number. This calls match() in for loop. If match() returns nullptr, loop ends. In every loop, student object calls printMe() to print its data.
	bool saveList();	//Saves current list into the text file. When new student is added or specific student is erased, save updates to text file. Returns false if error occured in saving procedure.
};
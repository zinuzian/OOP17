#include "prob2.h"



string Student::getName()
{
	return name;
}

string Student::getSid()
{
	return stud_id;
}

string Student::getDept()
{
	return dept;
}

string Student::getAge()
{
	return age;
}

string Student::getTel()
{
	return tel;
}

void Student::printMe(){
	for (int i = 0; i < 5; i++){
		cout.width(widths[i]);
		cout << left << (this->*getter[i])();
	}
	cout << endl;
}

Student::Student(string n, string sid, string d, string a, string t)
{
	name = n;
	stud_id = sid;
	dept = d;
	age = a;
	tel = t;
	getter[0] = &Student::getName;
	getter[1] = &Student::getSid;
	getter[2] = &Student::getDept;
	getter[3] = &Student::getAge;
	getter[4] = &Student::getTel;

	widths[0] = 16;
	widths[1] = 16;
	widths[2] = 24;
	widths[3] = 8;
	widths[4] = 13;
}
Student::Student() {
	name = "none";
}



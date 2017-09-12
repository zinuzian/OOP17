#include "prob2.h"

Student::Student(string n, string sid, string d, string a, string t)
{
	name = n;
	stud_id = sid;
	dept = d;
	age = a;
	tel = t;
}
Student::Student() {

}

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






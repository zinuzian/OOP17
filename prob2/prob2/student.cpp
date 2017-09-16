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
		cout << (this->*getter[i])();
		if (i == 4)
			cout << endl;
		else
			cout << "\t";
	}
	//cout << tmp.getName() << "\t" << tmp.getSid() << "\t" << tmp.getDept() << "\t" << tmp.getAge() << "\t" << tmp.getTel() << endl;
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


}
Student::Student() {

}



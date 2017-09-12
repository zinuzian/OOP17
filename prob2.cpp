#include "prob2.h"
#include <fstream>
#include <iostream>
#include <cstdlib>

int compare(const void * a, const void * b)
{
	return (*(Student*)a).getName().compare((*(Student*)b).getName());
}

SIManager::SIManager(string dir)
{
	fstream f;
	filename = dir;
	string str;
	f.open(filename);
	if (f.is_open()) {
		size = 0;
		list = new Student[100];
		while (getline(f, str)) {
			if (str.length() == 0)
				continue;
			if (size == 99){
				cout << "array is full, please erase old data" << endl;
				continue;
			}
			string::size_type pos = str.find("/");
			string n = str.substr(0, pos);
			str = str.substr(pos + 1);

			pos = str.find("/");
			string sid = str.substr(0, pos);
			str = str.substr(pos + 1);

			pos = str.find("/");
			string d = str.substr(0, pos);
			str = str.substr(pos + 1);

			pos = str.find("/");
			string a = str.substr(0, pos);
			str = str.substr(pos + 1);

			pos = str.find("/");
			string t = str.substr(0, pos);
			
			Student* tmp = new Student(n, sid, d, a, t);
			
			list[size] = *tmp;
			size++;
		}
		f.close();
		qsort(list, size, sizeof(Student), compare);
	}
}



bool SIManager::insert()
{
	string n, sid, d, a, t;
	if (size == 99){
		cout << "array is full, please erase old data" << endl;
		return false;
	}
	cout << "- Insertion -" << endl;
	cout << "Name ?  ";
	fflush(stdin);
	getline(cin, n,'\n');
	cout << "Student ID ?  ";
	cin >> sid;
	if (sid.length() != 10){
		cout << "rewrite sid";
		return false;
	}
	cout << "Age ?  ";
	cin >> d;
	cout << "Department ?  ";
	fflush(stdin);
	getline(cin, d, '\n');
	cout << "Tel ?  ";
	cin >> t;

	Student* tmp = new Student(n, sid, d, a, t);
	list[size] = *tmp;
	size++;

	ofstream f;
	f.open(filename,ios::app);
	f << (n + "/" + sid + "/" + d + "/" + a + "/" + t+"\n");
	f.close();
	qsort(list, size, sizeof(Student), compare);
	return true;
}

Student* SIManager::search()
{
	return nullptr;
}

bool SIManager::erase(string sid)
{

	return 0;
}

int SIManager::showMenu(){
	int menu;
	while (1){
		cout << "1. Insertion" << endl;
		cout << "2. Search" << endl;
		cout << "3. Deletion" << endl;
		cout << "4. Exit" << endl;
		cout << "> ";
		cin >> menu;
		if (menu > 4 || menu < 1){
			cout << "wrong input";
		}
		else{
			break;
		}
	}
	return menu;
}

void SIManager::printList(Student* res, int n){

}

int SIManager::getSize(){
	return size;
}

int main(int argc, char* argv[]) {

	SIManager sims(argv[1]);
	bool con = true;
	Student* result;
	while (con){
		int m = sims.showMenu();
		string sid;
		switch (m){
		case 1:	//insertrion
			if (!sims.insert()){
				cout << "error in insertion. Retry\n";
			}
			break;
		case 2:	//search
			result = sims.search();
			if (result == nullptr)
				cout << "there's no such element\n";
			else{
				sims.printList(result,sims.getSize());
			}
			break;
		case 3:	//deletion
			cin >> sid;
			sims.erase(sid);
			break;
		case 4:	//exit
			cout << "\n\n Good Bye..." << endl << endl << endl;
			con = false;
			break;
		}
	}




	return 0;
}



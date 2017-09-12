#include "prob2.h"
#include <fstream>
#include <iostream>
#include <cstdlib>

SIManager::SIManager(string filename)
{
	fstream f;
	string str;
	f.open(filename);
	if (f.is_open()) {
		size = 0;
		list = new Student[100];
		while (getline(f, str)) {
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

	}
}

bool SIManager::insert(Student *s)
{
	if (size == 99){
		cout << "array is full, please erase old data" << endl;
	}

	return true;
}

Student* SIManager::search(int menu)
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

int main(int argc, char* argv[]) {

	SIManager sims(argv[1]);
	bool con = true;
	while (con){
		int m = sims.showMenu();
		switch (m){
		case 1:
			insert()
			break;
		case 2:

			break;
		case 3:

			break;
		case 4:
			cout << "\n\n Good Bye..." << endl;
			con = false;
			break;
		}
	}




	return 0;
}



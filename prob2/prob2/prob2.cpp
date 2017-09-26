#include "prob2.h"
#include <fstream>
#include <cstdlib>

#define NOS 300

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
	list = new Student[NOS];
	if (f.is_open()) {
		size = 0;
		while (getline(f, str)) {
			if (str.length() == 0)
				continue;
			if (size == NOS-1){
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
	else{
		/*FILE* fp;
		fopen_s(&fp, "test1.txt", "w");
		fclose(fp);*/
		ofstream of;
		of.open(filename);
		of.close();
	}
}

bool SIManager::insert()
{
	string n, sid, d, a, t;
	if (size == NOS-1){
		cout << "array is full, please erase old data" << endl;
		return false;
	}
	system("cls");
	cout << "- Insertion -" << endl;
	cout << "Name ?  ";
	fflush(stdin);
	getline(cin, n,'\n');
	cout << "Student ID ?  ";
	cin >> sid;
	if (sid.length() != 10){
		cout << "check student id";
		fflush(stdin); getchar();
		return false;
	}
	cout << "Age ?  ";
	cin >> a;
	cout << "Department ?  ";
	fflush(stdin);
	getline(cin, d, '\n');
	cout << "Tel ?  ";
	cin >> t;

	Student* tmp = new Student(n, sid, d, a, t);
	list[size] = *tmp; //err
	size++;

	if (saveList() == false){
		cout << "Save Failed" << endl;
		fflush(stdin);getchar();
	}
	qsort(list, size, sizeof(Student), compare);
	return true;
}

void SIManager::search()
{
	int m;
	system("cls");
	cout << "- Search -" << endl;
	cout << "1. Search by name" << endl;
	cout << "2. Search by student ID (10 numbers)" << endl;
	cout << "3. Search by department name" << endl;
	cout << "4. Search by Age" << endl;
	cout << "5. List All\n> " << endl;
	fflush(stdin);
	cin >> m;
	switch (m){
	case 5:
		cout << "Name\t\tStudent ID\tDepartment\t\tAge\tTel" << endl;
		for (int i = 0; i < size; i++){
			list[i].printMe();
		}
		fflush(stdin);getchar();
		return;
	case 1:
		cout << "\nName keyword? ";
		break;
	case 2:
		cout << "\nStudent ID? ";
		break;
	case 3:
		cout << "\nDepartment name keyword? ";
		break;
	case 4:
		cout << "\nAge? ";
		break;
	}
	fflush(stdin);
	string input;
	getline(cin, input, '\n');
	if (m == 2 && input.size()!=10){
		cout << "Student ID must consist of 10 digits.";
		fflush(stdin); getchar();
		return;
	}
	printList(input, m);
	return;
}

Student* SIManager::match(string input,int m){
	for (int i = 0; list[i].getName().compare("none"); i++){
		Student tmp = list[i];
		func f = tmp.getter[m-1];
		string res = ((&tmp)->*f)();
		if (res.find(input) != string::npos){	//list is sorted already
			//tmp.printMe();

			return list + i;
		}
	}
	return nullptr;
}

void SIManager::printList(string input, int m){
	
	cout << "Name\t\tStudent ID\tDepartment\t\tAge\tTel" << endl;
	Student* tlist = list;
	Student* tmp;
	for (int i = 0; (tmp = match(input, m)) != nullptr; i++){
		list = tmp + 1;
		tmp->printMe();
	}
	list = tlist;
	fflush(stdin);getchar();
}

bool SIManager::erase(string sid)
{
	Student* tmp = match(sid, 2); //sid match
	if (tmp == nullptr){
		return false;
	}
	string d_name = tmp->getName();
	int idx = (tmp - list) ;
	for (int i = idx; i < size; i++){
		list[i] = list[i + 1];
	}
	size--;
	if (saveList() == false){
		cout << "Save Failed" << endl;
		fflush(stdin);getchar();
	}
	cout << d_name << " is deleted" << endl;
	fflush(stdin);getchar();
	return true;
}


bool SIManager::saveList(){
	ofstream f;
	f.open(filename);
	if (f.is_open()){
		for (int i = 0; i < size; i++){
			Student* tmp = list + i;
			for (int j = 0; j < 5; j++){
				func fn = tmp->getter[j];
				string output = (tmp->*fn)();
				f << output;
				if (j == 4)
					f << "\n";
				else
					f << "/";
			}
		}
		f.close();
		return true;
	}
	return false;
}


int SIManager::showMenu(){
	int menu;
	while (1){
		system("cls");
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
		string sid;
		bool res = false;
		switch (m){
		case 1:	//insertrion
			if (!sims.insert()){
				cout << "error in insertion. Retry\n";
			}
			break;
		case 2:	//search
			sims.search();
			break;
		case 3:	//deletion
			cout << "- Deletion -" << endl;
			cout << "Student ID to delete : ";
			cin >> sid;
			if (sid.size() != 10){
				cout << "Student ID must consist of 10 digits.";
				fflush(stdin); getchar();
				break;
			}
			res = sims.erase(sid);
			if (res == false){
				cout << "No such student" << endl;
				fflush(stdin);getchar();
			}
			break;
		case 4:	//exit
			cout << "\n\n Good Bye..." << endl << endl << endl;
			con = false;
			break;
		}
	}
	



	return 0;
}



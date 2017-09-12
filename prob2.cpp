#include "prob2.h"

SIManager::SIManager(string filename)
{
	fstream f;
	string str;
	f.open(filename);
	if (f.is_open()) {
		list = new Student[100];
		while (getline(f, str)) {
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

			if (!insert(tmp)){
				cout << "sorry, we have an error making list\n";
			}
		}
	}
}

bool SIManager::insert(Student *s)
{
	return 0;
}

Student* SIManager::search(int menu)
{
	return nullptr;
}

bool SIManager::erase(long sid)
{
	return 0;
}

int main(int argc, char* argv[]) {
	string filename = ".\\test1.txt";
	SIManager m(filename);
	return 0;
}



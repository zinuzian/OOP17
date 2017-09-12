#include "prob2.h"

SIManager::SIManager(string filename)
{
	fstream f;
	string str;
	f.open(filename);
	if (f.is_open) {
		list = new Student[100];
		while (getline(f, str)) {
			
		}
	}
}

int SIManager::insert(Student s)
{
	return 0;
}

Student* SIManager::search(int menu)
{
	return nullptr;
}

int SIManager::erase(long sid)
{
	return 0;
}

int main(int argc, char* argv[]) {

}



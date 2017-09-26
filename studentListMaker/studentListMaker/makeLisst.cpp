#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>

#define DELIM '/'

using namespace std;



string makeSid(){
	char n[11] = "0123456789";
	string str;
	for (int i = 0; i < 10; i++){
		str += n[rand() % 10];
	}
	return str;
}

string makeTel(){
	char n[11] = "0123456789";
	string str;
	for (int i = 0; i < 12; i++){
		str += n[rand() % 10];
	}
	return str;
}

int main(){

	string names[50] = { "Daniel Jeon", "Jinwoo Cho", "Jinwoo Jeon", "Hyesung Lee", "Tieree Henry", "Mijee Park", "Suho Lee", 
		"Juno Oh", "Junyung Park", "Sungjae Kim", "Hyunjun Joo", "Hyunjae Lee","Gabriel Santos","Yoona Kim"};
	int num=0;
	while (names[num].compare(""))	{ num++; }
	string *sids = new string[num];
	for (int i = 0; i < num; i++){
		sids[i] = makeSid();
	}
	string dpts[] = { "computer engineering", "digital imaging", "Dept. of management", "electrical engineering", "machanical engineering" };
	int n_d = sizeof(dpts) / sizeof(dpts[0]);
	string ages[] = { "23", "25", "22", "20", "24", "21" };
	int n_a = sizeof(ages) / sizeof(ages[0]);
	string *tels = new string[num];
	for (int i = 0; i < num; i++){
		tels[i] = makeTel();
	}
	
	fstream f;
	string str;

	f.open("file1.txt");
	if (!f.is_open()){
		FILE* fp;
		fopen_s(&fp, "file1.txt", "w");
		fclose(fp);
		f.open("file1.txt");
	}
	for (int i = 0; i < num; i++){
		str = (names[i] + DELIM + sids[i] + DELIM + dpts[rand() % n_d] + DELIM + ages[rand() % n_a] + DELIM + tels[i] + "\n");
		f.write(str.c_str(), str.size());
	}
	f.close();
	system("file1.txt");

	return 0;
}
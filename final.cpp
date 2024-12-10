/**************************************************

COMSC 210 | Final | Skylar Robinson | IDE Used: Eclipse

***************************************************/

#include <iostream>
#include <list>
#include <fstream>
#include <ctime>
using namespace std;

const int NAMES = 99;

string getName();

struct Customer {
	string name, order;
};

int main() {
	srand(time());
	list<Customer> drinkLine;

	return 0;
}

string getName() {
	ifstream in;
	//open the file
	in.open("names.txt");
	if (!in) {
		cout << "File open error.\n";
		return "";
	}
	//get random name
	int num = (rand() % NAMES) + 1;
	string name;
	for (int i = 0; i < num; i++)
		getline(in, name);
	//close file
	in.close();
	return name;
}

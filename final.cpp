/**************************************************

COMSC 210 | Final | Skylar Robinson | IDE Used: Eclipse

***************************************************/

#include <iostream>
#include <list>
#include <fstream>
#include <ctime>
using namespace std;

const int NAMES = 99, DRINKS = 10;
const string drinks[DRINKS] = {"Black Coffee", "Latte", "Mocha", "Frappuccino",
							   "Macchiato", "Cocoa", "Cold Brew", "Americano",
							   "Espresso", "White Mocha"};

struct Customer {
	string name, order;
};

string getName();
string getDrink();
Customer getCust();

int main() {
	srand(time(0));
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

string getDrink() {
	string drink;
	drink = drinks[rand() % DRINKS];
	return drink;
}

Customer getCust() {
	Customer temp;
}

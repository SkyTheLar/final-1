/**************************************************

COMSC 210 | Final | Skylar Robinson | IDE Used: Eclipse

***************************************************/

#include <iostream>
#include <list>
#include <fstream>
#include <ctime>
using namespace std;

const int NAMES = 99, DRINKS = 10, ROUNDS = 10;


struct Customer {
	string name, order;
};

struct CustNode {
	Customer cust;
	CustNode* next;
};

string getName();
string getOrder(string[], int);
Customer getCust(string[], int);
int prob();
void addDrinkCust(CustNode*);
void remDrinkCust(CustNode*);

int main() {
	string drinks[DRINKS] = {"Black Coffee", "Latte", "Mocha", "Frappuccino",
							 "Macchiato", "Cocoa", "Cold Brew", "Americano",
							 "Espresso", "White Mocha"};
	srand(time(0));
	CustNode* drinkLine = nullptr;

	//initialize the queue

	for (int i = 0; i < ROUNDS; i++) {
		if (prob() <= 50) {
			addDrinkCust(drinkLine);
		}
		if (!(drinkLine == nullptr)) {
			remDrinkCust(drinkLine);
		}
	}

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

string getOrder(string arr[], int LEN) {
	string order;
	order = arr[rand() % LEN];
	return order;
}

Customer getCust(string arr[], int LEN) {
	Customer temp;
	temp.name = getName();
	temp.order = getOrder(arr, LEN);
	return temp;
}

int prob() {
	return rand() % 100 + 1;
}

void addDrinkCust(CustNode* head) {


}

void remDrinkCust(CustNode* head) {
	CustNode* current = head;
	head = head->next;
	cout << current->cust.name << " was served.\n";
	delete current;
	current = nullptr;
}

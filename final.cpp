/**************************************************

COMSC 210 | Final | Skylar Robinson | IDE Used: Eclipse

***************************************************/

#include <iostream>
#include <list>
#include <fstream>
#include <ctime>
#include <deque>
#include <vector>
#include <list>
using namespace std;

const int NAMES = 99, DRINKS = 10, MUFFINS = 5, BRACELETS = 6, ICE_CREAMS = 8,
		  ROUNDS = 10, INITIAL = 3;
string drinks[DRINKS] = {"Black Coffee", "Latte", "Mocha", "Frappuccino",
						 "Macchiato", "Cocoa", "Cold Brew", "Americano",
						 "Espresso", "White Mocha"};
string muffins[MUFFINS] = {"Blueberry", "Chocolate", "Banana Nut",
		                  "Raspberry", "Plain"};
string bracelets[BRACELETS] = {"red", "orange", "yellow", "green",
		                       "blue", "purple"};
string ice_creams[ICE_CREAMS] = {"Vanilla", "Chocolate", "Strawberry",
								 "Cookies and Cream", "Coffee", "Birthday Cake",
								 "Peanut Butter Chocolate", "Raspberry"};

struct Customer {
	string name, order;
};

struct CustNode {
	string name, order;
	CustNode* next;
};

string getName();
string getOrder(string[], int);
Customer getCust(string[], int);
int prob();
void addDrinkCust(CustNode*&);
void remDrinkCust(CustNode*&);
void addMuffCust(deque<Customer>&);
void remMuffCust(deque<Customer>&);
void addBraclCust(vector<Customer>&);
void remBraclCust(vector<Customer>&);
void addIceCrCust(list<Customer>&);
void remIceCrCust(list<Customer>&);

int main() {

	srand(time(0));
	CustNode* drinkLine = nullptr;
	deque<Customer> muffLine;
	vector<Customer> braclLine;
	list<Customer> iceCrLine;

	//initialize the queue
	for (int i = 0; i < INITIAL; i++) {
		addDrinkCust(drinkLine);
		addMuffCust(muffLine);
		addBraclCust(braclLine);
		addIceCrCust(iceCrLine);
	}

	for (int i = 0; i < ROUNDS; i++) {
		cout << "Round " << i + 1 << ":\n";
		if (prob() <= 50) {
			addDrinkCust(drinkLine);
		}
		if (drinkLine != nullptr) {
			remDrinkCust(drinkLine);
		}
		if (prob() <= 50) {
			addMuffCust(muffLine);
		}
		if (!muffLine.empty()) {
			remMuffCust(muffLine);
		}
		if (prob() <= 50) {
			addBraclCust(braclLine);
		}
		if (!braclLine.empty()) {
			remBraclCust(braclLine);
		}
		if (prob() <= 50) {
			addIceCrCust(iceCrLine);
		}
		if (!iceCrLine.empty()) {
			remIceCrCust(iceCrLine);
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

void addDrinkCust(CustNode* &head) {
	CustNode* temp = new CustNode;
	temp->name = getName();
	temp->order = getOrder(drinks, DRINKS);
	temp->next = nullptr;
	cout << "\t" << temp->name << " ordered " << temp->order << ".\n";
	if (head == nullptr) {
		head = temp;
	}
	else {
		CustNode* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = temp;
	}
}

void remDrinkCust(CustNode* &head) {
	CustNode* current = head;
	head = head->next;
	cout << "\t" << current->name << " was served "
		 << current->order << ".\n";
	delete current;
	current = nullptr;
}

void addMuffCust(deque<Customer> &line) {
	Customer temp = getCust(muffins, MUFFINS);
	cout << "\t" << temp.name << " ordered " << temp.order << " muffin.\n";
	line.push_back(temp);
}

void remMuffCust(deque<Customer> &line) {
	cout << "\t" << line.front().name << " was served "
		 << line.front().order << " muffin.\n";
	line.pop_front();
}

void addBraclCust(vector<Customer>& line) {
	Customer temp = getCust(bracelets, BRACELETS);
	cout << "\t" << temp.name << " ordered "
		 << temp.order << " friendship bracelet.\n";
	line.push_back(temp);
}

void remBraclCust(vector<Customer>& line) {
	cout << "\t" << line.front().name << " was given "
		 << line.front().order << " friendship bracelet.\n";
	line.erase(line.begin());
}

void addIceCrCust(list<Customer>& line) {
	Customer temp = getCust(ice_creams, ICE_CREAMS);
	cout << "\t" << temp.name << " ordered "
		 << temp.order << " ice cream.\n";
	line.push_back(temp);
}

void remIceCrCust(list<Customer>& line) {
	cout << "\t" << line.front().name << " was served "
		 << line.front().order << " ice cream.\n";
	line.pop_front();
}

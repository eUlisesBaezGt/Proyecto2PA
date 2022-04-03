#pragma once
#include "Admin.h"
#include "Menu.h"


void LoginAdmin(vector<Admin>& list) {
	bool found = false;
	int ID;
	string Password;
	cout << "Enter your ID: ";
	cin >> ID;
	cin.ignore();
	cout << "Enter your password: ";
	getline(cin, Password);
	for (auto& i : list) {
		if (i.id == ID && i.password == Password && i.status) {
			found = true; break;
		}
	}
	if (found) { cout << "Welcome " << endl; Log_Admin(list); }
	else if (!found) { cout << "Invalid ID or password or user disabled" << endl; }
}




void LoginStud(vector<Student>& list) {
	bool found = false;
	int ID;
	string Password;
	cout << "Enter your ID: ";
	cin >> ID;
	cin.ignore();
	cout << "Enter your password: ";
	getline(cin, Password);
	for (auto& i : list) {
		if (i.id == ID && i.password == Password && i.status) {
			found = true; break;
		}
	}
	if (found) { cout << "Welcome " << endl; Log_Stud(list); }
	else if (!found) { cout << "Invalid ID or password or user disabled" << endl; }
}

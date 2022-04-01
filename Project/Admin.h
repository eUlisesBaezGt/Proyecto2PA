#pragma once

#include <iostream>
#include <cmath>
#include <vector>
#include <string>

#include "Menu.h"

using namespace std;

class Admin
{
public:
	int id{};
	string password{};

	string name;
	string middleName;
	string lastName;
	int age{};
	char gender{};
	bool status = true;
};


bool CheckAdminID(int id, const vector<Admin>& list) {
	for (auto& i : list) {
		if (i.id == id) return true; else return false;
	}
	return false;
}

int GetAdminId(int n, vector<Admin>& list) {
	n = rand() % 100;
	for (int i = 0; i < list.size(); ++i) {
		if (!CheckAdminID(n, list)) return n; else GetAdminId(n, list);
	}
	return n;
}


void EnableAdmin(vector<Admin> list) {
	bool found = false;
	cout << "ID of Admin to enable: ";
	int IS;
	cin >> IS;
	cin.ignore();
	for (auto& i : list) {
		if (IS == i.id) {
			found = true;
			i.status = true;
			cout << "Admin status successfully updated" << endl;
		}
	}
	if (!found) {
		cout << "Admin ID not found" << endl;
	}
}

void DisableAdmin(vector<Admin> list) {
	bool found = false;
	cout << "ID of Admin to disable: ";
	int IS;
	cin >> IS;
	cin.ignore();
	for (auto& i : list) {
		if (IS == i.id) {
			found = true;
			i.status = false;
			cout << "Admin status successfully updated" << endl;
		}
	}
	if (!found) {
		cout << "Admin ID not found" << endl;
	}
}

void PrintAdmins(const vector <Admin>& list) {
	for (auto& i : list) {
		cout << "-----------------------" << endl;
		cout << "ID: " << i.id << "\tName: " << i.name << "\tMiddle Name: " << i.middleName << "\tLast Name: " << i.lastName << "\tStatus" << i.status;
	}
}


void AddAdmin(vector<Admin>& list) {
	Admin temp;
	int n = 0;
	temp.id = GetAdminId(n, list);
	cout << " ------ Add Admin ------ " << endl;
	cout << "ID: " << temp.id << endl;
	cout << "Name: ";
	getline(cin, temp.name);
	cout << "Middle Name: ";
	getline(cin, temp.middleName);
	cout << "Last Name: ";
	getline(cin, temp.lastName);
	cout << "Age: ";
	cin >> temp.age;
	cin.ignore();
	cout << "Gender (M-F): ";
	cin >> temp.gender;
	cin.ignore();
	cout << "PASSWORD: ";
	getline(cin, temp.password);
	list.push_back(temp);

	system("clear");
}


void Log_Admin(vector<Admin>& students) {
	bool run = true;
	int option;

	while (run)
	{
		cout << "-------- LOGGED Admin MENU -------- ";
		/*cout << "1) Disable Student" << endl;
		cout << "2) Enable Student" << endl;
		cout << "3) Register Breakfast" << endl;
		cout << "4) Register Meal" << endl;
		cout << "5) Register Dinner" << endl;*/
		cout << "6) Exit" << endl;
		cout << "Select your option: ";

		cin >> option;
		cin.ignore();
		switch (option) {
		case 6:
			run = false;
			break;
		default:
			cout << "Invalid option";
			break;
		}
	}
}
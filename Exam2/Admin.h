#ifndef EXAMEN2_ADMIN_H
#define EXAMEN2_ADMIN_H

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

#include "enums_menus.h"

using namespace std;

static int GetAdminId(const vector<Admin>& list) {
	int n = rand() % 100;
	for (int i = 0; i < list.size(); ++i) {
		if (!CheckAdminID(n, list)) return n; else GetAdminId(list);
	}
}

static bool CheckAdminID(int id, vector<Admin> list) {
	for (auto& i : list) {
		if (i.id == id) return true;
		else return false;
	}
}

static void EnableAdmin(vector<Admin> list) {
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

static void DisableAdmin(vector<Admin> list) {
	bool found = false;
	cout << "ID of Admin to enable: ";
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

void PrintAdmins(vector <Admin> list) {
	for (size_t i = 0; i < list.size(); i++)
	{
		cout << "-----------------------" << endl;
		cout << "ID: " << list[i].id << "\tName: " << list[i].name << "\tMiddle Name: " << list[i].middleName << "\tLast Name: " << list[i].lastName
			<< "\tAge: " << list[i].age << "\tGender: " << list[i].gender << "\Status" << list[i].status;
	}
}

void LoginAdm(vector<Admin> list) {
	int ID;
	string Password;
	cout << "Enter your ID: ";
	cin >> ID;
	cin.ignore();
	cout << "Enter your password: ";
	getline(cin, Password);
	for (auto& i : list) {
		if (i.id == ID && i.password == Password && i.status == true) {
			cout << "Welcome " << i.name << endl;
			AdminMenu(list);
		}
	}
	cout << "Invalid ID or password" << endl;
	LoginAdm(list);
}

void AddAdm(vector<Admin>& list) {
	Admin temp;
	temp.id = GetAdminId(list);
	cout << " ------ Register Client ------ " << endl;
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
	cin >> temp.age;
	cin.ignore();
	list.push_back(temp);
	system("clear");
}


class Admin {
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

#endif //EXAMEN2_ADMIN_H

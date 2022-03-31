#pragma once

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

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
		if (!CheckAdminID(n, list)) return n; else GetAdminId(n,list);
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
	for (auto & i : list) {
		cout << "-----------------------" << endl;
		cout << "ID: " << i.id << "\tName: " << i.name << "\tMiddle Name: " << i.middleName << "\tLast Name: " << i.lastName << "\tStatus" << i.status;
	}
}

void LoginAdmin(const vector<Admin>& list) {
	int ID;
	string Password;
	cout << "Enter your ID: ";
	cin >> ID;
	cin.ignore();
	cout << "Enter your password: ";
	getline(cin, Password);
	for (auto& i : list) {
		if (i.id == ID && i.password == Password && i.status) {
			cout << "Welcome " << i.name << endl;
			// MENU
		}
	}
	cout << "Invalid ID or password" << endl;
}

void AddAdmin(vector<Admin>& list) {
	Admin temp;
    int n=0;
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
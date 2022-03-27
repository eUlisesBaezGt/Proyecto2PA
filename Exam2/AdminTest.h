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

class Admin {

private:
	string id{};
	string password{};

public:
	string name;
	string middleName;
	string lastName;
	int age{};
	char gender{};
	bool status = true;

	string MyAdminID() {
		return id;
	}

	string MyAdminPassword() {
		return password;
	}

	static string GetAdminId(const vector<Admin>& list) {
		int n = rand() % 100;
		string id = to_string(n);
		for (int i = 0; i < list.size(); ++i) {
			if (!CheckAdminID(id, list)) return id;
			else GetAdminId(list);
		}
	}

	static bool CheckAdminID(string id, vector<Admin> list) {
		for (auto& i : list) {
			if (i.MyAdminID() == id) return true;
			else return false;
		}
	}

	void AddAdm(vector<Admin>& list) {
		Admin temp;
		temp.id = temp.MyAdminID();
		cout << " ------ Register Client ------ " << endl;
		cout << "ID: " << id << endl;
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

	static void EnableAdmin(vector<Admin> list) {
		bool found = false;
		cout << "ID of Admin to enable: ";
		string IS;
		cin >> IS;
		cin.ignore();
		for (auto& i : list) {
			if (IS == i.MyAdminID()) {
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
		string IS;
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

	void LoginAdm(vector<Admin> list) {
		string ID;
		string Password;
		cout << "Enter your ID: ";
		cin >> ID;
		cin.ignore();
		cout << "Enter your password: ";
		getline(cin, Password);
		for (auto& i : list) {
			if (i.MyAdminPassword() == ID && i.MyAdminPassword() == Password && i.status == true) {
				cout << "Welcome " << i.name << endl;
				AdminMenu(list);
			}
		}
		cout << "Invalid ID or password" << endl;
		LoginAdm(list);
	}

};

void PrintAdmins(vector <Admin> list) {
	for (size_t i = 0; i < list.size(); i++)
	{
		cout << "-----------------------" << endl;
		cout << "ID: " << list[i].MyAdminID() << "\tName: " << list[i].name << "\tMiddle Name: " << list[i].middleName << "\tLast Name: " << list[i].lastName
			<< "\tAge: " << list[i].age << "\tGender: " << list[i].gender << "\Status" << list[i].status;
	}
}


#endif //EXAMEN2_ADMIN_H

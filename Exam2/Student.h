#ifndef EXAMEN2_STUDENT_H
#define EXAMEN2_STUDENT_H

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

#include "enums_menus.h"

using namespace std;

class Student {
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

static int GetStudentId(vector<Student>& list) {
	int n = rand() % 100;
	for (int i = 0; i < list.size(); ++i) {
		if (!CheckStudentID(n, list)) return n; else GetStudentId(list);
	}
}

static bool CheckStudentID(int id, vector<Student> list) {
	for (auto& i : list) {
		if (i.id == id) return true; else return false;
	}
}

static void EnableStudent(vector<Student> list) {
	bool found = false;
	cout << "ID of Student to enable: ";
	int IS;
	cin >> IS;
	cin.ignore();
	for (auto& i : list) {
		if (IS == i.id) {
			found = true;
			i.status = true;
			cout << "Student status successfully updated" << endl;
		}
	}
	if (!found) {
		cout << "Student ID not found" << endl;
	}
}

static void DisableStudent(vector<Student> list) {
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
		cout << "Student ID not found" << endl;
	}
}

static void PrintStudents(vector <Student> list) {
	for (size_t i = 0; i < list.size(); i++) {
		cout << "-----------------------" << endl;
		cout << "ID: " << list[i].id << "\tName: " << list[i].name << "\tMiddle Name: " << list[i].middleName << "\tLast Name: " << list[i].lastName << "\Status" << list[i].status;
	}
}

void LoginStud(vector<Student> list) {
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
	LoginStud(list);
}

void AddStud(vector<Student>& list) {
	Student temp;
	temp.id = GetStudentId(list);
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
	cout << "PASSWORD: ";
	getline(cin, temp.password);
	list.push_back(temp);
	system("clear");
}

#endif //EXAMEN2_STUDENT_H

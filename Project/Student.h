#pragma once

#include <iostream>
#include <cmath>
#include <vector>
#include <string>

#include "Enums.h"
#include "Menu.h"

class Student;
using namespace std;

struct Breakfast
{
	int TotalA;
	int TotalB;

	vector<Student> listA;
	vector<Student> listB;
};

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

bool CheckStudentID(int id, const vector<Student> list) {
	bool b = false;
	for (auto& i : list) {
		if (i.id == id) return true; break;
	}
	return b;
}

int GetStudentId(int n, const vector<Student> list) {
	n = rand() % 100;
	for (int i = 0; i < list.size(); ++i) {
		if (!CheckStudentID(n, list)) return n; break;
	}
}

void AddStudent(vector<Student>& list) {
	Student temp;
	int n = 0;
	temp.id = GetStudentId(n, list);
	cout << " ------ Add Student ------ " << endl;
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

void PrintStudents(const vector<Student> list) {
	for (auto& i : list) {
		cout << "-----------------------" << endl;
		cout << "ID: " << i.id << "\tName: " << i.name << "\tMiddle Name: " << i.middleName
			<< "\tLast Name: " << i.lastName << "\nStatus" << i.status;
	}
}

void EnableStudent(vector<Student>& list) {
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
void DisableStudent(vector<Student>& list) {
	bool found = false;
	cout << "ID of Student to disable: ";
	int IS;
	cin >> IS;
	cin.ignore();
	for (auto& i : list) {
		if (IS == i.id) {
			found = true;
			i.status = false;
			cout << "Student status successfully updated" << endl;
		}
	}
	if (!found) {
		cout << "Student ID not found" << endl;
	}
}


void Log_Stud(vector<Student>& students) {
	bool run = true;
	int option;

	while (run)
	{
		cout << "-------- LOGGED STUDENT MENU -------- ";
		cout << "1) Disable Student" << endl;
		cout << "2) Enable Student" << endl;
		cout << "3) Register Breakfast" << endl;
		cout << "4) Register Meal" << endl;
		cout << "5) Register Dinner" << endl;
		cout << "6) Exit" << endl;
		cout << "Select your option: ";

		cin >> option;
		cin.ignore();
		switch (option) {
		case DisStudent:
			cout << "Disable Student" << endl;
			DisableStudent(students);
			break;
		case EnaStudent:
			cout << "Enable Student" << endl;
			EnableStudent(students);
			break;
		case RegBreakfast:
			cout << "Register Breakfast" << endl;
			break;
		case RegMeal:
			cout << "Register Meal" << endl;
			break;
		case RegDinner:
			cout << "Register Dinner" << endl;
			break;
		case ExitStudentLog:
			cout << "Return to Main Menu" << endl;
			break;
		default:
			cout << "Invalid option";
			break;
		}
	}
}
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

	string MyStudentID() {
		return id;
	}

	string MyStudentPassword() {
		return password;
	}

	void RegisterBreakfast(vector<Student>& list) {
		return;
	}
	void RegisterMeal(vector<Student>& list) {
		return;
	}
	void RegisterDinner(vector<Student>& list) {
		return;
	}

	static string GetStudentId(vector<Student>& list) {
		int n = rand() % 100;
		string id = to_string(n);
		for (int i = 0; i < list.size(); ++i) {
			if (!CheckStudentID(id, list)) return id;
			else GetStudentId(list);
		}
	}

	static bool CheckStudentID(string id, vector<Student> list) {
		for (auto& i : list) {
			if (i.MyStudentID() == id) return true;
			else return false;
		}
	}

	void AddStud(vector<Student>& list) {
		Student temp;
		temp.id = MyStudentID();
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
		cout << "PASSWORD: ";
		getline(cin, temp.password);
		list.push_back(temp);
		system("clear");
	}

	static void EnableStudent(vector<Student> list) {
		bool found = false;
		cout << "ID of Student to enable: ";
		string IS;
		cin >> IS;
		cin.ignore();
		for (auto& i : list) {
			if (IS == i.MyStudentID()) {
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

	void LoginStud(vector<Student> list) {
		string ID;
		string Password;
		cout << "Enter your ID: ";
		cin >> ID;
		cin.ignore();
		cout << "Enter your password: ";
		getline(cin, Password);
		for (auto& i : list) {
			if (i.MyStudentID() == ID && i.MyStudentPassword() == Password && i.status == true) {
				cout << "Welcome " << i.name << endl;
			}
		}
		cout << "Invalid ID or password" << endl;
		LogStudent(list);
	}

};

void PrintStudents(vector <Student> list) {
	for (size_t i = 0; i < list.size(); i++)
	{
		cout << "-----------------------" << endl;
		cout << "ID: " << list[i].MyStudentID() << "\tName: " << list[i].name << "\tMiddle Name: " << list[i].middleName << "\tLast Name: " << list[i].lastName << "\tAge: " << list[i].age << "\tGender: " << list[i].gender << "\Status" << list[i].status;
	}
}

#endif //EXAMEN2_STUDENT_H

// almacenar

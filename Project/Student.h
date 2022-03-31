#pragma once

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

#include "Enums.h"
#include "Menu.h"

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

bool CheckStudentID(int id, const vector<Student> list) {
	bool b = false;
	for (auto& i : list) {
		if (i.id == id) return true;break;
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
	cin >> temp.age;
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



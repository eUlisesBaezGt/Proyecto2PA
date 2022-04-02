#pragma once

#include <iostream>
#include <cmath>
#include <vector>
#include <string>

class Student;
using namespace std;


struct Breakfast
{
	int Total;
	int TotalA;
	int TotalB;

	vector<Student> listA;
	vector<Student> listB;
};

struct Meal
{
	int Total;
	int TotalA;
	int TotalB;

	vector<Student> listA;
	vector<Student> listB;
};

struct Dinner
{
	int Total;
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


inline bool CheckStudentID(int id, const vector<Student> list) {
	for (auto& i : list) {
		if (i.id == id) return true; break;
	}
	return false;
}

inline int GetStudentId(int n, const vector<Student> list) {
	n = rand() % 100;
	for (int i = 0; i < list.size(); ++i) {
		if (!CheckStudentID(n, list)) return n; break;
	}
	return 0;
}

inline void PrintStudents(const vector<Student> list) {
	for (auto& i : list) {
		cout << "-----------------------" << endl;
		cout << "ID: " << i.id << "\tName: " << i.name << "\tMiddle Name: "
			<< i.middleName << "\tLast Name: " << i.lastName << "\nStatus"
			<< i.status;
	}
}

inline void AddStudent(vector<Student>& list) {
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


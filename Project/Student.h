#pragma once

#include <iostream>
#include <cmath>
#include <vector>
#include <string>

#include "Enums.h"

using namespace std;

class student;


struct breakfast
{
	int Total;
	int TotalA;
	int TotalB;

	vector<student> listA;
	vector<student> listB;
};

struct meal
{
	int Total;
	int TotalA;
	int TotalB;

	vector<student> listA;
	vector<student> listB;
};

struct dinner
{
	int Total;
	int TotalA;
	int TotalB;

	vector<student> listA;
	vector<student> listB;
};

class student
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


inline bool check_student_id(const int id, const vector<student>& list)
{
	bool used = false;
	for (auto& i : list)
	{
		if (i.id == id) used = true;
		break;
	}
	return used;
}

inline int get_student_id(const vector<student>& list)
{
	const int n = rand() % 100;
	const bool used = check_student_id(n, list);
	if (!used) return n;
	return get_student_id(list);
}

inline void print_students(const vector<student>& list)
{
	for (auto& i : list)
	{
		string status;
		if (i.status == true) status = "Active";
		else status = "Inactive";
		cout << "-----------------------" << endl;
		cout
			<< "ID: " << i.id << "\tName: " << i.name << "\tMiddle Name: " << i.middleName
			<< "\tLast Name: " << i.lastName << "\tStatus: " << status << endl;
	}
}

inline void add_student(vector<student>& list)
{
	student temp;
	temp.id = get_student_id(list);
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

inline void enable_student(vector<student>& list)
{
	bool found = false;
	cout << "ID of Student to enable: ";
	int is;
	cin >> is;
	cin.ignore();
	for (auto& i : list)
	{
		if (is == i.id)
		{
			found = true;
			i.status = true;
			cout << "Student status successfully updated" << endl;
		}
	}
	if (!found) cout << "Student ID not found" << endl;
}

inline void disable_student(vector<student>& list)
{
	bool found = false;
	cout << "ID of Student to disable: ";
	int is;
	cin >> is;
	cin.ignore();
	for (auto& i : list)
	{
		if (is == i.id)
		{
			found = true;
			i.status = false;
			cout << "Student status successfully updated" << endl;
		}
	}
	if (!found)
	{
		cout << "Student ID not found" << endl;
	}
}

inline void logged_student(vector<student>& list)
{
	bool run = true;
	int option;

	while (run)
	{
		cout << "-------- LOGGED student MENU -------- " << endl;
		cout << "1) Disable student" << endl;
		cout << "2) Enable student" << endl;
		cout << "3) Register Breakfast" << endl;
		cout << "4) Register Meal" << endl;
		cout << "5) Register Dinner" << endl;
		cout << "6) Exit" << endl;

		cout << "Select your option: ";
		cin >> option;
		cin.ignore();

		switch (option)
		{
		case DisStudent:
		{
			cout << "Disabling student" << endl;
			disable_student(list);
			break;
		}

		case EnaStudent:
		{
			cout << "Enabling student" << endl;
			enable_student(list);
			break;
		}

		case RegBreakfast:
		{
			cout << "Register Breakfast" << endl;
			break;
		}

		case RegMeal:
		{
			cout << "Register Meal" << endl;
			break;
		}

		case RegDinner:
		{
			cout << "Register Dinner" << endl;
			break;
		}

		case ExitstudentLog:
		{
			cout << "Return to Main Menu" << endl;
			run = false;
			break;
		}

		default:
		{
			cout << "Invalid Option" << endl;
			break;
		}
		}
	}
}

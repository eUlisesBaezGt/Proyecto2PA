#pragma once

#include <iostream>
#include <cmath>
#include <vector>
#include <string>

#include "App.h"
#include "Enums.h"

using namespace std;

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

inline void print_students(vector<student>& list)
{
	for (auto& i : list)
	{
		cout << "-----------------------" << endl;
		cout
			<< "ID: " << i.id << "\tName: " << i.name << "\tLast Name: " << i.lastName << endl;
	}
}

inline void print_students(const app App)
{
	for (auto& i : App.students)
	{
		string status;
		if (i.status == "true") status = "Active";
		else status = "Inactive";
		cout << "-----------------------" << endl;
		cout
			<< "ID: " << i.id << "\tName: " << i.name << "\tMiddle Name: " << i.middleName
			<< "\tLast Name: " << i.lastName << "\tStatus: " << status << "\tBreakfast: " << i.breakfast
			<< "\tMeal: " << i._meal << "\tDinner: " << i.dinner << endl;
	}
}

inline void add_student(app& App)
{
	student temp;
	temp.id = get_student_id(App.students);
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
	App.students.push_back(temp);

	system("clear");
}

inline void enable_student(app& App)
{
	bool found = false;
	cout << "ID of Student to enable: ";
	int is;
	cin >> is;
	cin.ignore();
	for (auto& i : App.students)
	{
		if (is == i.id)
		{
			found = true;
			i.status = "true";
			cout << "Student status successfully updated" << endl;
		}
	}
	if (!found) cout << "Student ID not found" << endl;
}

inline void disable_student(app& App)
{
	bool found = false;
	cout << "ID of Student to disable: ";
	int is;
	cin >> is;
	cin.ignore();
	for (auto& i : App.students)
	{
		if (is == i.id)
		{
			found = true;
			i.status = "false";
			cout << "Student status successfully updated" << endl;
		}
	}
	if (!found)
	{
		cout << "Student ID not found" << endl;
	}
}

inline void register_breakfast(app& App)
{
	bool found = false;
	string block;

	if (App.breakfast.total >= App.total_students)
	{
		cout << "No more students can register for breakfast" << endl;
		return;
	}
	cout << "ID of Student: ";
	int is;
	cin >> is;
	cin.ignore();
	for (auto& student : App.students)
	{
		if (is == student.id)
		{
			App.breakfast.total++;
			found = true;
			cout << "Select block: ";
			cin >> block;
			if (block == "A" || block == "B")
			{
				student.breakfast = block;
				if (student.breakfast == "A")
				{
					App.breakfast.total_a++;
					App.breakfast.list_a.push_back(student);
					break;
				}
				App.breakfast.total_b++;
				App.breakfast.list_b.push_back(student);
				break;
			}
		}
		cout << "Invalid block" << endl;
		break;
	}
	if (!found) cout << "Student ID not found" << endl;
}

inline void register_meal(app& App)
{
	bool found = false;
	string block;

	if (App._meal.total >= App.total_students)
	{
		cout << "No more students can register for meal" << endl;
		return;
	}
	cout << "ID of Student: ";
	int is;
	cin >> is;
	cin.ignore();
	for (auto& student : App.students)
	{
		if (is == student.id)
		{
			App._meal.total++;
			found = true;
			cout << "Select block: ";
			cin >> block;
			if (block == "A" || block == "B")
			{
				student._meal = block;
				if (student._meal == "A")
				{
					App._meal.total_a++;
					App._meal.list_a.push_back(student);
					break;
				}
				App._meal.total_b++;
				App._meal.list_b.push_back(student);
				break;
			}
		}
		cout << "Invalid block" << endl;
		break;
	}
	if (!found) cout << "Student ID not found" << endl;
}

inline void register_dinner(app& App)
{
	bool found = false;
	string block;

	if (App.dinner.total >= App.total_students)
	{
		cout << "No more students can register for dinner" << endl;
		return;
	}
	cout << "ID of Student: ";
	int is;
	cin >> is;
	cin.ignore();
	for (auto& student : App.students)
	{
		if (is == student.id)
		{
			App.dinner.total++;
			found = true;
			cout << "Select block: ";
			cin >> block;
			if (block == "A" || block == "B")
			{
				student.dinner = block;
				if (student.dinner == "A")
				{
					App.dinner.total_a++;
					App.dinner.list_a.push_back(student);
					break;
				}
				App.dinner.total_b++;
				App.dinner.list_b.push_back(student);
				break;
			}
		}
		cout << "Invalid block" << endl;
		break;
	}
	if (!found) cout << "Student ID not found" << endl;
}

inline void logged_student(app& App)
{
	bool run = true;
	int option;

	while (run)
	{
		cout << "-------- LOGGED STUDENT MENU -------- " << endl;
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
			disable_student(App);
			break;
		}

		case EnaStudent:
		{
			cout << "Enabling student" << endl;
			enable_student(App);
			break;
		}

		case RegBreakfast:
		{
			cout << "Register Breakfast" << endl;
			register_breakfast(App);
			break;
		}

		case RegMeal:
		{
			cout << "Register Meal" << endl;
			register_meal(App);
			break;
		}

		case RegDinner:
		{
			cout << "Register Dinner" << endl;
			register_dinner(App);
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

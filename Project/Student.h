#pragma once

#include <iostream>
#include <cmath>
#include <vector>
#include <string>

#include "App.h"
#include "Enums.h"
#include "Files.h"

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
	const int n = rand() % (1000 + 1 - 0) + 0;
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
	App.students.push_back(temp);
	add_student_2_file(App);

	system("cls");
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
	App.breakfast.Maxtotal = App.total_students;
	int cap = 0;

	bool found = false;
	string block;

	cout << "ID of Student: ";
	int is;
	cin >> is;
	cin.ignore();
	for (auto& student : App.students)
	{
		if (is == student.id)
		{
			found = true;
			cout << "Select block: ";
			cin >> block;
			if (block == "A" || block == "B")
			{
				if (block == "A")
				{
					for (auto& i : App.students)
					{
						if (i.breakfast == "A")
						{
							cap++;
						}
					}
					if (cap == App.breakfast.total_a) cout << "Block A is full" << endl;
					else
					{
						student.breakfast = block;
						App.breakfast.list_a.push_back(student);
						cout << "Registered correctly" << endl;
						break;
					}
				}
				else
				{
					cap = 0;
					for (auto& i : App.students)
					{
						if (i.breakfast == "B")
						{
							cap++;
						}
					}
					if (cap == App.breakfast.total_b) cout << "Block B is full" << endl;
					else
					{
						student.breakfast = block;
						App.breakfast.list_b.push_back(student);
						cout << "Registered correctly" << endl;
						break;
					}
				}
			}
		}
	}
	if (!found) cout << "Student ID not found" << endl;
}


inline void register_meal(app& App)
{
	App._meal.Maxtotal = App.total_students;
	int cap = 0;

	bool found = false;
	string block;

	cout << "ID of Student: ";
	int is;
	cin >> is;
	cin.ignore();
	for (auto& student : App.students)
	{
		if (is == student.id)
		{
			found = true;
			cout << "Select block: ";
			cin >> block;
			if (block == "A" || block == "B")
			{
				if (block == "A")
				{
					for (auto& i : App.students)
					{
						if (i._meal == "A")
						{
							cap++;
						}
					}
					if (cap == App._meal.total_a) cout << "Block A is full" << endl;
					else
					{
						student._meal = block;
						App._meal.list_a.push_back(student);
						cout << "Registered correctly" << endl;
						break;
					}
				}
				else
				{
					cap = 0;
					for (auto& i : App.students)
					{
						if (i._meal == "B")
						{
							cap++;
						}
					}
					if (cap == App._meal.total_b) cout << "Block B is full" << endl;
					else
					{
						student._meal = block;
						App._meal.list_b.push_back(student);
						cout << "Registered correctly" << endl;
						break;
					}
				}
			}
		}
	}
	if (!found) cout << "Student ID not found" << endl;
}

inline void register_dinner(app& App)
{
	App.dinner.Maxtotal = App.total_students;
	int cap = 0;

	bool found = false;
	string block;

	cout << "ID of Student: ";
	int is;
	cin >> is;
	cin.ignore();
	for (auto& student : App.students)
	{
		if (is == student.id)
		{
			found = true;
			cout << "Select block: ";
			cin >> block;
			if (block == "A" || block == "B")
			{
				if (block == "A")
				{
					for (auto& i : App.students)
					{
						if (i.dinner == "A")
						{
							cap++;
						}
					}
					if (cap == App.dinner.total_a) cout << "Block A is full" << endl;
					else
					{
						student.dinner = block;
						App.dinner.list_a.push_back(student);
						cout << "Registered correctly" << endl;
						break;
					}
				}
				else
				{
					cap = 0;
					for (auto& i : App.students)
					{
						if (i.dinner == "B")
						{
							cap++;
						}
					}
					if (cap == App.dinner.total_b) cout << "Block B is full" << endl;
					else
					{
						student.dinner = block;
						App.dinner.list_b.push_back(student);
						cout << "Registered correctly" << endl;
						break;
					}
				}
			}
		}
	}
	if (!found) cout << "Student ID not found" << endl;
}

inline void delete_register(app& App)
{
	bool found = false;

	cout << "ID of Student: ";
	int is;
	cin >> is;
	cin.ignore();
	for (auto& student : App.students)
	{
		if (is == student.id)
		{
			found = true;
			cout << "-------- DELETE REGISTER -------- " << endl;
			if (student.breakfast == "A")
			{
				App.breakfast.total_a--;
				student.breakfast = "";
			}

			if (student.breakfast == "B")
			{
				App.breakfast.total_b--;
				student.breakfast = "";
			}
			if (student._meal == "A")
			{
				App._meal.total_a--;
				student._meal = "";
			}
			if (student._meal == "B")
			{
				App._meal.total_b--;
				student._meal = "";
			}
			if (student.dinner == "A")
			{
				App.dinner.total_a--;
				student.dinner = "";
			}
			if (student.dinner == "B")
			{
				App.dinner.total_b--;
				student.dinner = "";
			}
		}
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
		cout << "6) Delete Register" << endl;
		cout << "7) Exit" << endl;

		cout << "Select your option: ";
		cin >> option;
		cin.ignore();

		switch (option)
		{
		case DisStudent:
			{
				cout << "Disabling student" << endl;
				disable_student(App);
				add_student_2_file(App);
				break;
			}

		case EnaStudent:
			{
				cout << "Enabling student" << endl;
				enable_student(App);
				add_student_2_file(App);
				break;
			}

		case RegBreakfast:
			{
				cout << "Register Breakfast" << endl;
				register_breakfast(App);
				add_student_2_file(App);
				break;
			}

		case RegMeal:
			{
				cout << "Register Meal" << endl;
				register_meal(App);
				add_student_2_file(App);
				break;
			}

		case RegDinner:
			{
				cout << "Register Dinner" << endl;
				register_dinner(App);
				add_student_2_file(App);
				break;
			}
		case ChangeReg:
			{
				cout << "Change register" << endl;
				delete_register(App);
				add_student_2_file(App);
				break;
			}

		case ExitStudentLog:
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

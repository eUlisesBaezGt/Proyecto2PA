#pragma once

#include <iostream>

#include "Student.h"
#include "Enums.h"
#include "Admin.h"
#include "Logins.h"

inline void admin_menu(app& App)
{
	vector<admin> list = App.admins;
	int option;
	bool run = true;

	while (run)
	{
		cout << "-------- ADMIN MENU --------" << endl;
		cout << "1) Login" << endl;
		cout << "2) Add Admin" << endl;
		cout << "3) Print All" << endl;
		cout << "4) Exit" << endl;

		cout << "Select your option: ";
		cin >> option;
		cin.ignore();

		switch (option)
		{
		case LogAdm:
			login_admin(App);
			break;
		case AddAdm:
			add_admin(list);
			break;
		case PrAAdm:
			print_admins(list);
			break;
		case ExitAdmin:
			cout << "Return to Main Menu" << endl;
			run = false;
			break;
		default:
			cout << "Invalid option";
			break;
		}
	}
}


inline void student_menu(app& App)
{
	vector<student> list = App.students;
	int option;
	bool run = true;

	while (run)
	{
		cout << "-------- STUDENT MENU -------- " << endl;
		cout << "1) Login" << endl;
		cout << "2) Add Student" << endl;
		cout << "3) Print All" << endl;
		cout << "4) Exit" << endl;

		cout << "Select your option: ";
		cin >> option;
		cin.ignore();

		switch (option)
		{
		case LogStud:
			login_stud(App);
			break;
		case AddStud:
			add_student(list);
			break;
		case PrAStud:
			print_students(list);
			break;
		case Exitstudent:
			run = false;
			cout << "Return to Main Menu" << endl;
			break;
		default:
			cout << "Invalid option";
			break;
		}
	}
}

inline void main_menu()
{
	app App;
	char choice;
	bool run = true;

	while (run)
	{
		cout << endl;
		cout << "A) Use as Admin" << endl;
		cout << "S) Use as Student" << endl;
		cout << "Q) Quit" << endl;
		cout << "Select your option: ";
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case 'A':
			cout << "Using as admin " << endl;
			admin_menu(App);
			break;
		case 'S':
			cout << "Using as student" << endl;
			student_menu(App);
			break;
		case 'Q':
			cout << "Goodbye!" << endl;
			run = false;
			break;
		default:
			cout << "Invalid choice" << endl;
			break;
		}
	}
}

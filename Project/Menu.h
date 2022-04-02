#pragma once

#include <iostream>
#include <vector>

#include "student.h"
#include "Enums.h"
#include "Admin.h"
#include "Logins.h"

inline void admin_menu(vector<Admin>& list)
{
	int option;
	bool run = true;

	while (run)
	{
		cout << "-------- ADMIN MENU -------- " << endl;
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
			//login_admin(list);
			break;
		case AddAdm:
			AddAdmin(list);
			break;
		case PrAAdm:
			PrintAdmins(list);
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

inline void student_menu(vector<student> list)
{
	int option;
	bool run = true;

	while (run)
	{
		cout << "-------- student MENU -------- " << endl;
		cout << "1) Login" << endl;
		cout << "2) Add student" << endl;
		cout << "3) Print All" << endl;
		cout << "4) Exit" << endl;

		cout << "Select your option: ";
		cin >> option;
		cin.ignore();

		switch (option)
		{
		case LogStud:
			login_stud(list);
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
	vector<student> students;
	vector<Admin> admins;
	char choice;
	bool run = true;

	while (run)
	{
		cout << endl;
		cout << "A) Use as Admin" << endl;
		cout << "S) Use as student" << endl;
		cout << "Q) Quit" << endl;
		cout << "Select your option: ";
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case 'A':
			cout << "admin " << endl;
			// admin_menu(admins);
			break;
		case 'S':
			cout << "student" << endl;
			student_menu(students);
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

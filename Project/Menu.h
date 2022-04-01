#pragma once

#include <iostream>
#include <vector>

#include "Admin.h"
#include "Student.h"
#include "Enums.h"

using namespace std;


void AdminMenu(vector<Admin>& list) {
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

		switch (option) {
		case LogAdm:
			LoginAdmin(list);
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


void StudentMenu(vector<Student>list)
{
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
			LoginStud(list);
			break;
		case AddStud:
			AddStudent(list);
			break;
		case PrAStud:
			PrintStudents(list);
			break;
		case ExitStudent:
			cout << "Return to Main Menu" << endl;
			run = false;
			break;
		default:
			cout << "Invalid option";
			StudentMenu(list);
			break;
		}
	}
}


void MainMenu() {
	vector<Student> students;
	// vector<Admin> admins;
	char choice;
	bool run = true;

	while (run) {
		cout << endl;
		cout << "A) Use as Admin" << endl;
		cout << "S) Use as Student" << endl;
		cout << "Q) Quit" << endl;
		cout << "Select your option: ";
		cin >> choice;
		cin.ignore();
		switch (choice) {
		case 'A':
			cout << "admin " << endl;
			// AdminMenu(admins);
			break;
		case 'S':
			cout << "student" << endl;
			StudentMenu(students);
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

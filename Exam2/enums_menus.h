#ifndef EXAM2_ENUMS_MENUS_H
#define EXAM2_ENUMS_MENUS_H

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

#include "Admin.h"
#include "Student.h"


enum StudentMenu {
	LoginStudent = 1,
	AddStudent,
	PrintAllStudent,
	ExitStudent
};

enum LoggedStudentMenu {
	DisableStudent = 1,
	EnableStudent,
	RegisterBreakfast,
	RegisterMeal,
	RegisterDinner,
	ExitStudentLog
};

enum AdminMenu {
	LoginAdmin = 1,
	AddAdmin,
	PrintAllAdmin,
	ExitAdmin
};

enum LoggedAdminMenu {
	DisableAdmin = 1,
	EnableAdmin,
	EditStudentsCapacity,
	Capacity4Eachmeal,
	ModifyPlatesperBlock,
	SeeStudentsInBlock,
	ExitAdminLog
};

void LogStudent(vector <Student> students) {
	cout << "-------- LOGGED STUDENT MENU -------- ";
	cout << "1) Disable Student" << endl;
	cout << "2) Enable Student" << endl;
	cout << "3) Register Breakfast" << endl;
	cout << "4) Register Meal" << endl;
	cout << "5) Register Dinner" << endl;
	cout << "6) Exit" << endl;
	cout << "Select your option: ";
	int option;
	cin >> option;
	cin.ignore();
	switch (option)
	{
	case DisableStudent:
		break;
	case EnableStudent:
		break;
	case RegisterBreakfast:
		break;
	case RegisterMeal:
		break;
	case RegisterDinner:
		break;
	case ExitStudentLog:
		cout << "GOOBYE" << endl;
		break;
	default:
		cout << "Invalid option";
		StudentMenu(students);
		break;
	}
}

//void StudentMenu(vector <Student> students) {
//	Student student;
//	cout << "-------- STUDENT MENU -------- ";
//	cout << "1) Login" << endl;
//	cout << "2) Add Student" << endl;
//	cout << "3) Print All" << endl;
//	cout << "4) Exit" << endl;
//	cout << "Select your option: ";
//	int option;
//	cin >> option;
//	cin.ignore();
//	switch (option)
//	{
//	case LoginStudent:
//		LogStudent(students);
//		break;
//	case AddStudent:
//		student.AddStud(students);
//		break;
//	case PrintAllAdmin:
//		PrintStudents(students);
//		break;
//	case ExitStudent:
//		cout << "GOOBYE" << endl;
//		break;
//	default:
//		cout << "Invalid option";
//		StudentMenu(students);
//		break;
//	}
//}
//
//void AdminMenu(vector <Admin> admins) {
//	Admin admin;
//	cout << "-------- ADMIN MENU -------- ";
//	cout << "1) Login" << endl;
//	cout << "2) Add Admin" << endl;
//	cout << "3) Print All" << endl;
//	cout << "4) Exit" << endl;
//	cout << "Select your option: ";
//	int option;
//	cin >> option;
//	cin.ignore();
//	switch (option)
//	{
//	case LoginAdmin:
//		admin.LoginAdm(admins);
//		break;
//	case AddAdmin:
//		admin.AddAdm(admins);
//		break;
//	case PrintAllStudent:
//		PrintAdmins(admins);
//		break;
//	case ExitAdmin:
//		cout << "GOOBYE" << endl;
//		break;
//	default:
//		cout << "Invalid option";
//		AdminMenu(admins);
//		break;
//	}
//}

void MainMenu() {
	vector <Student> students;
	vector <Admin> admins;
	char choice;
	cout << "A) Use as Admin" << endl;
	cout << "S) Use as Student" << endl;
	cout << "Q) Quit" << endl;
	cout << "Select your option: ";
	cin >> choice;
	cin.ignore();
	switch (choice) {
	case 'A':
		StudentMenu(students);
		break;
	case 'S':
		AdminMenu(admins);
		break;
	case 'Q':
		cout << "Goodbye!" << endl;
		break;
	default:
		cout << "Invalid choice" << endl;
		MainMenu();
		break;
	}
}

#endif //EXAM2_ENUMS_MENUS_H

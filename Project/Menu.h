#pragma once

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

#include "Admin.h"
#include "Student.h"
#include "Enums.h"

using namespace std;

//
//void LogStudent(vector <Student> students) {
//	cout << "-------- LOGGED STUDENT MENU -------- ";
//	cout << "1) Disable Student" << endl;
//	cout << "2) Enable Student" << endl;
//	cout << "3) Register Breakfast" << endl;
//	cout << "4) Register Meal" << endl;
//	cout << "5) Register Dinner" << endl;
//	cout << "6) Exit" << endl;
//	cout << "Select your option: ";
//	int option;
//	cin >> option;
//	cin.ignore();
//	switch (option)
//	{
//	case DisStudent:
//		cout << "Disable Student" << endl;
//		break;
//	case EnaStudent:
//		cout << "Enable Student" << endl;
//		break;
//	case RegBreakfast:
//		cout << "Register Breakfast" << endl;
//		break;
//	case RegMeal:
//		cout << "Register Meal" << endl;
//		break;
//	case RegDinner:
//		cout << "Register Dinner" << endl;
//		break;
//	case ExitStudentLog:
//		cout << "GOOBYE" << endl;
//		break;
//	default:
//		cout << "Invalid option";
//		StudentMenu(students);
//		break;
//	}
//}
//
//void StudentMenu(vector <Student> list) {
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
//		LogStudent(list);
//		break;
//	case AddStudent:
//		AddStud(list);
//		break;
//	case PrintAllAdmin:
//		PrintStudents(list);
//		break;
//	case ExitStudent:
//		cout << "GOOBYE" << endl;
//		break;
//	default:
//		cout << "Invalid option";
//		StudentMenu(list);
//		break;
//	}
//}
//
//void AdminMenu(vector <Admin> list) {
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
//		LoginAdm(list);
//		break;
//	case AddAdmin:
//		AddAdm(list);
//		break;
//	case PrintAllStudent:
//		PrintAdmins(list);
//		break;
//	case ExitAdmin:
//		cout << "GOOBYE" << endl;
//		break;
//	default:
//		cout << "Invalid option";
//		AdminMenu(list);
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
		/*StudentMenu(students);*/
        cout << "Admin Menu" << endl;
		break;
	case 'S':
		/*AdminMenu(admins);*/
        cout << "Student Menu" << endl;
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

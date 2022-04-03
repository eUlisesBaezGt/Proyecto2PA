#pragma once

#include "App.h"
#include "Admin.h"
#include "Student.h"


inline void login_admin(app& App)
{
	bool found = false;
	int id;
	string password;
	cout << "Enter your ID: ";
	cin >> id;
	cin.ignore();
	cout << "Enter your password: ";
	getline(cin, password);
	for (auto& i : App.admins)
	{
		if (i.id == id && i.password == password && i.status)
		{
			found = true;
			cout << "Welcome " << endl;
			logged_admin(App);
			break;
		}
	}
	if (!found) { cout << "Invalid ID or password or user disabled" << endl; }
}


inline void login_stud(app &App)
{
	bool found = false;
	int ID;
	string Password;
	cout << "Enter your ID: ";
	cin >> ID;
	cin.ignore();
	cout << "Enter your password: ";
	getline(cin, Password);
	for (auto& i : App.students)
	{
		if (i.id == ID && i.password == Password && i.status)
		{
			found = true;
			cout << "Welcome " << endl;
			logged_student(App);
			break;
		}
	}
	if (!found) {cout << "Invalid ID or password or user disabled" << endl; }
}

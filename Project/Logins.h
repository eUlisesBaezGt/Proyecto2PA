#pragma once

#include "App.h"
#include "Admin.h"
#include "Student.h"


inline void login_admin(app App)
{
	vector<admin> list;
	bool found = false;
	int ID;
	string Password;
	cout << "Enter your ID: ";
	cin >> ID;
	cin.ignore();
	cout << "Enter your password: ";
	getline(cin, Password);
	for (auto& i : list)
	{
		if (i.id == ID && i.password == Password && i.status)
		{
			found = true;
			break;
		}
	}
	if (found)
	{
		cout << "Welcome " << endl;
		logged_admin(App);
	}
	else if (!found) { cout << "Invalid ID or password or user disabled" << endl; }
}


inline void login_stud(app App)
{
	vector<student> list;
	bool found = false;
	int ID;
	string Password;
	cout << "Enter your ID: ";
	cin >> ID;
	cin.ignore();
	cout << "Enter your password: ";
	getline(cin, Password);
	for (auto& i : list)
	{
		if (i.id == ID && i.password == Password && i.status)
		{
			found = true;
			break;
		}
	}
	if (found)
	{
		cout << "Welcome " << endl;
		logged_student(App);
	}
	else if (!found) { cout << "Invalid ID or password or user disabled" << endl; }
}

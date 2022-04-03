#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "App.h"

inline bool check_admin_id(const int id, const vector<admin> list)
{
	bool used = false;
	for (auto& i : list)
	{
		if (i.id == id) used = true;
		break;
	}
	return used;
}

inline int get_admin_id(const vector<admin> list)
{
	const int n = rand() % 100;
	const bool used = check_admin_id(n, list);
	if (!used) return n;
	return get_admin_id(list);
}

inline void print_admins(const app App)
{
	for (auto& i : App.admins)
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

inline void add_admin(app& App)
{
	admin temp;
	temp.id = get_admin_id(App.admins);
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
	App.admins.push_back(temp);

	system("clear");
}

inline void enable_admin(app& App)
{
	bool found = false;
	cout << "ID of Admin to enable: ";
	int is;
	cin >> is;
	cin.ignore();
	for (auto& i : App.admins)
	{
		if (is == i.id)
		{
			found = true;
			i.status = true;
			cout << "Admin status successfully updated" << endl;
		}
	}
	if (!found) cout << "Admin ID not found" << endl;
}

inline void disable_admin(app& App)
{
	bool found = false;
	cout << "ID of Admin to disable: ";
	int is;
	cin >> is;
	cin.ignore();
	for (auto& i : App.admins)
	{
		if (is == i.id)
		{
			found = true;
			i.status = false;
			cout << "Admin status successfully updated" << endl;
		}
	}
	if (!found)
	{
		cout << "Admin ID not found" << endl;
	}
}

inline void edit_total_capacity(app& App)
{
	cout << "-------- EDIT TOTAL CAPACITY --------" << endl;
	cout << "Enter new total capacity: ";
	int cap;
	cin >> App.total_students;
	cin.ignore();
	cout << "Total Capacity successfully updated" << endl;
}

inline void edit_specific_meal_capacity(app& App)
{
	int option;
	cout << "-------- EDIT SPECIFIC MEAL CAPACITY --------" << endl;

	cout << "1) Breakfast" << endl;
	cout << "2) Meal" << endl;
	cout << "3) Dinner" << endl;

	cout << "Select your option: ";
	cin >> option;
	cin.ignore();

	switch (option)
	{
	case 1:
	{
		cout << "Enter new breakfast capacity: ";
		cin >> App.breakfast.total;
		cin.ignore();
		cout << "Breakfast capacity successfully updated" << endl;
		break;
	}
	case 2:
	{
		cout << "Enter new meal capacity: ";
		cin >> App._meal.total;
		cin.ignore();
		cout << "Meal capacity successfully updated" << endl;
		break;
	}

	case 3:
	{
		cout << "Enter new dinner capacity: ";
		cin >> App.dinner.total;
		cin.ignore();
		cout << "Dinner capacity successfully updated" << endl;
		break;
	}

	default:
	{
		cout << "Invalid option" << endl;
		break;
	}
	}
}

inline void edit_specific_meal_block_capacity(app& App)
{
	int hour;
	char block;
	cout << "-------- EDIT SPECIFIC MEAL BLOCK CAPACITY --------" << endl;
	cout << "1) Breakfast" << endl;
	cout << "2) Meal" << endl;
	cout << "3) Dinner" << endl;

	cout << "Select your option: ";
	cin >> hour;
	cin.ignore();

	cout << "Block A" << endl;
	cout << "Block B" << endl;
	cout << "Select your option: ";

	cin >> block;
	cin.ignore();

	switch (hour)
	{
	case 1:
	{
		if (block == 'A')
		{
			cout << "Enter new block A capacity: ";
			cin >> App.breakfast.total_a;
			cin.ignore();
			App.breakfast.total_b = App.breakfast.total - App.breakfast.total_a;
			cout << "Breakfast block capacity successfully updated" << endl;
			break;
		}
		if (block == 'B')
		{
			cout << "Enter new block B capacity: ";
			cin >> App.breakfast.total_b;
			cin.ignore();
			App.breakfast.total_a = App.breakfast.total - App.breakfast.total_b;
			cout << "Breakfast block capacity successfully updated" << endl;
			break;
		}
		cout << "Invalid option" << endl;
		break;
	}
	case 2:
	{
		if (block == 'A')
		{
			cout << "Enter new block A capacity: ";
			cin >> App._meal.total_a;
			cin.ignore();
			App._meal.total_b = App._meal.total - App._meal.total_a;
			cout << "Meal block capacity successfully updated" << endl;
			break;
		}
		if (block == 'B')
		{
			cout << "Enter new block B capacity: ";
			cin >> App._meal.total_b;
			cin.ignore();
			App._meal.total_a = App._meal.total - App._meal.total_b;
			cout << "Meal block capacity successfully updated" << endl;
			break;
		}
		cout << "Invalid option" << endl;
		break;
	}
	case 3:
	{
		if (block == 'A')
		{
			cout << "Enter new block A capacity: ";
			cin >> App.dinner.total_a;
			cin.ignore();
			App.dinner.total_b = App.dinner.total - App.dinner.total_a;
			cout << "Dinner block capacity successfully updated" << endl;
			break;
		}
		if (block == 'B')
		{
			cout << "Enter new block B capacity: ";
			cin >> App.dinner.total_b;
			cin.ignore();
			App.dinner.total_a = App.dinner.total - App.dinner.total_b;
			cout << "Dinner block capacity successfully updated" << endl;
			break;
		}
		cout << "Invalid option" << endl;
		break;
	}
	default:
	{
		cout << "Invalid option" << endl;
		break;
	}
	}
}

inline void how_may_students_block(app& App)
{
	int hour;
	char block;
	int capacity = 0;
	cout << "-------- HOW MANY STUDENTS IN BLOCK--------" << endl;
	cout << "1) Breakfast" << endl;
	cout << "2) Meal" << endl;
	cout << "3) Dinner" << endl;

	cout << "Select your option: ";
	cin >> hour;
	cin.ignore();

	cout << "Block A" << endl;
	cout << "Block B" << endl;
	cout << "Select your option: ";

	cin >> block;
	cin.ignore();

	switch (hour)
	{
	case 1:
	{
		if (block == 'A')
		{
			capacity = App.breakfast.total_a;
			cout << "Breakfast capacity successfully updated" << endl;
		}
		else if (block == 'B')
		{
			capacity = App.breakfast.total_b;
			cout << "Breakfast capacity successfully updated" << endl;
		}
		else
		{
			cout << "Invalid option" << endl;
		}
		cout << "Capacity --> " << capacity << endl;
		break;
	}
	case 2:
	{
		if (block == 'A')
		{
			capacity = App._meal.total_a;
			cout << "Meal capacity successfully updated" << endl;
		}
		else if (block == 'B')
		{
			capacity = App._meal.total_b;
			cout << "Meal capacity successfully updated" << endl;
		}
		else
		{
			cout << "Invalid option" << endl;
		}
		cout << "Capacity --> " << capacity << endl;
		break;
	}
	case 3:
	{
		if (block == 'A')
		{
			capacity = App.dinner.total_a;
			cout << "Dinner capacity successfully updated" << endl;
		}
		else if (block == 'B')
		{
			capacity = App.dinner.total_b;
			cout << "Dinner capacity successfully updated" << endl;
		}
		else
		{
			cout << "Invalid option" << endl;
		}
		cout << "Capacity --> " << capacity << endl;
		break;
	}
	default:
	{
		cout << "Invalid option" << endl;
	}
	}
}

inline void which_students_block(app& App)
{
	int hour;
	char block;
	vector<student> list;
	cout << "-------- WHICH STUDENTS IN BLOCK--------" << endl;
	cout << "1) Breakfast" << endl;
	cout << "2) Meal" << endl;
	cout << "3) Dinner" << endl;

	cout << "Select your option: ";
	cin >> hour;
	cin.ignore();

	cout << "Block A" << endl;
	cout << "Block B" << endl;
	cout << "Select your option: ";

	cin >> block;
	cin.ignore();

	switch (hour)
	{
	case 1:
	{
		if (block == 'A')
		{
			list = App.breakfast.list_a;
			print_students(App);
			break;
		}
		if (block == 'B')
		{
			list = App.breakfast.list_b;
			print_students(App);
			break;
		}
		if (block != 'A' && block != 'B') cout << "Invalid option" << endl;
		break;
	}
	case 2:
	{
		if (block == 'A')
		{
			list = App._meal.list_a;
			print_students(App);
			break;
		}
		if (block == 'B')
		{
			list = App._meal.list_b;
			print_students(App);
			break;
		}
		if (block != 'A' && block != 'B') cout << "Invalid option" << endl;
		break;
	}
	case 3:
	{
		if (block == 'A')
		{
			list = App.dinner.list_a;
			print_students(App);
			break;
		}
		if (block == 'B')
		{
			list = App.dinner.list_b;
			print_students(App);
			break;
		}
		if (block != 'A' && block != 'B') cout << "Invalid option" << endl;
		break;
	}
	default:
	{
		cout << "Invalid option" << endl;
		break;
	}
	}
}

inline void logged_admin(app& App)
{
	vector<admin> list = App.admins;
	bool run = true;
	int option;

	while (run)
	{
		system("clear");
		cout << "-------- LOGGED ADMIN MENU --------" << endl;
		cout << "1) Disable Admin" << endl;
		cout << "2) Enable Admin" << endl;
		cout << "3) Edit Total Capacity" << endl;
		cout << "4) Edit a Specific Meal Block Capacity" << endl;
		cout << "5) See How Many Students in Block " << endl;
		cout << "6) See Which Students in Meal " << endl;
		cout << "7) Exit" << endl;

		cout << "Select your option: ";
		cin >> option;
		cin.ignore();

		switch (option)
		{
		case DisAdmin:
		{
			cout << "Disabling Admin..." << endl;
			disable_admin(App);
			break;
		}

		case EnaAdmin:
		{
			cout << "Enabling Admin..." << endl;
			enable_admin(App);
			break;
		}

		case EdTotCap:
		{
			cout << "Editing Total Capacity..." << endl;
			edit_total_capacity(App);
			break;
		}

		case EdSpecMealBlockCap:
		{
			cout << "Editing Specific Meal Block Capacity..." << endl;
			edit_specific_meal_block_capacity(App);
			break;
		}

		case HowManyStudsBlock:
		{
			cout << "How Many Students in Block..." << endl;
			how_may_students_block(App);
			break;
		}

		case WhichStudsBlock:
		{
			cout << "Which Students in Block..." << endl;
			which_students_block(App);
			break;
		}

		case ExitAdminLog:
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

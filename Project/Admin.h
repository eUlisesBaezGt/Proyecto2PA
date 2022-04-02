#pragma once

#include <iostream>
#include <vector>
#include <string>


class admin
{
public:
	int id{};
	string password{};

	string name;
	string middleName;
	string lastName;
	int age{};
	char gender{};
	bool status = true;
};


inline bool check_admin_id(const int id, const vector<admin>& list)
{
	bool used = false;
	for (auto& i : list)
	{
		if (i.id == id) used = true;
		break;
	}
	return used;
}

inline int get_admin_id(const vector<admin>& list)
{
	const int n = rand() % 100;
	const bool used = check_admin_id(n, list);
	if (!used) return n;
	return get_admin_id(list);
}

inline void print_admins(const vector<admin>& list)
{
	for (auto& i : list)
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

inline void add_admin(vector<admin>& list)
{
	admin temp;
	temp.id = get_admin_id(list);
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
	list.push_back(temp);

	system("clear");
}

inline void enable_admin(vector<admin>& list)
{
	bool found = false;
	cout << "ID of Admin to enable: ";
	int is;
	cin >> is;
	cin.ignore();
	for (auto& i : list)
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

inline void disable_admin(vector<admin>& list)
{
	bool found = false;
	cout << "ID of Admin to disable: ";
	int is;
	cin >> is;
	cin.ignore();
	for (auto& i : list)
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

inline void logged_admin(vector<admin>& list)
{
	bool run = true;
	int option;

	while (run)
	{
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
			disable_admin(list);
			break;
		}

		case EnaAdmin:
		{
			cout << "Enabling Admin..." << endl;
			enable_admin(list);
			break;
		}

		case EdTotCap:
		{
			cout << "Editing Total Capacity..." << endl;
			break;
		}

		case EdSpecMealBlockCap:
		{
			cout << "Editing Specific Meal Block Capacity..." << endl;
			break;
		}

		case HowManyStudsBlock:
		{
			cout << "How Many Students in Block..." << endl;
			break;
		}

		case WhichStudsBlock:
		{
			cout << "Which Students in Block..." << endl;
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

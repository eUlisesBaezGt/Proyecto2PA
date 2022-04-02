#pragma once


//inline void login_admin(vector<Admin>& list) {
//	bool found = false;
//	int ID;
//	string Password;
//	cout << "Enter your ID: ";
//	cin >> ID;
//	cin.ignore();
//	cout << "Enter your password: ";
//	getline(cin, Password);
//	for (auto& i : list) {
//		if (i.id == ID && i.password == Password && i.status) {
//			found = true; break;
//		}
//	}
//	if (found) { cout << "Welcome " << endl; logged_admin(list); }
//	else if (!found) { cout << "Invalid ID or password or user disabled" << endl; }
//}

inline void login_stud(vector<student>& list)
{
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
		logged_student(list);
	}
	else if (!found) { cout << "Invalid ID or password or user disabled" << endl; }
}

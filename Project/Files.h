#pragma once

#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include<sstream>

#include "App.h"


inline void make_files()
{
	string filename = "Students.csv";
	ifstream ifile;
	ifile.open(filename);
	if (!ifile)
	{
		ifile.close();
		ofstream myFileOutput(filename, ios_base::app);
		myFileOutput << "ID,Password,Name,,Middle_Name,Last_Name,Age,Gender,Status,Breakfast,Meal,Dinner\n";
		myFileOutput.close();
	}

	string filename2 = "Admins.csv";
	ifstream ifile2;
	ifile2.open(filename2);
	if (!ifile2)
	{
		ifile2.close();
		ofstream myFileOutput(filename2, ios_base::app);
		myFileOutput << "ID,Password,Name,Middle_Name,Last_Name,Age,Gender,Status,Breakfast,Meal,Dinner\n";
		myFileOutput.close();
	}

	string filename3 = "Total.csv";
	ifstream ifile3;
	ifile3.open(filename3);
	if (!ifile3)
	{
		ifile3.close();
		ofstream myFileOutput(filename3, ios_base::app);
		myFileOutput << "Total Student Capacity\n";
		myFileOutput << "100\n";
		myFileOutput.close();
	}

	string filename4 = "BlockBreakfast.csv";
	ifstream ifile4;
	ifile4.open(filename4);
	if (!ifile4)
	{
		ifile4.close();
		ofstream myFileOutput(filename4, ios_base::app);
		myFileOutput << "Block,Capacity\n";
		myFileOutput.close();
	}

	string filename5 = "BlockMeal.csv";
	ifstream ifile5;
	ifile5.open(filename5);
	if (!ifile5)
	{
		ifile5.close();
		ofstream myFileOutput(filename5, ios_base::app);
		myFileOutput << "Block,Capacity\n";
		myFileOutput.close();
	}

	string filename6 = "BlockDinner.csv";
	ifstream ifile6;
	ifile6.open(filename6);
	if (!ifile6)
	{
		ifile6.close();
		ofstream myFileOutput(filename6, ios_base::app);
		myFileOutput << "Block,Capacity\n";
		myFileOutput.close();
	}
}

inline void read_total_students(app& App)
{
	string line, colname;
	vector<string> headers;
	string value;
	string filename = "Total.csv";
	ifstream myFileInput(filename);

	if (!myFileInput.is_open()) throw runtime_error("Could not open file");
	if (myFileInput.good())
	{
		// Extract the first line in the file
		getline(myFileInput, line);

		// Create a stringstream from line
		stringstream ss(line);

		// Extract each column name
		while (getline(ss, colname, ','))
		{
			headers.push_back(colname);
		}
	}
	while (getline(myFileInput, line))
	{
		// Create a stringstream of the current line
		stringstream ss(line);

		int colIdx = 0;
		int _total;
		while (getline(ss, value, ','))
		{
			switch (colIdx)
			{
			case 0:
				_total = stoi(value);
				break;
			default:
				break;
			}

			// If ',' as next character, skip it
			if (ss.peek() == ',') ss.ignore();
			colIdx++;
		}
		App.total_students = _total;
	}
	myFileInput.close();
}

inline void read_students(app& App)
{
	string line, colname;
	vector<string> headers;
	string value;

	ifstream myFileInput("Students.csv");
	if (!myFileInput.is_open()) throw runtime_error("Could not open file");
	if (myFileInput.good())
	{
		// Extract the first line in the file
		getline(myFileInput, line);

		// Create a stringstream from line
		stringstream ss(line);

		// Extract each column name
		while (getline(ss, colname, ','))
		{
			headers.push_back(colname);
		}
	}

	while (getline(myFileInput, line))
	{
		// Create a stringstream of the current line
		stringstream ss(line);

		int colIdx = 0;
		int _id, _age;
		string _password, _name, _middle_name, _last_name, _gender, _status, _breakfast, _meal, _dinner;

		while (getline(ss, value, ','))
		{
			switch (colIdx)
			{
			case 0:
				_id = stoi(value);
				break;
			case 1:
				_password = value;
				break;
			case 2:
				_name = value;
				break;
			case 3:
				_middle_name = value;
				break;
			case 4:
				_last_name = value;
				break;
			case 5:
				_age = stoi(value);
				break;
			case 6:
				_gender = value;
				break;
			case 7:
				_status = value;
				break;
			case 8:
				_breakfast = value;
				break;
			case 9:
				_meal = value;
				break;
			case 10:
				_dinner = value;
				break;
			default:
				break;
			}

			// If ',' as next character, skip it
			if (ss.peek() == ',') ss.ignore();
			colIdx++;
		}

		student temp = {
			_id, _password, _name, _middle_name, _last_name, _age, _gender, _status, _breakfast, _meal, _dinner
		};
		App.students.push_back(temp);
	}
	myFileInput.close();
}

inline void read_blocks_breakfast(app& App)
{
	string line, colname;
	vector<string> headers;
	string value;
	ifstream myFileInput("BlocksBreakfast.csv");
	if (!myFileInput.is_open()) throw runtime_error("Could not open file");
	if (myFileInput.good())
	{
		// Extract the first line in the file
		getline(myFileInput, line);

		// Create a stringstream from line
		stringstream ss(line);

		// Extract each column name
		while (getline(ss, colname, ','))
		{
			headers.push_back(colname);
		}
	}
	while (getline(myFileInput, line))
	{
		// Create a stringstream of the current line
		stringstream ss(line);

		int colIdx = 0;
		int _capacity;
		string _block;

		while (getline(ss, value, ','))
		{
			switch (colIdx)
			{
			case 0:
				_block = value;
				break;
			case 1:
				_capacity = stoi(value);
				break;
			default:
				break;
			}

			// Si el siguiente token es una coma, ignoralo y se mueve al siguiente elemento
			if (ss.peek() == ',') ss.ignore();
			colIdx++;
		}
		if (_block == "A")
		{
			_capacity = App.breakfast.total_a;
		}
		if (_block == "B")
		{
			_capacity = App.breakfast.total_b;
		}
		App.breakfast.total = App.breakfast.total_a + App.breakfast.total_b;
	}
}

inline void read_blocks_meal(app& App)
{
	string line, colname;
	vector<string> headers;
	string value;
	ifstream myFileInput("BlocksMeal.csv");
	if (!myFileInput.is_open()) throw runtime_error("Could not open file");
	if (myFileInput.good())
	{
		// Extract the first line in the file
		getline(myFileInput, line);

		// Create a stringstream from line
		stringstream ss(line);

		// Extract each column name
		while (getline(ss, colname, ','))
		{
			headers.push_back(colname);
		}
	}
	while (getline(myFileInput, line))
	{
		// Create a stringstream of the current line
		stringstream ss(line);

		int colIdx = 0;
		int _capacity;
		string _block;

		while (getline(ss, value, ','))
		{
			switch (colIdx)
			{
			case 0:
				_block = value;
				break;
			case 1:
				_capacity = stoi(value);
				break;
			default:
				break;
			}

			// Si el siguiente token es una coma, ignoralo y se mueve al siguiente elemento
			if (ss.peek() == ',') ss.ignore();
			colIdx++;
		}
		if (_block == "A")
		{
			_capacity = App._meal.total_a;
		}
		if (_block == "B")
		{
			_capacity = App._meal.total_b;
		}
		App._meal.total = App._meal.total_a + App._meal.total_b;
	}
}

inline void read_blocks_dinner(app& App)
{
	string line, colname;
	vector<string> headers;
	string value;
	ifstream myFileInput("BlocksDinner.csv");
	if (!myFileInput.is_open()) throw runtime_error("Could not open file");
	if (myFileInput.good())
	{
		// Extract the first line in the file
		getline(myFileInput, line);

		// Create a stringstream from line
		stringstream ss(line);

		// Extract each column name
		while (getline(ss, colname, ','))
		{
			headers.push_back(colname);
		}
	}
	while (getline(myFileInput, line))
	{
		// Create a stringstream of the current line
		stringstream ss(line);

		int colIdx = 0;
		string _block;
		int _capacity;

		while (getline(ss, value, ','))
		{
			switch (colIdx)
			{
			case 0:
				_block = value;
				break;
			case 1:
				_capacity = stoi(value);
				break;
			default:
				break;
			}

			if (_block == "A")
			{
				_capacity = App.dinner.total_a;
			}
			if (_block == "B")
			{
				_capacity = App.dinner.total_b;
			}
			App.dinner.total = App.dinner.total_a + App.dinner.total_b;


			// Si el siguiente token es una coma, ignoralo y se mueve al siguiente elemento
			if (ss.peek() == ',') ss.ignore();
			colIdx++;
		}
		myFileInput.close();
	}
}

inline void read_admins(app& App)
{
	string line, colname;
	vector<string> headers;
	string value;

	ifstream myFileInput("Admins.csv");
	if (!myFileInput.is_open()) throw runtime_error("Could not open file");
	if (myFileInput.good())
	{
		// Extract the first line in the file
		getline(myFileInput, line);

		// Create a stringstream from line
		stringstream ss(line);

		// Extract each column name
		while (getline(ss, colname, ','))
		{
			headers.push_back(colname);
		}
	}

	while (getline(myFileInput, line))
	{
		// Create a stringstream of the current line
		stringstream ss(line);

		int colIdx = 0;
		int _id, _age;
		string _password, _name, _middle_name, _last_name, _gender, _status, _breakfast, _meal, _dinner;

		while (getline(ss, value, ','))
		{
			switch (colIdx)
			{
			case 0:
				_id = stoi(value);
				break;
			case 1:
				_password = value;
				break;
			case 2:
				_name = value;
				break;
			case 3:
				_middle_name = value;
				break;
			case 4:
				_last_name = value;
				break;
			case 5:
				_age = stoi(value);
				break;
			case 6:
				_gender = value;
				break;
			case 7:
				_status = value;
				break;
			case 8:
				_breakfast = value;
				break;
			case 9:
				_meal = value;
				break;
			case 10:
				_dinner = value;
				break;
			default:
				break;
			}

			// If ',' as next character, skip it
			if (ss.peek() == ',') ss.ignore();
			colIdx++;
		}

		admin temp = {
			_id, _password, _name, _middle_name, _last_name, _age, _gender, _status
		};
		App.admins.push_back(temp);
	}
	myFileInput.close();
}


inline void add_student_2_file(const app App)
{
	ofstream myFileOutput("Students.csv", ios_base::app);
	for (auto& student : App.students)
	{
		myFileOutput << student.id << "," << student.password << "," << student.name << ","
			<< student.middleName << "," << student.lastName << "," << student.age << ","
			<< student.gender;
	}
	myFileOutput.close();
}

inline void add_admin_2_file(const app App)
{
	ofstream myFileOutput("Admins.csv", ios_base::app);
	for (auto& admin : App.admins)
	{
		myFileOutput << admin.id << "," << admin.password << "," << admin.name << ","
			<< admin.middleName << "," << admin.lastName << "," << admin.age << ","
			<< admin.gender;
	}
	myFileOutput.close();
}

inline void update_total(const app App)
{
	const int n = App.total_students;
	ofstream myFileOutput("Total.csv");
	myFileOutput << n;
}

inline void update_block(const app App)
{
	ofstream myFileOutput("BlockBreakfast.csv");
	ofstream myFileOutput2("BlockMeal.csv");
	ofstream myFileOutput3("BlockDinnerBreakfast.csv");
	myFileOutput << "A" << "," << App.breakfast.total_a << "\n"
		<< "B" << App.breakfast.total_b;

	myFileOutput2 << "A" << "," << App._meal.total_a << "\n"
		<< "B" << App._meal.total_b;

	myFileOutput3 << "A" << "," << App.dinner.total_a << "\n"
		<< "B" << App.dinner.total_b;
}

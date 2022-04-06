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
		ofstream myFileOutput(filename);
		myFileOutput << "id" << "," << "password" << "," << "name" << ","
			<< "middleName" << "," << "lastName" << "," << "age" << ","
			<< "gender" << "," << "status" << "," << "breakfast" << "," << "meal" << "," << "dinner"
			<< "\n";
		myFileOutput.close();
	}

	string filename2 = "Admins.csv";
	ifstream ifile2;
	ifile2.open(filename2);
	if (!ifile2)
	{
		ofstream myFileOutput(filename2);
		myFileOutput << "id" << "," << "password" << "," << "name" << ","
			<< "middleName" << "," << "lastName" << "," << "age" << ","
			<< "gender" << "," << "status" << "\n";
		myFileOutput.close();
	}

	string filename3 = "Total.csv";
	ifstream ifile3;
	ifile3.open(filename3);
	if (!ifile3)
	{
		ofstream myFileOutput(filename3);
		myFileOutput << "4\n";
		myFileOutput.close();
	}

	string filename4 = "BlockBreakfast.csv";
	ifstream ifile4;
	ifile4.open(filename4);
	if (!ifile4)
	{
		ofstream myFileOutput(filename4);
		myFileOutput << "Block,Capacity\n";
		myFileOutput << "A,2\n";
		myFileOutput << "B,2\n";
		myFileOutput.close();
	}

	string filename5 = "BlockMeal.csv";
	ifstream ifile5;
	ifile5.open(filename5);
	if (!ifile5)
	{
		ofstream myFileOutput(filename5);
		myFileOutput << "Block,Capacity\n";
		myFileOutput << "A,2\n";
		myFileOutput << "B,2\n";
		myFileOutput.close();
	}

	string filename6 = "BlockDinner.csv";
	ifstream ifile6;
	ifile6.open(filename6);
	if (!ifile6)
	{
		ofstream myFileOutput(filename6);
		myFileOutput << "Block,Capacity\n";
		myFileOutput << "A,2\n";
		myFileOutput << "B,2\n";
		myFileOutput.close();
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
		string _password, _name, _middle_name, _last_name, _gender, _status;

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

inline void read_total_students(app& App)
{
	string line, colname;
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

		int colIdx = 0;
		int _total{};

		while (getline(ss, value, ','))
		{
			if (colIdx == 0)
			{
				_total = stoi(value);
			}
		}
		App.total_students = _total;
	}

	myFileInput.close();
}

inline void read_blocks_breakfast(app& App)
{
	string line, colname;
	vector<string> headers;
	string value;
	ifstream myFileInput("BlockBreakfast.csv");
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

				if (_block == "A")
				{
					App.breakfast.total_a = _capacity;
				}
				if (_block == "B")
				{
					App.breakfast.total_b = _capacity;
				}

				// Si el siguiente token es una coma, ignoralo y se mueve al siguiente elemento
				if (ss.peek() == ',') ss.ignore();
				colIdx++;
			}
		}
		myFileInput.close();
	}
}

inline void read_blocks_meal(app& App)
{
	string line, colname;
	vector<string> headers;
	string value;
	ifstream myFileInput("BlockMeal.csv");
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
		while (getline(myFileInput, line))
		{
			// Create a stringstream of the current line
			stringstream ss(line);

			int colIdx = 0;
			int _capacity = 0;
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

				if (_block == "A")
				{
					App._meal.total_a = _capacity;
				}
				if (_block == "B")
				{
					App._meal.total_b = _capacity;
				}

				// Si el siguiente token es una coma, ignoralo y se mueve al siguiente elemento
				if (ss.peek() == ',') ss.ignore();
				colIdx++;
			}
		}
		myFileInput.close();
	}
}

inline void read_blocks_dinner(app& App)
{
	string line, colname;
	vector<string> headers;
	string value;
	ifstream myFileInput("BlockDinner.csv");
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
		while (getline(myFileInput, line))
		{
			// Create a stringstream of the current line
			stringstream ss(line);

			int colIdx = 0;
			int _capacity = 0;
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

				if (_block == "A")
				{
					App.dinner.total_a = _capacity;
				}
				if (_block == "B")
				{
					App.dinner.total_b = _capacity;
				}

				// Si el siguiente token es una coma, ignoralo y se mueve al siguiente elemento
				if (ss.peek() == ',') ss.ignore();
				colIdx++;
			}
		}
		myFileInput.close();
	}
}


inline void add_student_2_file(const app App)
{
	ofstream myFileOutput("Students.csv");
	myFileOutput << "id" << "," << "password" << "," << "name" << ","
		<< "middleName" << "," << "lastName" << "," << "age" << ","
		<< "gender" << "," << "status" << "," << "breakfast" << "," << "meal" << "," << "dinner"
		<< "\n";


	for (auto& student : App.students)
	{
		myFileOutput << student.id << "," << student.password << "," << student.name << ","
			<< student.middleName << "," << student.lastName << "," << student.age << ","
			<< student.gender << "," << student.status << "," << student.breakfast << "," << student._meal << ","
			<< student.dinner << "\n";
	}
	myFileOutput.close();
}

inline void add_admin_2_file(const app App)
{
	ofstream myFileOutput("Admins.csv");
	myFileOutput << "id" << "," << "password" << "," << "name" << ","
		<< "middleName" << "," << "lastName" << "," << "age" << ","
		<< "gender" << "," << "status" << "\n";

	for (auto& admin : App.admins)
	{
		myFileOutput << admin.id << "," << admin.password << "," << admin.name << ","
			<< admin.middleName << "," << admin.lastName << "," << admin.age << ","
			<< admin.gender << "," << admin.status << "\n";
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
	ofstream myFileOutput3("BlockDinner.csv");
	myFileOutput << "Block,Capacity\n";
	myFileOutput << "A" << "," << App.breakfast.total_a << "\n"
		<< "B" << "," << App.breakfast.total_b;
	myFileOutput2 << "Block,Capacity\n";
	myFileOutput2 << "A" << "," << App._meal.total_a << "\n"
		<< "B" << "," << App._meal.total_b;
	myFileOutput3 << "Block,Capacity\n";
	myFileOutput3 << "A" << "," << App.dinner.total_a << "\n"
		<< "B" << "," << App.dinner.total_b;
}

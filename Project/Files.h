#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include<sstream>
#include <utility>

#include "App.h"

using namespace std;


inline void make_files()
{
	string filename = "Students.csv";
	ifstream ifile;
	ifile.open(filename);
	if (!ifile)
	{
		ifile.close();
		ofstream myFileOutput("./Students.csv", ios_base::app);
		myFileOutput << "ID,Password,Name,,Middle_Name,Last_Name,Age,Gender,Status,Breakfast,Meal,Dinner\n";
		myFileOutput.close();
	}

	string filename2 = "Admins.csv";
	ifstream ifile2;
	ifile2.open(filename2);
	if (!ifile2)
	{
		ifile2.close();
		ofstream myFileOutput("./Admins.csv", ios_base::app);
		myFileOutput << "ID,Password,Name,Middle_Name,Last_Name,Age,Gender,Status,Breakfast,Meal,Dinner\n";
		myFileOutput.close();
	}
}


inline void read_students(vector<student>& students)
{
	string line, colname;
	vector<string> headers;
	string value;
	ifstream myFileInput("./Students.csv");
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
		string _password, _name, _middle_name, last_name;
		string _gender, _breakfast, _meal, _dinner;
		string _status;

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
				last_name = value;
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
		}

		// If next element is ',' ignore it and continue
		if (ss.peek() == ',') ss.ignore();
		colIdx++;
		student temp = {
			_id, _password, _name, _middle_name, last_name, _age, _gender, _status, _breakfast, _meal, _dinner
		};
		students.push_back(temp);
		ofstream myFileOutput("./Students.csv", ios_base::app);
		myFileOutput << temp.id << "," << temp.name << "," << temp.lastName << "," << temp.middleName << "," << temp.age
			<< "," << temp.gender << "," << temp.status << "," << temp.breakfast << "," << temp._meal << "," << temp.
			dinner << endl;
	}
	myFileInput.close();
}

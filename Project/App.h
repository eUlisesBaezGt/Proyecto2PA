#pragma once

#include <vector>

using namespace std;

class student
{
public:
	int id{};
	string password{};

	string name;
	string middleName;
	string lastName;
	int age{};
	string gender{};
	string status = "true";

	string breakfast{};
	string _meal{};
	string dinner{};
};

class admin
{
public:
	int id{};
	string password{};

	string name;
	string middleName;
	string lastName;
	int age{};
	string gender{};
	string status = "true";
};

struct meal
{
	int total{};
	int Maxtotal{};
	int total_a{};
	int total_b{};

	vector<student> list_a;
	vector<student> list_b;
};

struct app
{
	vector<student> students;
	vector<admin> admins;
	int total_students{};

	meal breakfast;
	meal _meal;
	meal dinner;
};

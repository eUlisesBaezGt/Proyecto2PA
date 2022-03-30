#pragma once

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

#include "Enums.h"
#include "Menu.h"

using namespace std;

class Student {
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

bool CheckStudentID(int id, const vector<Student> &lista) {
    for (auto &i: lista) {
        if (i.id == id) return true; else return false;
    }
}

int GetStudentId(int n, const vector<Student>& lista) {
    n = rand() % 100;
    for (int i = 0; i < lista.size(); ++i) {
        if (!CheckStudentID(n, lista)) return n; else GetStudentId(n, lista);
    }
}

void EnableStudent(vector<Student> lista) {
    bool found = false;
    cout << "ID of Student to enable: ";
    int IS;
    cin >> IS;
    cin.ignore();
    for (auto &i: lista) {
        if (IS == i.id) {
            found = true;
            i.status = true;
            cout << "Student status successfully updated" << endl;
        }
    }
    if (!found) {
        cout << "Student ID not found" << endl;
    }
}

void DisableStudent(vector<Student> lista) {
    bool found = false;
    cout << "ID of Admin to disable: ";
    int IS;
    cin >> IS;
    cin.ignore();
    for (auto &i: lista) {
        if (IS == i.id) {
            found = true;
            i.status = false;
            cout << "Admin status successfully updated" << endl;
        }
    }
    if (!found) {
        cout << "Student ID not found" << endl;
    }
}

void PrintStudents(const vector<Student> &lista) {
    for (auto &i: lista) {
        cout << "-----------------------" << endl;
        cout << "ID: " << i.id << "\tName: " << i.name << "\tMiddle Name: " << i.middleName
             << "\tLast Name: " << i.lastName << "\nStatus" << i.status;
    }
}

void LoginStud(const vector<Student> &lista) {
    int ID;
    string Password;
    cout << "Enter your ID: ";
    cin >> ID;
    cin.ignore();
    cout << "Enter your password: ";
    getline(cin, Password);
    for (auto &i: lista) {
        if (i.id == ID && i.password == Password && i.status) {
            cout << "Welcome " << i.name << endl;
            // MENU
        }
    }
    cout << "Invalid ID or password" << endl;
}

void AddStudent(vector<Student> &lista) {
    Student temp;
    int n = 0;
    temp.id = GetStudentId(n, lista);
    cout << " ------ Register Client ------ " << endl;
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
    cin >> temp.age;
    cin.ignore();
    cout << "PASSWORD: ";
    getline(cin, temp.password);
    lista.push_back(temp);
    
    system("clear");
}

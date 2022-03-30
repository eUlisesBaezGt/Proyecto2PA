#pragma once

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

#include "Admin.h"
#include "Student.h"
#include "Enums.h"

using namespace std;


void LogStudent(const vector<Student> &students) {
    cout << "-------- LOGGED STUDENT MENU -------- ";
    cout << "1) Disable Student" << endl;
    cout << "2) Enable Student" << endl;
    cout << "3) Register Breakfast" << endl;
    cout << "4) Register Meal" << endl;
    cout << "5) Register Dinner" << endl;
    cout << "6) Exit" << endl;
    cout << "Select your option: ";
    int option;
    cin >> option;
    cin.ignore();
    switch (option) {
        case DisStudent:
            cout << "Disable Student" << endl;
            DisableStudent(students);
            break;
        case EnaStudent:
            cout << "Enable Student" << endl;
            EnableStudent(students);
            break;
        case RegBreakfast:
            cout << "Register Breakfast" << endl;
            break;
        case RegMeal:
            cout << "Register Meal" << endl;
            break;
        case RegDinner:
            cout << "Register Dinner" << endl;
            break;
        case ExitStudentLog:
            cout << "Goodbye" << endl;
            break;
        default:
            cout << "Invalid option";
            break;
    }
}

void StudentMenu(const vector<Student> &list) {
    cout << "-------- STUDENT MENU -------- " << endl;
    cout << "1) Login" << endl;
    cout << "2) Add Student" << endl;
    cout << "3) Print All" << endl;
    cout << "4) Exit" << endl;
    cout << "Select your option: ";
    int option;
    cin >> option;
    cin.ignore();
    switch (option) {
        case LogStud:
            LogStudent(list);
            break;
        case AddStud:
            // AddStud(list);
            break;
        case PrAStud:
            PrintStudents(list);
            break;
        case ExitStudent:
            cout << "Goodbye" << endl;
            break;
        default:
            cout << "Invalid option";
            StudentMenu(list);
            break;
    }
}

void AdminMenu(vector<Admin> list) {
    cout << "-------- ADMIN MENU -------- " << endl;
    cout << "1) Login" << endl;
    cout << "2) Add Admin" << endl;
    cout << "3) Print All" << endl;
    cout << "4) Exit" << endl;
    cout << "Select your option: ";
    int option;
    cin >> option;
    cin.ignore();
    switch (option) {
        case LogAdm:
            LoginAdmin(list);
            break;
        case AddAdm:
            AddAdmin(list);
            break;
        case PrAAdm:
            PrintAdmins(list);
            break;
        case ExitAdmin:
            cout << "Goodbye" << endl;
            break;
        default:
            cout << "Invalid option";
            AdminMenu(list);
            break;
    }
}

[[noreturn]] void MainMenu() {
    vector<Student> students;
    vector<Admin> admins;
    char choice;

    while (true) {
        cout << "A) Use as Admin" << endl;
        cout << "S) Use as Student" << endl;
        cout << "Q) Quit" << endl;
        cout << "Select your option: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 'A':
                cout << "Admin Menu" << endl;
                AdminMenu(admins);
                break;
            case 'S':
                cout << "Student Menu" << endl;
                StudentMenu(students);
                break;
            case 'Q':
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
                // press enter to continue
                break;
        }
        
    }
}

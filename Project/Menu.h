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


void MainMenu() {
    vector<Student> students;
    // vector<Admin> admins;
    char choice;
    bool run = true;

    while (run) {
        cout << "A) Use as Admin" << endl;
        cout << "S) Use as Student" << endl;
        cout << "Q) Quit" << endl;
        cout << "Select your option: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
        case 'A':
            AdminMenu(admins);
            break;
         /*case 'S':
                StudentMenu(students);
                break;*/
        case 'Q':
            cout << "Goodbye!" << endl;
            run = false;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }

    }
}

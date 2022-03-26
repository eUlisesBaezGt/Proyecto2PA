#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

#include "Student.h"
#include "Admin.h"


enum StudentsMenu{
    Add_Student=1,
    Store_Student_in_file,
    Disable_Student,
    Enable_Student,
    printClients,
    RegisterBreakfast,
    RegisterMeal,
    RegisterDinner,
};

enum AdminMenu{
    Add_Admin=1,
    Store_Admin_in_file,
    Disable_Admin,
    Enable_Admin,
    EditStudentscapacity,
    Capacityforeachmeal,
    ModifyHowManyPlatesperBlock,
    Seethestudentsineachblock,
};


//bool checkID(const string& ID, vector<Admin> list) { // Checks if the ID is already in use
//    for (auto &i: list) {
//        if (i.myID() == ID) {
//            return true;
//        } else {
//            return false;
//        }
//    }
//}


void showMenuStudent() {
    cout << "1. Add Student" << endl;
    cout << "2. Store Student in file" << endl;
    cout << "3. Disable Student" << endl;
    cout << "4. Enable Student" << endl;
}

void showMenuAdmin() {
    cout << "1. Add Admin" << endl;
    cout << "2. Store Admin in file" << endl;
    cout << "3. Disable Admin" << endl;
    cout << "4. Enable Admin" << endl;
}

void showMainMenu() { // login as admin or student
    char choice;
    cout << "A) Login as Admin" << endl;
    cout << "S) Login as Student" << endl;
    cin >> choice;
    cin.ignore();
    switch(choice){
        case 'A':
            showMenuStudent();
            break;
        case 'S':
            showMenuAdmin();
            break;
        default:
            cout << "Invalid choice" << endl;
            showMainMenu();
            break;
    }

}

void checkLoginStudent(vector<Student> list) { // login as admin
    string ID;
    string password;
    cout << "Enter your ID: ";
    cin >> ID;
    cin.ignore();
    cout << "Enter your password: ";
    getline(cin, password);
    for (auto &i: list) {
        if (i.myID() == ID && i.myPassword() == password) {
            cout << "Welcome " << i.name() << endl;
            showMenuStudent();
            return;
        }
    }
    cout << "Invalid ID or password" << endl;
    checkLoginStudent(list);
}

//void checkLoginAdmin(vector<Admin> list) { // login as admin
//    string ID;
//    string password;
//    cout << "Enter your ID: ";
//    cin >> ID;
//    cin.ignore();
//    cout << "Enter your password: ";
//    getline(cin, password);
//    for (auto &i: list) {
//        if (i.myID() == ID && i.myPassword() == password) {
//            cout << "Welcome " << i.name() << endl;
//            showMenuAdmin();
//            return;
//        }
//    }
//    cout << "Invalid ID or password" << endl;
//    checkLoginAdmin(list);
//}



int main() {
    showMainMenu();
    return 0;
}

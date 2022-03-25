#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

#include "Student.h"
#include "Admin.h"


using namespace std;
enum StudentsMenu{
    printClients=1,
    RegisterBreakfast,
    RegisterMeal,
    RegisterDinner,
    
};

enum AdminMenu{
    EditStudentscapacity=1,
    Capacityforeachmeal,
    ModifyHowManyPlatesperBlock,
    Seethestudentsineachblock,
    
};


// MISSING: lists
int ID_GEN() {
    // Generate a random ID and verifies if it is already in use
    int ID;
    return ID;
}

bool checkID(int ID, vector<Student> list) { // Checks if the ID is already in use
    for (auto &i: list) {
        if (i.getID() == ID) {
            return true;
        } else {
            return false;
        }
    }
}

bool checkID(int ID, vector<Admin> list) { // Checks if the ID is already in use
    for (auto &i: list) {
        if (i.getID() == ID) {
            return true;
        } else {
            return false;
        }
    }
}


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
    int ID;
    string password;
    cout << "Enter your ID: ";
    cin >> ID;
    cin.ignore();
    cout << "Enter your password: ";
    getline(cin, password);
    for (auto &i: list) {
        if (i.getID() == ID && i.getPassword() == password) {
            cout << "Welcome " << i.getName() << endl;
            showMenuStudent();
            return;
        }
    }
    cout << "Invalid ID or password" << endl;
    checkLoginStudent(list);
}

void checkLoginAdmin(vector<Admin> list) { // login as admin
    int ID;
    string password;
    cout << "Enter your ID: ";
    cin >> ID;
    cin.ignore();
    cout << "Enter your password: ";
    getline(cin, password);
    for (auto &i: list) {
        if (i.getID() == ID && i.getPassword() == password) {
            cout << "Welcome " << i.getName() << endl;
            showMenuAdmin();
            return;
        }
    }
    cout << "Invalid ID or password" << endl;
    checkLoginAdmin(list);
}

class Admin  {
    private: int id;
    


    public: void administrador() {
        system("cls");
        int id, age;
        string name, last_name1, last_name2, gender;
        cout << " ------Administration------ " << endl;
        cout << "ID: ";
        cin >> id;
        cout << " Pleae enter your name: ";
        cin >> name;
        cout << " Pleae enter yor fisrt lastname: ";
        cin >> last_name1;
        cout << " Pleae enter your second lastname: ";
        cin >> last_name2;
        cout << " Enter your age: ";
        cin >> age;
        cout << "Enter your gender: ";
        cin >> gender;

        getAdmin(id, age, name, gender, last_name1, last_name2);
        system("cls");

    }
};
void getClient(int _id, int _age, string _name, string _last_name1, string _lastname2, string _gender){
    
    this -> id = _id;
    this -> age = _age;
    this -> name = _name;
    this-> last_name1 = _last_name1;
    this-> lastname2 = _last_name2;
    this -> gender = _gender;
    
};

int main() {
    showMainMenu();
    return 0;
}

#ifndef EXAMEN2_STUDENT_H
#define EXAMEN2_STUDENT_H

#include "enums_menus.h"
using namespace std;

class Student {

private:
    string id{};
    string password{};

public:
    string name;
    string middleName;
    string lastName;
    int age{};
    char gender{};
    bool status{};

    string myID() {
        return id;
    }

    string myPassword() {
        return password;
    }

    static string getId(const vector<Student> &list) {
        int n = rand() % 100;
        string id = to_string(n);
        for (int i = 0; i < list.size(); ++i) {
            if (!checkID(id, list)) return id;
            else getId(list);
        }
    }


    static bool checkID(string id, vector<Student> list) {
        for (auto &i: list) {
            if (i.myID() == id) return true;
            else return false;
        }
    }

    void add(vector<Student> &list){
        Student temp;
        temp.id = myID();
        cout << " -Register Client- " << endl;
        cout << "ID: " << id << endl;
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

        list.push_back(temp);
        system("clear");
    }

    static void enable(vector<Student> list) {
        bool found = false;
        cout << "ID of Student to enable: ";
        string IS;
        cin >> IS;
        cin.ignore();

        for (auto &i: list) {
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


    static void disable(vector<Student> list) {
        bool found = false;
        cout << "ID of Admin to disable: ";
        string IS;
        cin >> IS;
        cin.ignore();

        for (auto &i: list) {
            if (IS == i.id) {
                found = true;
                i.status = false;
                cout << "Admin status successfully updated" << endl;
            }
        }
        if (!found) {
            cout << "Admin ID not found" << endl;
        }
    }

    void checkLoginStudent(vector<Student> list) { // login as admin
        string ID;
        string Password;
        cout << "Enter your ID: ";
        cin >> ID;
        cin.ignore();
        cout << "Enter your password: ";
        getline(cin, Password);
        for (auto &i: list) {
            if (i.myID() == ID && i.myPassword() == Password) {
                cout << "Welcome " << i.myID() << endl;
                showMenuStudent();
                return;
            }
        }
        cout << "Invalid ID or password" << endl;
        checkLoginStudent(list);
    }


};

#endif //EXAMEN2_STUDENT_H


//  almacenar


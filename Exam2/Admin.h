#ifndef EXAMEN2_ADMIN_H
#define EXAMEN2_ADMIN_H

#include "aux.h"

using namespace std;

class Admin {

private:
    string id{};

public:
    string name;
    string middleName;
    string lastName;
    int age{};
    char gender{};
    bool status{};

    string myID() {
        id = getID();
        return id;
    }

    void add(vector<Admin> &list) const {
        Admin temp;
        temp.id = temp.myID();
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
        list.push_back(temp);
        system("clear");
    }

    static void enable(vector<Admin> list) {
        bool found = false;
        cout << "ID of Admin to enable: ";
        string IS;
        cin >> IS;
        cin.ignore();

        for (auto &i: list) {
            if (IS == i.id) {
                found = true;
                i.status = true;
                cout << "Admin status successfully updated" << endl;
            }
        }
        if (!found) {
            cout << "Admin ID not found" << endl;
        }
    }

    static void disable(vector<Admin> list) {
        bool found = false;
        cout << "ID of Admin to enable: ";
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

};

#endif //EXAMEN2_ADMIN_H

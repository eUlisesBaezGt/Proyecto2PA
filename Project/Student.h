#pragma once

#include <iostream>
#include <cmath>
#include <vector>
#include <string>

#include "Enums.h"
#include "Menu.h"

class Student;
using namespace std;

struct Breakfast
{
	int TotalA;
	int TotalB;

	vector<Student> listA;
	vector<Student> listB;
};

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

bool CheckStudentID(int id, const vector<Student> list) {
	bool b = false;
	for (auto& i : list) {
		if (i.id == id) return true; break;
	}
	return b;
}

int GetStudentId(int n, const vector<Student> list) {
	n = rand() % 100;
	for (int i = 0; i < list.size(); ++i) {
		if (!CheckStudentID(n, list)) return n; break;
	}
}

void AddStudent(vector<Student>& list) {
	Student temp;
	int n = 0;
	temp.id = GetStudentId(n, list);
	cout << " ------ Add Student ------ " << endl;
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
	cin >> temp.gender;
	cin.ignore();
	cout << "PASSWORD: ";
	getline(cin, temp.password);
	list.push_back(temp);

	system("clear");
}

void PrintStudents(const vector<Student> list) {
	for (auto& i : list) {
		cout << "-----------------------" << endl;
		cout << "ID: " << i.id << "\tName: " << i.name << "\tMiddle Name: " << i.middleName
			<< "\tLast Name: " << i.lastName << "\nStatus" << i.status;
	}
}


<<<<<<< HEAD
//
//
//
//
//void EnableStudent(vector<Student>& list) {
//    bool found = false;
//    cout << "ID of Student to enable: ";
//    int IS;
//    cin >> IS;
//    cin.ignore();
//    for (auto& i : list) {
//        if (IS == i.id) {
//            found = true;
//            i.status = true;
//            cout << "Student status successfully updated" << endl;
//        }
//    }
//    if (!found) {
//        cout << "Student ID not found" << endl;
//    }
//}
//
//void DisableStudent(vector<Student>& list) {
//    bool found = false;
//    cout << "ID of Student to disable: ";
//    int IS;
//    cin >> IS;
//    cin.ignore();
//    for (auto& i : list) {
//        if (IS == i.id) {
//            found = true;
//            i.status = false;
//            cout << "Student status successfully updated" << endl;
//        }
//    }
//    if (!found) {
//        cout << "Student ID not found" << endl;
//    }
//}
//
//
//
//void Log_Stud(vector<Student>& students) {
//    bool run = true;
//    int option;
//
//    while (run)
//    {
//        cout << "-------- LOGGED STUDENT MENU -------- ";
//        cout << "1) Disable Student" << endl;
//        cout << "2) Enable Student" << endl;
//        cout << "3) Register Breakfast" << endl;
//        cout << "4) Register Meal" << endl;
//        cout << "5) Register Dinner" << endl;
//        cout << "6) Exit" << endl;
//        cout << "Select your option: ";
//
//        cin >> option;
//        cin.ignore();
//        switch (option) {
//        case DisStudent:
//            cout << "Disable Student" << endl;
//            DisableStudent(students);
//            break;
//        case EnaStudent:
//            cout << "Enable Student" << endl;
//            EnableStudent(students);
//            break;
//        case RegBreakfast:
//            cout << "Register Breakfast" << endl;
//            break;
//        case RegMeal:
//            cout << "Register Meal" << endl;
//            break;
//        case RegDinner:
//            cout << "Register Dinner" << endl;
//            break;
//        case ExitStudentLog:
//            cout << "Return to Main Menu" << endl;
//            break;
//        default:
//            cout << "Invalid option";
//            break;
//        }
//    }
//}
//
//void LoginStud(vector<Student>& list) {
//    bool found = false;
//    int ID;
//    string Password;
//    cout << "Enter your ID: ";
//    cin >> ID;
//    cin.ignore();
//    cout << "Enter your password: ";
//    getline(cin, Password);
//    for (auto& i : list) {
//        if (i.id == ID && i.password == Password && i.status) {
//            found = true; break;}}
//    if (found){cout << "Welcome " << endl; Log_Stud(list);}
//    else if (!found){cout << "Invalid ID or password or user disabled" << endl;}}
//
//
//void Breakfast(){
//    bool run = true;
//    int option2;
//    string Scrambeled_eggs, Molletes, Chilaquiles, PapasHashbrown:"";
//
//    while (run)
//    {
//        cout << "-------- CHOOSE STUDENT MENU -------- ";
//        cout << "1) Scrambled eggs " << endl;
//        cout << "2) Molletes" << endl;
//        cout << "3) Chilaquiles" << endl;
//        cout<< " 4) Papas Hashbrown"
//        cout << "6) Exit" << endl;
//        cout << "Select your meal: ";
//        
//        
//        cin >> option2;
//        cin.ignore();
//        switch (option2) {
//        case Scrambeled_eggs:
//            cout << "Scrambeled eggs" << endl;
//            break;
//        case Molletes:
//            cout << "Molletes" << endl;
//            break;
//        case Molletes:
//            cout << "Molletes" << endl;
//            break;
//        case Molletes:
//            cout << "Molletes" << endl;
//            break;
//        case PapasHashbrown:
//            cout << "Papas Hashbrown" << endl;
//            break;
//                
//        
//        
//}
=======




void EnableStudent(vector<Student>& list) {
    bool found = false;
    cout << "ID of Student to enable: ";
    int IS;
    cin >> IS;
    cin.ignore();
    for (auto& i : list) {
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

void DisableStudent(vector<Student>& list) {
    bool found = false;
    cout << "ID of Student to disable: ";
    int IS;
    cin >> IS;
    cin.ignore();
    for (auto& i : list) {
        if (IS == i.id) {
            found = true;
            i.status = false;
            cout << "Student status successfully updated" << endl;
        }
    }
    if (!found) {
        cout << "Student ID not found" << endl;
    }
}



void Log_Stud(vector<Student>& students) {
    bool run = true;
    int option;

    while (run)
    {
        cout << "-------- LOGGED STUDENT MENU -------- ";
        cout << "1) Disable Student" << endl;
        cout << "2) Enable Student" << endl;
        cout << "3) Register Breakfast" << endl;
        cout << "4) Register Meal" << endl;
        cout << "5) Register Dinner" << endl;
        cout << "6) Exit" << endl;
        cout << "Select your option: ";

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
            cout << "Return to Main Menu" << endl;
            break;
        default:
            cout << "Invalid option";
            break;
        }
    }
}

void LoginStud(vector<Student>& list) {
    bool found = false;
    int ID;
    string Password;
    cout << "Enter your ID: ";
    cin >> ID;
    cin.ignore();
    cout << "Enter your password: ";
    getline(cin, Password);
    for (auto& i : list) {
        if (i.id == ID && i.password == Password && i.status) {
            found = true; break;}}
    if (found){cout << "Welcome " << endl; Log_Stud(list);}
    else if (!found){cout << "Invalid ID or password or user disabled" << endl;}}


void Breakfast(){
    bool run = true;
    int option2, price=0, acum_1=0, acum_2=0, acum_3=0, acum_4=0;
    string Scrambeled_eggs, Molletes, Chilaquiles, PapasHashbrown:"";

    while (run)
    {
        cout << "-------- CHOOSE STUDENT BREAKFAST -------- ";
        cout << "1) Scrambled eggs " << endl;
        cout << "2) Molletes" << endl;
        cout << "3) Chilaquiles" << endl;
        cout<< " 4) Papas Hashbrown"
        cout << "6) Exit" << endl;
        cout << "Select your meal: ";
        
        
        cin >> option2;
        cin.ignore();
        switch (option2) {
        case Scrambeled_eggs:
            cout << "Scrambeled eggs" << endl;
                price = price + 50;
                acum_1 ++;
            break;
        case Molletes:
            cout << "Molletes" << endl;
                price =  price + 45;
                acum_2 ++;
            break;
        case Molletes:
            cout << "Chilaquiles" << endl;
                price = price + 50;
                acum_3 ++;
            break;
        
        case PapasHashbrown:
            cout << "Papas Hashbrown" << endl;
                price = price +25;
                acum_4 ++;
            break;
        case Exit:
                if(acum_1!=0)
                {
                    cout << acum_1 "---------Scrambeled eggs bought ($50)" <<endl;
                }
                if(acum_2!=0)
                {
                    cout<< acum_2 "-----------Molletes bought ($45)" <<endl;
                }
                if(acum_3!=0)
                {
                    cout<< acum_3 "-----------Chilaquiles bought ($50)" <<endl;
                }
                if(acum_4!=0)
                {
                    cout<< acum_4 "-----------Papas Hshbrown bought ($25)" <<endl;
                }
                
                cout<< " The amount of money is: " + price;
                
            break;
        
                
}
void Meal (){
            bool run = true;
            int option2, price=0, acum_1=0, acum_2=0, acum_3=0, acum_4=0;
            string Hmaburger, Pizza, ChikenNuggets, FriedChiken:"";

            while (run)
            {
                cout << "-------- CHOOSE STUDENT MEAL -------- ";
                cout << "1) Hamburger " << endl;
                cout << "2) Pizza" << endl;
                cout << "3) Chiken Nuggets" << endl;
                cout<< " 4) Fried Chiken" << endl;
                cout << "6) Exit" << endl;
                cout << "Select your meal: ";
                
                
                cin >> option2;
                cin.ignore();
                switch (option2) {
                case Hamburger:
                    cout << "Hamburger" << endl;
                        price = price + 50;
                        acum_1 ++;
                    break;
                case Pizza:
                    cout << "Pizza" << endl;
                        price =  price + 45;
                        acum_2 ++;
                    break;
                case ChikenNuggets:
                    cout << "Chiken Nuggets" << endl;
                        price = price + 50;
                        acum_3 ++;
                    break;
                
                case FriedChiken:
                    cout << "Fried Chiken" << endl;
                        price = price +25;
                        acum_4 ++;
                    break;
                case Exit:
                        if(acum_1!=0)
                        {
                            cout << acum_1 "---------Hamburger ($50)" <<endl;
                        }
                        if(acum_2!=0)
                        {
                            cout<< acum_2 "-----------Pizza ($45)" <<endl;
                        }
                        if(acum_3!=0)
                        {
                            cout<< acum_3 "-----------Chiken Nuggets ($50)" <<endl;
                        }
                        if(acum_4!=0)
                        {
                            cout<< acum_4 "-----------Fried Chiken ($25)" <<endl;
                        }
                        
                        cout<< " The amount of money is: " + price
                        
                    break;
                        
                        
                
    }
}
void Dinner (){
                bool run = true;
                int option2, price=0, acum_1=0, acum_2=0, acum_3=0, acum_4=0;
                string Quesadillas, Molletes, Cereal, Tacos:"";

                while (run)
                {
                    cout << "-------- CHOOSE STUDENT DINNER -------- ";
                    cout << "1) Quesadillas " << endl;
                    cout << "2) Molletes" << endl;
                    cout << "3) Cereal" << endl;
                    cout<< " 4) Tacos" << endl;
                    cout << "6) Exit" << endl;
                    cout << "Select your meal: ";
                    
                    
                    cin >> option2;
                    cin.ignore();
                    switch (option2) {
                    case Quesadillas:
                        cout << "Quesadillas" << endl;
                            price = price + 50;
                            acum_1 ++;
                        break;
                    case Molletes:
                        cout << "Molletes" << endl;
                            price =  price + 45;
                            acum_2 ++;
                        break;
                    case Cereal:
                        cout << "Cereal" << endl;
                            price = price + 50;
                            acum_3 ++;
                        break;
                    
                    case Tacos:
                        cout << "Tacos" << endl;
                            price = price +25;
                            acum_4 ++;
                        break;
                    case Exit:
                            if(acum_1!=0)
                            {
                                cout << acum_1 "---------Quesadillas ($50)" <<endl;
                            }
                            if(acum_2!=0)
                            {
                                cout<< acum_2 "-----------Molletes ($45)" <<endl;
                            }
                            if(acum_3!=0)
                            {
                                cout<< acum_3 "-----------Cereal ($50)" <<endl;
                            }
                            if(acum_4!=0)
                            {
                                cout<< acum_4 "-----------Tacos ($25)" <<endl;
                            }
                            cout<< "The amount of money is: " + price;
                        break;
                            
                            
                    
        }
    }
>>>>>>> 3366729ecf0257f153b624f11457c1c8e0dc1197

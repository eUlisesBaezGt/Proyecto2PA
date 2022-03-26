#ifndef EXAMEN2_STUDENT_H
#define EXAMEN2_STUDENT_H

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

    string getId(vector <Student> list) {
        id = rand() % 100;
        for (int i = 0; i < list.size(); i++) {
            checkID()
            }
        }
        return id;}

    string myID(vector <Student> list){
        id = getID();
        bool flag = checkID(id, list);
        if flag == false{
            return id;
        }
        else{
            myID(list);
        }
    }

    bool checkID(string id, vector<Student> list) {
        for (auto &i: list) {
            if (i.myID() == id) {
                return true;
            } else {
                return false;
            }
        }
    }

    void add(vector<Student> &list) const {
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

    static void enable(vector<Student> list){
        bool found = false;
        cout << "ID of Student to enable: ";
        string IS;
        cin >> IS;
        cin.ignore();

        for(auto & i : list){
            if(IS == i.id){
                found = true;
                i.status = true;
                cout << "Student status successfully updated" << endl;
            }
        }
        if(!found){
            cout << "Student ID not found" << endl;
        }
    }


    static void disable(vector<Student> list){
        bool found = false;
        cout << "ID of Admin to disable: ";
        string IS;
        cin >> IS;
        cin.ignore();

        for(auto & i : list){
            if(IS == i.id){
                found = true;
                i.status = false;
                cout << "Admin status successfully updated" << endl;
            }
        }
        if(!found){
            cout << "Admin ID not found" << endl;
        }
    }


    
};

#endif //EXAMEN2_STUDENT_H


//  almacenar


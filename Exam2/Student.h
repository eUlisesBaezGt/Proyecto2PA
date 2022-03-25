#ifndef EXAMEN2_STUDENT_H
#define EXAMEN2_STUDENT_H

class Student {

private:
    int id;

public:
    string name;
    string lastName1;
    string lastName2;
    int age;
    char gender;
    bool status;

    void add_student() {
        int id, age;
        string name, lastName1, lastName2;
        cout << " -Register Client- " << endl;
        id = ID_GEN();
        cout << "ID: " << id << endl;
        cout << "Name: ";
        cin >> name;
        cin.ignore();
        cout << "Middle Name: ";
        cin >> lastName1;
        cin.ignore();
        cout << "Last Name: ";
        cin >> lastName2;
        cin.ignore();
        cout << "Age: ";
        cin >> age;
        cin.ignore();
        cout << "Gender (M-F): ";
        cin >> gender;
        cin.ignore();
        system("clear");
    }

    string set_client() 
    {
        return "ID: " + to_string(id) + "\nName: " + name + "\nMiddle Name: " + lastName1 + "\nLast Name: " + lastName2  +"\nAge: "  +
                to_string(age) + "\nGender: " + gender + "\n";
    }


    void store(){

    }


    void enable(vector<Student> list){
        cout << "ID of Student to enable: ";
        int id;
        cin >> id;
        cin.ignore();
        bool found;
        bool found = false;

        for(int i=0; i < list.size() ;i++){
            if(id == list[i].id){
                found = true;
                list[i].status = true;
                cout << "Student status succesfully updated" << endl;
            }
        }
        if(found == false){
            cout << "Student ID not found" << endl;
        }
    }


    void disable(){

    }

    
};

#endif //EXAMEN2_STUDENT_H


#ifndef EXAMEN2_STUDENT_H
#define EXAMEN2_STUDENT_H



#endif //EXAMEN2_STUDENT_H

// 1. Dar de alta, almacenar, deshabilitar y habilitar Estudiantes en el sistema
// Dar de alta ✅

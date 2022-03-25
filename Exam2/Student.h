#ifndef EXAMEN2_STUDENT_H
#define EXAMEN2_STUDENT_H

class Student {
public:
    string name;
    string lastName1;
    string lastName2;
    int age;
    char gender;

    void add_client() {
        int id, age;
        string name, lastName1, lastName2;
        cout << " -Register Client- " << endl;
        id = ID_GEN()
        cout << "ID: " << id << endl;
        cout << "Name: ";
        cin >> name;
        cin.ignore()
        cout << "Middle Name: ";
        cin >> lastName1;
        cin.ignore()
        cout << "Last Name: ";
        cin >> lastName2;
        cin.ignore()
        cout << "Age: ";
        cin >> age;
        cin.ignore()
        cout << "Gender (M-F): ";
        cin >> gender;
        cin.ignore()

        getClient(id, name, lastName1, lastName2, age, gender);
        system("clear");
    }
private:
    int id;
};

void getClient(int _id, string _name, string _lastName1, string _lastName2, int _age, string _gender) {
        this -> id = _id;
        this -> name = _name;
        this -> lastName1 = _lastName1;
        this -> lastName2 = _lastName2;
        this -> age = _age;
        this -> gender = _gender;
    };

#endif //EXAMEN2_STUDENT_H

// 1. almacenar, deshabilitar y habilitar Estudiantes en el sistema

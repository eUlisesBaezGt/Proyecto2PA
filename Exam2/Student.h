#ifndef EXAMEN2_STUDENT_H
#define EXAMEN2_STUDENT_H

class Student {
public:
    string name;
    string lastName1;
    string lastName2;
    int age;
    char gender;

    void alta_cliente() {
        int id, age;
        string name, lastName1, lastName2;
        cout << " -Register Client- " << endl;
        cout << "ID: ";
        cin >> id;
        cout << "Name: ";
        cin >> name;
        cout << "Middle Name: ";
        cin >> lastName1;
        cout << "Last Name: ";
        cin >> lastName2;
        cout << "Age: ";
        cin >> age;
        cout << "Gender: ";
        cin >> gender;

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

// 1. Dar de alta, almacenar, deshabilitar y habilitar Estudiantes en el sistema

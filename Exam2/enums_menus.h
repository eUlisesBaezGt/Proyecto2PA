#ifndef EXAM2_ENUMS_MENUS_H
#define EXAM2_ENUMS_MENUS_H

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

#endif //EXAM2_ENUMS_MENUS_H

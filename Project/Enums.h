#pragma once

enum StudentMenu {
	LogStud = 1,
	AddStud,
	PrAStud,
	ExitStudent
};

enum LoggedStudentMenu {
	DisStudent = 1,
	EnaStudent,
	RegBreakfast,
	RegMeal,
	RegDinner,
	ExitStudentLog
};

enum AdminMenu {
	LogAdm = 1,
	AddAdm,
	PrAAdm,
	ExitAdmin
};

enum LoggedAdminMenu {
	DisAdmin = 1,
	EnaAdmin,
	EdStudCap,
	Cap4Meal,
	ModBlock,
	SeeStudentsBlock,
	ExitAdminLog
};
//
//void HacerArchivo()
//{
//    string filename = "Clientes.csv";
//    ifstream ifile;
//    ifile.open(filename);
//    if (!ifile)
//    {
//        ifile.close();
//        ofstream myFileOutput("./Clientes.csv", ios_base::app);
//        myFileOutput << "id, name, middleName, lastName, age, gender\n";
//        myFileOutput.close();
//    }
//
//    string filename2 = "Admin.csv";
//    ifstream ifile2;
//    ifile2.open(filename2);
//    if (!ifile2)
//    {
//        ifile2.close();
//        ofstream myFileOutput("Admin.csv", ios_base::app);
//        myFileOutput << "id, name, middleName, lastName, age, gender\n";
//        myFileOutput.close();
//    }
//};
//
//void leerStudents(vector <Student>& list)
//{
//    int encontro = -1;
//    string line, colname;
//    vector <string> headers;
//    string value;
//    ifstream myFileInput("Clientes.csv");
//    if (!myFileInput.is_open()) throw runtime_error("Could not open file.");
//    if (myFileInput.good())
//    {
//        // Extract the first line in the file
//        getline(myFileInput, line);
//
//        // Create a stringstream from line
//        stringstream ss(line);
//
//        // Extract each column name
//        while (getline(ss, colname, ',')) {
//            headers.push_back(colname);
//        }
//    }
//    while (getline(myFileInput, line))
//    { 
//        sstringstream ss(line); //MARCA ERROR
//
//        int colIdx = 0;
//        int id;
//        string name;
//        string middleName;
//        string lastName;
//        int age;
//        char gender;
//
//        while (getline(ss, value, ', ')) //MARCA ERROR
//        {
//            switch (colIdx)
//            {
//            case 0:
//                id = stoi(value);
//                break;
//            case 1:
//                name = value;
//                break;
//            case 2:
//                middleName = value;
//                break;
//            case 3:
//                lastName = value;
//                break;
//            case 4:
//                age = stoi(value);
//                break;
//            case 5:
//                //string temp_s(CHAR_LENGTH, value);
//                gender.push_back(value); //MARCA ERRROR
//                break;
//            default:
//                break;
//            }
//        }
//    }
//};
#pragma once

enum studentMenu
{
	LogStud = 1,
	AddStud,
	PrAStud,
	Exitstudent
};

enum LoggedstudentMenu
{
	Disstudent = 1,
	Enastudent,
	RegBreakfast,
	RegMeal,
	RegDinner,
	ExitstudentLog
};

enum AdminMenu
{
	LogAdm = 1,
	AddAdm,
	PrAAdm,
	ExitAdmin
};

enum LoggedAdminMenu
{
	DisAdmin = 1,
	EnaAdmin,
	EdStudCap,
	Cap4Meal,
	ModBlock,
	SeestudentsBlock,
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
//void leerstudents(vector <student>& list)
//{
//    int encontro = -1;
//    string line, colname;
//    vector <string> headers;
//    vector<student> leer_estudiantes;
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
//        stringstream ss(line);
//
//        int colIdx = 0;
//        int id;
//        string name;
//        string middleName;
//        string lastName;
//        int age;
//        char gender;
//
//        while (getline(ss, value, ','))
//        {
//            cout << "Col: " << colIdx << endl;
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
//                gender.push_back(value); //SE NECESITA UN CHAR TO STRING
//                break;
//            default:
//                break;
//            }
//
//
//            // Si el siguiente token es una coma, ignoralo y se mueve al siguiente elemento
//            if (ss.peek() == ',') ss.ignore();
//            colIdx++;
//        }
//        student temp(id, name, middleName, lastName, age, gender);  //CORREGIR ID
//        leer_estudiantes.push_back(temp);
//    }
//    myFileInput.close();
//
//    for (int i = 0; i < leer_estudiantes.size(); i++)
//    {
//        cout << leer_estudiantes[i].id << "," << leer_estudiantes[i].name << "," << leer_estudiantes[i].middleName << "," << leer_estudiantes[i].lastName << "," << leer_estudiantes[i].age << "," << leer_estudiantes[i].gender << endl;
//    }
// };

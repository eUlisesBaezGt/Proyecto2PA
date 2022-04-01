#pragma once

#include <iostream>
#include <cmath>
#include <vector>
#include <string>

#include "Student.h"

using namespace std;

enum ENUMStudentMenu {
	LogStud = 1,
	AddStud,
	PrAStud,
	ExitStudent
};

enum ENUMLoggedStudentMenu {
	DisStudent = 1,
	EnaStudent,
	RegBreakfast,
	RegMeal,
	RegDinner,
	ExitStudentLog
};

enum ENUMAdminMenu {
	LogAdm = 1,
	AddAdm,
	PrAAdm,
	ExitAdmin
};

enum ENUMLoggedAdminMenu {
	DisAdmin = 1,
	EnaAdmin,
	EdStudCap,
	Cap4Meal,
	ModBlock,
	SeeStudentsBlock,
	ExitAdminLog
};

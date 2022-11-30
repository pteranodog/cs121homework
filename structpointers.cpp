//
// Examples of structures with pointers and functions
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

struct date
{
	unsigned int month;
	unsigned int day;
	unsigned int year;
};

struct student_record
	{
		string firstname;
		string lastname;
		date birthdate;
		float gpa;
		double exam;
		double homework;
		float grade;
	};


student_record enter_data_by_value(student_record student);
void enter_data_by_reference(student_record &student);
void compute_grade(student_record &student);
void print_record(student_record student);

int main(void) 
{
	// Varaibles of type student record
	student_record Alice, Bob;

	// Pointers to student_record types
    student_record *pAlice, *pBob;

	// Initialize the pointers
    pAlice = &Alice;
    pBob = &Bob;


	cout << "Enter Student Data for Alice." << endl;
    *pAlice = enter_data_by_value(*pAlice);

	// Compute Grade for Alice.
    compute_grade(*pAlice);

	// Print data record
	cout << "Data Record for Alice" << endl << endl;
    print_record(*pAlice);


	cout << endl  << endl;

	// Use call by reference to input data for Bob
	cout << "Enter Student Data for Bob." << endl;
    enter_data_by_reference(*pBob);

	// Compute Grade for Bob.
    compute_grade(*pBob);


	cout << "Data Record for Bob" << endl << endl;
    print_record(*pBob);

	system("pause");

	// Handling pointers to structs
    student_record *pStudent;
    pStudent = new student_record;
    pStudent->firstname = "John";
    pStudent->lastname = "Doe";
    pStudent->birthdate.month = 1;
    pStudent->birthdate.day = 1;
    pStudent->birthdate.year = 2000;
    
    cout << "Call enter_data_by_value to initialize ptr_Alice" << endl;


	cout << "Data Record for Alice Modified" << endl << endl;


	cout << endl << endl;

	cout << "Call enter_data_by_reference to initialize ptr_student" << endl;


	cout << "Data Record for student" << endl << endl;

	cout << endl << endl;


	cout << endl << endl;
	system("pause");
}

student_record enter_data_by_value(student_record student)
{
    cout << "Enter first and last name: " << endl;
	cin >> student.firstname >> student.lastname;
	cout << "Enter Date of Birth as MM DD YYYY" << endl;
	cin >> student.birthdate.month >> student.birthdate.day >> student.birthdate.year;
	cout << "Enter GPA: ";
	cin >> student.gpa;
	cout << endl;
	cout << "Enter exam average: ";
	cin >> student.exam;
	cout << endl;
	cout << "Enter homework average: ";
	cin >> student.homework;
	cout << endl;

    return student;  // Return filled data record
}


void enter_data_by_reference(student_record &student)
{
    cout << "Enter first and last name: " << endl;
	cin >> student.firstname >> student.lastname;
	cout << "Enter Date of Birth as MM DD YYYY" << endl;
	cin >> student.birthdate.month >> student.birthdate.day >> student.birthdate.year;
	cout << "Enter GPA: ";
	cin >> student.gpa;
	cout << endl;
	cout << "Enter exam average: ";
	cin >> student.exam;
	cout << endl;
	cout << "Enter homework average: ";
	cin >> student.homework;
	cout << endl;

    return; // Nothing returned in call by reference
}


void compute_grade(student_record &student)
{
	cout << "In function compute grade." << endl;
	cout << "Exam = " << student.exam << endl;
	cout << "Homework = " << student.homework << endl;
	student.grade = student.exam /100 * 60 + student.homework /100 * 30 + 10;
	cout << "Grade = " << student.grade << endl;

	return;
}

void print_record(student_record student)
{
    cout << student.firstname << " " << student.lastname << endl;
	cout << "Date of birth " 
		 << setw(3) << student.birthdate.month 
		 << setw(3) << student.birthdate.day 
		 << setw(5)<< student.birthdate.year
		 << endl;
	cout << "GPA: " << student.gpa << endl;
	cout << "Exam: " << student.exam << endl;
	cout << "Homework: " << student.homework << endl;
	cout << "Grade: " << student.grade << endl;
    return;
}

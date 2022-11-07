//
// CS 121 User defined types. Example one - student record.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

enum gradetype {A, B, C, D, F};

struct student_record {
    string firstname;
    string lastname;
    float gpa;
    unsigned int exam;
    unsigned int homework;
    float grade;
    gradetype lettergrade;
};

int main(void) 
{

	student_record student;
	cout << "Enter Student Data for Alice." << endl;
	cout << "First Name: ";
	cin >> student.firstname;
	cout << endl;
	cout << "Last Name: ";
    cin >> student.lastname;
	cout << endl;

	cout << "GPA: ";
    cin >> student.gpa;
	cout << endl;

	cout << "exam: ";
    cin >> student.exam;
	cout << endl;

	cout << "Homework: ";
    cin >> student.homework;

	cout << endl;
    
	// Compute Grade
    student.grade = student.exam * 0.6 + student.homework * 0.4;
    if (student.grade >= 89.5)
        student.lettergrade = A;
    else if (student.grade >= 79.5)
        student.lettergrade = B;
    else if (student.grade >= 69.5)
        student.lettergrade = C;
    else if (student.grade >= 59.5)
        student.lettergrade = D;
    else
        student.lettergrade = F;
	cout << "Data Record for Alice" << endl << endl;

	cout << endl << endl;
	system("pause");
}

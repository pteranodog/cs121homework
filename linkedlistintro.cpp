
//
// Introduction to Linked Lists
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
	unsigned int age;
	string major;
	student_record *link;
};

void enter_data(student_record &student);
void print_data(student_record &student);

int main(void)
{
	unsigned int count = 0;

	// Declare some pointers to student_record types
    student_record *Roger = new student_record;
    student_record *Susan = new student_record;
    enter_data(*Roger);
    Roger->link = NULL;
    enter_data(*Susan);
    Susan->link = NULL;

    Roger->link = Susan;
    
    std::cout << Roger->firstname << " " << Roger->lastname;
    std::cout << Roger->link->firstname << " " << Roger->link->lastname;

	// 1. Create a root node

    

	// 2. Enter the data for the new student.



	// 3. Set the link to NULL;



	// 4. We have to save the entry point so set the root node to this node



	// 5. Enter a loop to make some more nodes

	while (count <= 2)
	{

		// 5. Make a new node



		// 6. Fill the node with data for this student



		// 7. Set the link to NULL



		// 8. Connect the previous node to this one



		// 9. Move the current node pointer to the new node



		count++;
	}

	std::cout << endl << endl;
	// Print out the data on the linked list.
	// Start at the first (root) node

 

	std::system("pause");
	return 0;
}

// Functions

void enter_data(student_record &student)
{
	std::cout << "Enter first and last name." << endl;
	cin >> student.firstname >> student.lastname;
	std::cout << "Enter date of birth as MM DD YYYY." << endl;
	cin >> student.birthdate.month >> student.birthdate.day >> student.birthdate.year;
	std::cout << "Enter age." << endl;
	cin >> student.age;
	std::cout << "Enter major (e.g. CS)." << endl;
	cin >> student.major;

	return;
}

void print_data(student_record &student)
{

	std::cout << "Name:      " << student.firstname << " " << student.lastname << endl;
	std::cout << "Birthdate: " << student.birthdate.month << setw(3) << student.birthdate.day
		 << setw(5) << student.birthdate.year << endl;
	std::cout << "Age:       " << student.age << endl;
	std::cout << "Major:     " << student.major << endl;

	return;
}
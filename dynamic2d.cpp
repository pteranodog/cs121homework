#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#define SKIP2 cout << endl << endl;

using namespace std;

void initialize_1D(unsigned int array_in[], unsigned int elements);
void initialize_2D(unsigned int array[][10], unsigned int rows, unsigned int cols);
void printarray_1D(unsigned array_in[], unsigned int elements);
void printarray_2D(unsigned int array[][10], unsigned int rows, unsigned int cols);

int main()
{

	int j, k;
	int rows = 0, columns = 0;
	unsigned int values[20] = { 0 };
	unsigned int numbers[4][10] = { 0 };

	// Initialize and print values

	cout << "Contents of 1D Array values" << endl;
	initialize_1D(values, 20);
	printarray_1D(values, 20);

	SKIP2

		// Initialize and print values

	cout << "Contents of 2D Array numbers" << endl;
	initialize_2D(numbers, 4, 10);
	printarray_2D(numbers, 4, 10);

	SKIP2

		// system("pause");

		// Dynamic Arrays



		// CASE I
		// Create 4 one-dimensional dynamic arrays

		cout << "Enter number of elements (columns) in each row. " << endl;
	cin >> columns;


	// Initialize the four arrays


	// Print the array contents
	// The int type cast operator is used to get decimal addresses instead of hexadecimal

	SKIP2

		system("pause");

	// Make an array of pointers to unsigned int

	rows = 4;

	cout << "Print Dynamic Array Table CASE 1:" << endl;

	SKIP2

		cout << "Print Dynamic Array Table CASE 2:" << endl;

	SKIP2

		cout << "Print Dynamic Array Table CASE 3:" << endl;

	SKIP2

		cout << endl;
	system("pause");


	return 0;
}

//
// Initialize a one dimensional array with random positive integers 
//
void initialize_1D(unsigned int array_in[], unsigned int elements)
{
	unsigned int k;

	for (k = 0; k < elements; k++)
	{
		array_in[k] = rand() % 100;
	}

}
//
// Initialize a two dimensional array with random positive integers 
// The actual array passed to the function must be declared with 10 columns
//

void initialize_2D(unsigned int array[][10], unsigned int rows, unsigned int cols)
{
	unsigned int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			array[i][j] = rand() % 100;
		}
	}
}

//
// Print the contents of a one dimensional array of unsigned integers
//
void printarray_1D(unsigned array_in[], unsigned int elements)
{
	unsigned int k;
	cout << "VARIABLE    CONTENTS" << endl;
	for (k = 0; k < elements; k++)
	{
		cout << "array[" << setw(2) << k << "]" << setw(8) << array_in[k] << endl
			 << setw(14) << (int)&array_in[k] << endl;
	}
	cout << endl;
	return;
}
//
// Print the contents of a two dimensional array
// The actual array passed to the function must be declared with 10 columns
//
void printarray_2D(unsigned int array[][10], unsigned int rows, unsigned int cols)
{
	unsigned int j, k;
	cout << "VARIABLE    CONTENTS" << endl;
	for (j = 0; j < rows; j++)
	{
		for (k = 0; k < cols; k++) {
			cout << "array[" << j << "][" << k << "]" << setw(5) << array[j][k] << endl;
		}
		cout << endl;
	}
	cout << endl;
	return;
}
//
// Print the contents of a two dimensional array with variable columns
// The actual array passed to the function must contain pointers to unsigned int
//


//
// Print the contents of a two dimensional array with variable rows and columns
// The actual array passed to the function must contain pointers to unsigned int
// 
//
// CS 121 Recursive functions - factorial
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;
long int factorial(unsigned int number);
long int rec_factorial(unsigned int number);
long int rec_factorial_alt(unsigned int number);

int main(void) 
{

	long int nfact;
	unsigned int k, number;

	cout << "Enter a value for number" << endl;
	cin >> number;


	cout << "Calling iterative function factorial(" << number << ")" << endl;
	nfact = factorial(number);
	cout << "Nfactorial = " << nfact << endl;
	system("pause");

	cout << endl << endl;
	cout << "Calling recursive function rec_factorial(" << number << ")" << endl;
	nfact = rec_factorial(number);
	cout << "Nfactorial = " << nfact << endl;
	system("pause");

    cout << endl << endl;
	cout << "Calling alternate recursive function rec_factorial_alt(" << number << ")" << endl;
	nfact = rec_factorial_alt(number);
	cout << "Nfactorial = " << nfact;


	cout << endl << endl;
	system("pause");
}

long int factorial(unsigned int number)
{
	unsigned int k;
	long int nfact = 1;

	for (k = 1; k <= number; k++)
		nfact = nfact*k;

	return nfact;
}


long int rec_factorial(unsigned int number)
{
	long int nfact = 1;
	cout << setw(7 - number) << " " << "Entering rec_factorial with number = " << number;
//	if (number - 1 > 0)
//		cout << " * " << number - 1 << endl;
//	else
		cout << endl;


	if (number == 1)
	{
		cout << setw(7 - number) << " " <<  "Returning 1" << endl;
		return 1;
	}
	else
	{
		nfact = number * rec_factorial(number - 1);
		cout << setw(7 - number) << " " << "Returning " << nfact << endl;
		return nfact;
	}

}

long int rec_factorial_alt(unsigned int number)
{
	long int nfact = 1;

	cout << setw(7 - number) << " " << "Entering rec_factorial_alt with number = " << number;
//	if (number - 1 > 0)
//		cout << " * " << number - 1 << endl;
//	else
		cout << endl;

	if (number > 1 )
	{
		nfact = number * rec_factorial(number - 1);
	}

    cout << setw(7 - number) << " " << "Returning " << nfact << endl;
	return nfact;
}
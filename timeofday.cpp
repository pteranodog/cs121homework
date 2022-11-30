//
// CS 121 Textbook Example of a Class
//     Log out next time :)

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// Create Class timeofday here
class timeofday {
    public:
        // Contstructors
        timeofday();
        timeofday(int inithours, int initminutes, int initseconds);
        // Methods (sometimes called "member functions")
        timeofday increment();
        void write();
        bool equal(timeofday othertime);
    private:
        int hours, minutes, seconds;
};

int main(void) 
{

	// Instantiate a couple of objects of type timeofday

    timeofday time1(5,30,0);
    timeofday time2;
	
	// Perform some operations with the objects
	// Write out the times time1 and time2

    time1.write();
    time2.write();

	// Compare the times time1 and time2 for equality


	// Make the times equal and do the operations again



	// Increment time2 and compare again



	// Instantiate a time near end of day





	// Increment the time by one second in a loop 




	cout << endl << endl;
	system("pause");
}

// ----------------------------------------------------------------- //
// Write the Code for the Member Functions here
// ----------------------------------------------------------------- //

// Function timeofday - This is a constructor

timeofday::timeofday() {
    hours = 0;
    minutes = 0;
    seconds = 0;
}

timeofday::timeofday(int inithours, int initminutes, int initseconds)
{
    hours = inithours;
    minutes = initminutes;
    seconds = initseconds;
}

// Function timeof day increment

void timeofday::increment() {
    seconds++;
    if (seconds > 59) {
        seconds = 0;
        minutes++;
        if (minutes > 59) {
            minutes = 0;
            hours++;
            if (hours > 23) {
                hours = 0;
            }
        }
    }
}

// Function write

void timeofday::write() {
    cout << setfill('0') << setw(2) << hours << ":" << setw(2) << minutes << ":" << setw(2) << seconds << endl;
}

// Function test Equal

bool timeofday::equal(timeofday othertime) {
    bool value = false;
    if (hours == othertime.hours && minutes == othertime.minutes && seconds == othertime.seconds) {
        value = true;
    }
    return value;
}

// Function Test Less Than

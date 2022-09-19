//
// Program to read and process weather station data 
// Data is input one full line at a time and then processed with
// string manipulation functions
//
// It demonstrates fstream, iomanip, file open, file read, file close,
// getline, eof, substr, at, lenght and find.
//
// Actual weather station data is employed
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main(void)
{
	// Variables

	string dataline = "";
	string station = "";

	string tmax_s = "", tmin_s = "";

	unsigned int pos_station_name = 0;
	unsigned int pos_date = 0;	
	unsigned int pos_tmax = 0;
	unsigned int pos_tmin = 0;
	unsigned int bad_records = 0;

	float tmax = 0, tmin = 0;

	ifstream infile;
	ofstream outfile;

	cout << "WEATHER STATION DATA" << endl << endl;
	cout << "Open the data file." << endl << endl;
	infile.open("datafiles/AL_Weather_Station.txt");

    if (!infile) 
	{
        cout << "Unable to open the input file. " << endl;
        system ("pause");
        return(1);
	}
	else
	{
	    cout << "Data file opened." << endl;
	}

    outfile.open("datafiles/filteredweatherdata.txt");
    
    if (!outfile) 
	{
        cout << "Unable to open the output file. " << endl;
        system ("pause");
        return(1);
	}
	else
	{
	    cout << "Output file opened." << endl;
	}

	cout << "Use the first line of the file to find the column positions. " << endl;


	// Use headers to fine max and min temp columns
    getline(infile, dataline);
    pos_tmax = dataline.find("TMAX");
    pos_tmin = dataline.find("TMIN");
    pos_date = dataline.find("DATE");
    pos_station_name = dataline.find("STATION_NAME");
    if (!(pos_tmax <= dataline.length() || pos_tmin <= dataline.length() || pos_date <= dataline.length() || pos_station_name <= dataline.length())) {
        cout << "Data format not properly found." << endl;
        system("pause");
        return 1;
    }


	cout << "Read the second line from the file. " << endl;

	// Now process the data records from the file


	while (!infile.eof())
	{


	} // End While 

	// Close the files
	infile.close();
	outfile.close();

	cout << "New file created with bad records filtered out. " << endl;
	cout << "There were " << bad_records << " filtered out." << endl;

	cout << "\n\n";
	system("pause");
	return 0;
}
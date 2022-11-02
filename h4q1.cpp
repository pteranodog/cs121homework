#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

int main(void) {
	ifstream infile;
	ofstream outfile;
	infile.open("datafiles/AL_Weather_Station.txt");
	if (!infile)
	{
		cout << "Unable to open the input file. " << endl;
		system("pause");
		return 1;
	}
	outfile.open("datafiles/Filtered_AL_Weather_Station.txt");
	if (!outfile)
	{
		cout << "Unable to open the output file. " << endl;
		system("pause");
		return 2;
	}
	
    string titleLine;
    string widthLine;
    getline(infile, titleLine);
    getline(infile, widthLine);
    outfile << titleLine << endl;
    outfile << widthLine << endl;

    int precip_pos = titleLine.find("PRCP");
    int precip_width = widthLine.find(" ",precip_pos)-precip_pos;
    int tmax_pos = titleLine.find("TMAX");
    int tmax_width = widthLine.find(" ",tmax_pos)-tmax_pos;
    int tmin_pos = titleLine.find("TMIN");
    int tmin_width = widthLine.find(" ",tmin_pos)-tmin_pos;

    string dataline;
    while (!infile.eof()) {
        getline(infile, dataline);
        if (stod(dataline.substr(precip_pos,precip_width)) != -9999 &&
            stod(dataline.substr(tmax_pos,tmax_width)) != -9999 &&
            stod(dataline.substr(tmin_pos,tmin_width)) != -9999)
            outfile << dataline << endl;
    }

    infile.close();
    outfile.close();
	system("pause");
	return 0;
}
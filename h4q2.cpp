#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

float cToF(float celsius) {
    return celsius * 9 / 5 + 32;
}

int main(void) {
	ifstream infile;
	ofstream outfile;
	infile.open("datafiles/Filtered_AL_Weather_Station.txt");
	if (!infile)
	{
		cout << "Unable to open the input file. " << endl;
		system("pause");
		return 1;
	}
	outfile.open("datafiles/weather_station_five_column.txt");
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

    int station_name_pos = titleLine.find("STATION_NAME");
    int station_name_width = widthLine.find(" ",station_name_pos)-station_name_pos;
    int date_pos = titleLine.find("DATE");
    int date_width = widthLine.find(" ",date_pos)-date_pos;
    int precip_pos = titleLine.find("PRCP");
    int precip_width = widthLine.find(" ",precip_pos)-precip_pos;
    int tmax_pos = titleLine.find("TMAX");
    int tmax_width = widthLine.find(" ",tmax_pos)-tmax_pos;
    int tmin_pos = titleLine.find("TMIN");
    int tmin_width = widthLine.find(" ",tmin_pos)-tmin_pos;

    outfile << setw(station_name_width + 1) << left << "STATION_NAME" << setw(date_width + 1) << "DATE" << setw(precip_width + 1) << "PRCP" << setw(tmax_width + 1) << "TMAX" << setw(tmin_width + 1) << "TMIN" << " " << endl;
    outfile << setfill('-') << setw(station_name_width) << left << "-" << " " << setw(date_width) << "-" << " " << setw(precip_width) << "-" << " " << setw(tmax_width) << "-" << " " << setw(tmin_width) << "-" << endl;

    string dataline;
    outfile << setfill(' ');
    while (!infile.eof()) {
        getline(infile, dataline);
        outfile << setw(station_name_width + 1) << dataline.substr(station_name_pos,station_name_width) << setw(date_width + 1) << dataline.substr(date_pos,date_width) << setw(precip_width + 1) << dataline.substr(precip_pos,precip_width) << setw(tmax_width + 1) << cToF(stof(dataline.substr(tmax_pos,tmax_width))/10.0) << setw(tmin_width + 1) << cToF(stof(dataline.substr(tmin_pos,tmin_width))/10.0) << endl;
    }

    infile.close();
    outfile.close();
	system("pause");
	return 0;
}
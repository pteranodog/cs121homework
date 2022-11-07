#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;
int getMaxIndex(float array[], int size, int start = -1);
int getMinIndex(float array[], int size, int start = -1);

int main(void) {
	ifstream infile;
	ofstream outfile;
	infile.open("datafiles/weather_station_five_column.txt");
	if (!infile)
	{
		cout << "Unable to open the input file. " << endl;
		system("pause");
		return 1;
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
    int tmin_width = widthLine.size()-tmin_pos;
    
    string dataline;
    int number_of_lines = 0;
    while (!infile.eof()) {
        getline(infile, dataline);
        number_of_lines++;
    }
    number_of_lines--;
    infile.clear();
    infile.seekg(0, ios::beg);
    
    getline(infile, titleLine);
    getline(infile, widthLine);
    
    string station_name[number_of_lines];
    string date[number_of_lines];
    float precip[number_of_lines];
    float tmax[number_of_lines];
    float tmin[number_of_lines];

    for (int i = 0; i < number_of_lines; i++) {
        getline(infile, dataline);
        station_name[i] = dataline.substr(station_name_pos,station_name_width);
        
        station_name[i] = station_name[i].substr(station_name[i].find_first_not_of(" "));
        // found the very helpful find_first_not_of function on the C++ documentation

        date[i] = dataline.substr(date_pos,date_width);
        
        precip[i] = stof(dataline.substr(precip_pos,precip_width));
        
        tmax[i] = stof(dataline.substr(tmax_pos,tmax_width));
        
        tmin[i] = stof(dataline.substr(tmin_pos,tmin_width));

    }
    int currentMaxIndex = getMaxIndex(tmax, number_of_lines);
    int currentMinIndex = getMinIndex(tmin, number_of_lines);

    cout << "The hottest temperature was " << tmax[currentMaxIndex] << " degrees at " << station_name[currentMaxIndex] << endl;
    cout << "The coldest temperature was " << tmin[currentMinIndex] << " degrees at " << station_name[currentMinIndex] << endl;

    while (tmax[currentMaxIndex] == tmax[getMaxIndex(tmax, number_of_lines, currentMaxIndex)]) {
        currentMaxIndex = getMaxIndex(tmax, number_of_lines, currentMaxIndex);
        cout << "The temperature also reached " << tmax[currentMaxIndex] << " degrees at " << station_name[currentMaxIndex] << endl;
    }
    while (tmin[currentMinIndex] == tmin[getMinIndex(tmin, number_of_lines, currentMinIndex)]) {
        currentMinIndex = getMinIndex(tmin, number_of_lines, currentMinIndex);
        cout << "The temperature also reached " << tmin[currentMinIndex] << " degrees at " << station_name[currentMinIndex] << endl;
    }


    infile.close();
	system("pause");
	return 0;
}

int getMaxIndex(float array[], int size, int start) {
    int maxIndex = start + 1;
    for (int i = start + 1; i < size; i++) {
        if (array[i] > array[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

int getMinIndex(float array[], int size, int start) {
    int minIndex = start + 1;
    for (int i = start + 1; i < size; i++) {
        if (array[i] < array[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}


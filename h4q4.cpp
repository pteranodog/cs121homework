#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

int getMaxIndex(float array[], int size, int start = -1) {
    int maxIndex = start + 1;
    for (int i = start + 1; i < size; i++) {
        if (array[i] > array[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

int getMinIndex(float array[], int size, int start = -1) {
    int minIndex = start + 1;
    for (int i = start + 1; i < size; i++) {
        if (array[i] < array[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}


float getAverage(float array[], int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum / size;
}

float getMaxByStation(float array[], string stations[], string dates[], int size, string station, string startDateStr, string endDateStr) {
    int count = 0;
    int startDate = stoi(startDateStr);
    int endDate = stoi(endDateStr);
    for (int i = 0; i < size; i++) {
        if ((stations[i] == station || stations[i] == station + " AL US") && stoi(dates[i]) >= startDate && stoi(dates[i]) <= endDate) {
            count++;
        }
    }
    float stationArray[count];
    int index = 0;
    for (int i = 0; i < size; i++) {
        if ((stations[i] == station || stations[i] == station + " AL US") && stoi(dates[i]) >= startDate && stoi(dates[i]) <= endDate) {
            stationArray[index] = array[i];
            index++;
        }
    }
    return stationArray[getMaxIndex(stationArray, count)];
}

float getMinByStation(float array[], string stations[], string dates[], int size, string station, string startDateStr, string endDateStr) {
    int count = 0;
    int startDate = stoi(startDateStr);
    int endDate = stoi(endDateStr);
    for (int i = 0; i < size; i++) {
        if ((stations[i] == station || stations[i] == station + " AL US") && stoi(dates[i]) >= startDate && stoi(dates[i]) <= endDate) {
            count++;
        }
    }
    float stationArray[count];
    int index = 0;
    for (int i = 0; i < size; i++) {
        if ((stations[i] == station || stations[i] == station + " AL US") && stoi(dates[i]) >= startDate && stoi(dates[i]) <= endDate) {
            stationArray[index] = array[i];
            index++;
        }
    }
    return stationArray[getMinIndex(stationArray, count)];
}


float getAverageByStation(float array[], string dates[], string stations[], int size, string station, string startDateStr, string endDateStr) {
    float sum = 0;
    int count = 0;
    int startDate = stoi(startDateStr);
    int endDate = stoi(endDateStr);
    for (int i = 0; i < size; i++) {
        if ((stations[i] == station || stations[i] == station + " AL US") && stoi(dates[i]) >= startDate && stoi(dates[i]) <= endDate) {
            sum += array[i];
            count++;
        }
    }
    return sum / count;
}

int countMatches(string array[], int size, string match) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] == match) {
            count++;
        }
    }
    return count;
}

float totalOverDates(string dateArray[], float totalArray[], int size, string startDateStr, string endDateStr) {
    float sum = 0;
    int startDate = stoi(startDateStr);
    int endDate = stoi(endDateStr);
    for (int i = 0; i < size; i++) {
        if (stoi(dateArray[i]) >= startDate && stoi(dateArray[i]) <= endDate) {
            sum += totalArray[i];
        }
    }
    return sum;
}

float totalOverDatesByStation(string dateArray[], float totalArray[], int size, string startDateStr, string endDateStr, string station_name[], string station) {
    float sum = 0;
    int startDate = stoi(startDateStr);
    int endDate = stoi(endDateStr);
    for (int i = 0; i < size; i++) {
        if (stoi(dateArray[i]) >= startDate && stoi(dateArray[i]) <= endDate && station_name[i].find(station) != -1) {
            sum += totalArray[i];
        }
    }
    return sum;
}

string dateFromParts(string day, string month, string year) {
    return year + month + day;
}

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
    char choice;
    do {
        cout << "What would you like to do?" << endl;
        cout << "A. Total precipitation for a given day" << endl;
        cout << "B. Total precipitation for a given date range" << endl;
        cout << "C. Total precipitation by station for all of March" << endl;
        cout << "D. Temperature extremes and average by station" << endl;
        cout << "E. Temperature extremes and average by station for a given date range" << endl;
        cout << "F. Exit" << endl;
        
        
        cin >> choice;

        if (choice == 'A' || choice == 'a') {
            cout << "Enter a date in MM DD YYYY format: ";
            string day = "";
            string month = "";
            string year = "";
            cin >> month >> day >> year;
            string dateStr = dateFromParts(day, month, year);
            float total = totalOverDates(date, precip, number_of_lines, dateStr, dateStr);
            cout << "Total precipitation: " << total << endl;
        }
        else if (choice == 'B' || choice == 'b') {
            cout << "Enter a start date in MM DD YYYY format: ";
            string day = "";
            string month = "";
            string year = "";
            cin >> month >> day >> year;
            string startDateStr = dateFromParts(day, month, year);
            cout << "Enter an end date in MM DD YYYY format: ";
            cin >> month >> day >> year;
            string endDateStr = dateFromParts(day, month, year);
            float total = totalOverDates(date, precip, number_of_lines, startDateStr, endDateStr);
            cout << "Total precipitation: " << total << endl;
        }
        else if (choice == 'C' || choice == 'c') {
            string stationName = "";
            cout << "Enter a station name: ";
            cin >> stationName;
            float total = totalOverDatesByStation(date, precip, number_of_lines, "20180301", "20180331", station_name, stationName);
            cout << "Total precipitation: " << total << endl;
        }
        else if (choice == 'D' || choice == 'd') {
            string stationName = "";
            cout << "Enter a station name: ";
            cin >> stationName;
            string restOfStationName = "";
            getline(cin, restOfStationName);
            stationName += restOfStationName;
            float maxT = getMaxByStation(tmax, station_name, date, number_of_lines, stationName, "20180301", "20180331");
            float minT = getMinByStation(tmin, station_name, date, number_of_lines, stationName, "20180301", "20180331");
            float avgTMax = getAverageByStation(tmax, date, station_name, number_of_lines, stationName, "20180301", "20180331");
            float avgTMin = getAverageByStation(tmin, date, station_name, number_of_lines, stationName, "20180301", "20180331");
            cout << "Max temperature: " << maxT << endl;
            cout << "Min temperature: " << minT << endl;
            cout << "Average max temperature: " << avgTMax << endl;
            cout << "Average min temperature: " << avgTMin << endl;
        }
        else if (choice == 'E' || choice == 'e') {
            string stationName = "";
            cout << "Enter a station name: ";
            cin >> stationName;
            string restOfStationName = "";
            getline(cin, restOfStationName);
            stationName += restOfStationName;
            cout << "Enter a start date in MM DD YYYY format: ";
            string day = "";
            string month = "";
            string year = "";
            cin >> month >> day >> year;
            string startDateStr = dateFromParts(day, month, year);
            cout << "Enter an end date in MM DD YYYY format: ";
            cin >> month >> day >> year;
            string endDateStr = dateFromParts(day, month, year);
            float maxT = getMaxByStation(tmax, station_name, date, number_of_lines, stationName, startDateStr, endDateStr);
            float minT = getMinByStation(tmin, station_name, date, number_of_lines, stationName, startDateStr, endDateStr);
            float avgTMax = getAverageByStation(tmax, date, station_name, number_of_lines, stationName, startDateStr, endDateStr);
            float avgTMin = getAverageByStation(tmin, date, station_name, number_of_lines, stationName, startDateStr, endDateStr);
            cout << "Max temperature: " << maxT << endl;
            cout << "Min temperature: " << minT << endl;
            cout << "Average max temperature: " << avgTMax << endl;
            cout << "Average min temperature: " << avgTMin << endl;
        }
        else if (choice == 'F' || choice == 'f') {
            continue;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
        system("pause");
    } while (choice != 'F' && choice != 'f');


    infile.close();
	system("pause");
	return 0;
}
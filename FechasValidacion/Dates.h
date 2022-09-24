#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Date {
private:
	string date;
	unsigned int year, month, day;
	string dateInString;
public:
	Date(string);
	string getDate();
	void setYear(int y);
	void setMonth(int m);
	void setDay(int d);
	int getYear();
	int getMonth();
	int getDay();
	void valInput();
	void separate(string date);
	void YeartoInt(string year);
	void MonthtoInt(string month);
	void DaytoInt(string day);
	bool isNumber(string n);
	void validate();
	int valYear();
	bool leap_year(int _y);
	int valMonth();
	bool valDay(bool y, int m);

	operator const char* () {
		ostringstream formattedDate;
		formattedDate << month << "-" << day << "-" << year;
		dateInString = formattedDate.str();
		return dateInString.c_str();
	}
};
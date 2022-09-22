#pragma once
#include <iostream>
#include <string>
using namespace std;

class Date {
private:
	string date;
	unsigned int year, month, day;
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
};
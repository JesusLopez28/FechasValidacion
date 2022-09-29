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

	void addDays(int nDaysToAdd) {
		if (day != NULL) {
			day += nDaysToAdd;
			bool l_year = leap_year(year);

			switch (month) {
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				if (day > 31) {
					addMonths(day / 31);
					day %= 31;
				}
				break;

			case 4:
			case 6:
			case 9:
			case 11:
				if (day > 30) {
					addMonths(day / 30);
					day %= 30;
				}
				break;

			case 2:
				if (l_year == true) {
					if (day > 29) {
						addMonths(day / 29);
						day %= 29;
					}
				}
				else {
					if (day > 28) {
						addMonths(day / 28);
						day %= 28;
					}
				}
				break;
			}
		}
	}

	void addMonths(int nMonthsToAdd) {
		if (month != NULL) {
			month += nMonthsToAdd;
			if (month > 12) {
				addYears(month / 12);
				month %= 12;
			}
		}
	}

	void addYears(int nYearsToAdd) {
		if (year != NULL) {
			year += nYearsToAdd;
		}
	}

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

	bool validate();

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

	Date& operator ++() {
		addDays(1);
		return *this;
	}
};
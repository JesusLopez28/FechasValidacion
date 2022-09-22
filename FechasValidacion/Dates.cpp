#include <iostream>
#include <string> 
#include "Dates.h"
using namespace std;

Date::Date(string d){
	this->date = d;
}

string Date::getDate(){
	return date;
}

void Date::setYear(int y){
	year = y;
}

void Date::setMonth(int m){
	month = m;
}

void Date::setDay(int d){
	day = d;
}

int Date::getYear(){
	return year;
}

int Date::getMonth(){
	return month;
}

int Date::getDay(){
	return day;
}

void Date::valInput(){
	string input = getDate();
	int size = input.size(), i;
	if (size == 10) {
		separate(input);
	}
	else {
		cout << "Fecha invalida." << endl;
	}
}

void Date::separate(string date){
	size_t pos = 0;
	string year, month, day;
	string d = date, delimiter = "/", token="";
	while ((pos = d.find(delimiter)) != string::npos) { 
		token = d.substr(0, pos); 
		if (year.empty()){
			year = token;
		}
		else {
			month = token;
		}
		d.erase(0, pos + delimiter.length());
		day = d;
	}
	YeartoInt(year);
	MonthtoInt(month);
	DaytoInt(day);
	validate();
}

void Date::YeartoInt(string year){
	string y = year;
	int int_year;
	if (isNumber(y) == true) {
		int_year = stoi(y);
		setYear(int_year);
	}
	else {
		cout << "Fecha invalida." << endl;
	}
}

void Date::MonthtoInt(string month){
	string m = month;
	int int_month;
	if (isNumber(m) == true) {
		int_month = stoi(m);
		setMonth(int_month);
	}
	else {
		cout << "Fecha invalida." << endl;
	}
}

void Date::DaytoInt(string day){
	string d = day;
	int int_day;
	if (isNumber(d) == true) {
		int_day = stoi(d);
		setDay(int_day);
	}
	else {
		cout << "Fecha invalida." << endl;
	}
}

bool Date::isNumber(string n){
	for (char const& c : n) {
		if (isdigit(c) == 0) return false;
	}
	return true;
}

void Date::validate(){
	int year, month, day;
	year = getYear();
	month = getMonth();
	day = getDay();
	//system("cls");
	//cout << year << "/" << month << "/" << day << endl;
}
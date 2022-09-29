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
	int size = input.size();
	if (size == 10) {
		separate(input);
	}
	else {
		cout << "Entrada invalida, deben ser solo 10 caracteres AAAA/MM/DD." << endl;
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
		setYear(NULL);
		cout << "Anio invalido." << endl;
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
		cout << "Mes invalido." << endl;
		setMonth(NULL);
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
		cout << "Dia invalido." << endl;
		setDay(NULL);
	}
}

bool Date::isNumber(string n){
	for (char const& c : n) {
		if (isdigit(c) == 0) return false;
	}
	return true;
}

bool Date::validate(){
	int year = valYear(), month = valMonth();
	bool l_year;
	if (month == 0 || year == 0) {
		cout << "Mes o anio invalidos." << endl;
	}
	else {
		l_year = leap_year(year);
		if (valDay(l_year, month) == true) {
			return true;
		}
		else {		
			return false;
		}
	}
}

int Date::valYear(){
	int year = getYear();
	if (year == 0) {
		return 0;
	}
	else {
		return year;
	}
}

bool Date::leap_year(int _y){
	int year = _y;
	bool leap_year = false;

	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		leap_year = true;
	}
	else {
		leap_year = false;
	}
	return leap_year;
}

int Date::valMonth() {
	int month = getMonth();
	if (month >= 1 && month <= 12) {
		return month;
	}
	else {
		return 0;
	}
}

bool Date::valDay(bool y, int m){
	int month = m, day = getDay();
	bool ly = y, validation = false;

	switch (month){
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (day >= 1 && day <= 31) {
			validation = true;
		}else validation = false;
		break;

	case 4:
	case 6:
	case 9:
	case 11:
		if (day >= 1 && day <= 30) {
			validation = true;
		}
		else validation = false;
		break;
	
	case 2:
		if (ly == true) {
			if (day >= 1 && day <= 29) {
				validation = true;
			}
			else validation = false;
		}
		else {
			if (day >= 1 && day <= 28) {
				validation = true;
			}
			else validation = false;
		}
		break;
	}

	return validation;
}
#pragma once
#include <iostream>
#include <regex> 
#include <time.h>
#include <stdlib.h> 
#include "DateException.h"
using namespace std;


class Date
{
	int day;
	int month;
	int year;
public:
	Date();
	Date(int day, int month, int year);
	Date(Date& date);
	Date(string date);
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	int getDay();
	int getMonth();
	int getYear();
	bool isTillToday();
	friend ostream& operator << (ostream& out, Date& date);
	friend istream& operator >> (istream& in, Date& date);
	friend void isValidDate(int day, int month, int year);
	bool operator == (Date& date);
	bool operator < (Date& date);
	bool operator <= (Date& date);
	bool operator > (Date& date);
	bool operator >= (Date& date);
	Date& operator = (string date);
};


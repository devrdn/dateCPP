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

	void isValidDate();


public:
	Date();
	Date(int day, int month, int year);
	Date(Date& date);
	Date(string date);
	bool isTillToday();
	friend ostream& operator << (ostream& out, Date& date);
	bool operator == (Date& date);
	bool operator < (Date& date);
	bool operator <= (Date& date);
	bool operator > (Date& date);
	bool operator >= (Date& date);

};


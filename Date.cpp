#include "Date.h"

const int MIN_Y = 1900;
const int MAX_Y = 2060;

Date::Date()
{
	this->day = 01;
	this->month = 01;
	this->year = MIN_Y;
}

Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

Date::Date(Date& date)
{
	this->day = date.day;
	this->month = date.day;
	this->year = date.day;
}


void isValidDate(int day, int month, int year)
{
	if (day <= 0 || day > 31)
		throw DateException(1);

	else if (month <= 0 || month > 12)
		throw DateException(2);

	else if (year < MIN_Y || year > MAX_Y)
		throw DateException(3);

	else if (day == 31) {
		if ((month <= 7 && month % 2 == 0) || (month >= 8 && month % 2 != 0))
			throw DateException(5);
	}

	else if (month == 2) {
		if (day == 29 && year % 4 != 0)
			throw DateException(5);
		else if (day == 30 || day == 31)
			throw DateException(5);
	}
}

Date::Date(string date)
{
	cmatch cdate;
	regex regexp("([\\d]{1,2})\.([\\d]{1,2})\.([\\d]{1,4})");
	try {
		if (!regex_match(date.c_str(), cdate, regexp))
			throw DateException(4);
	}
	catch (DateException& ex) {
		cout << "Error(" << ex.getErrorNumber() << "): " << ex.getError() << ".";
		exit(4);
	}
	this->day = atoi(cdate[1].str().c_str());
	this->month = atoi(cdate[2].str().c_str());
	this->year = atoi(cdate[3].str().c_str());
	try {
		isValidDate(this->day, this->month, this->year);
	}
	catch (DateException& ex) {
		cout << "Error(" << ex.getErrorNumber() << "): " << ex.getError() << ".";
		exit(0);
	}
}

void Date::setDay(int day)
{
	try {
		isValidDate(day, this->month, this->year);
	}
	catch (DateException &ex) {
		cout << "Error(" << ex.getErrorNumber() << "): " << ex.getError() << ".";
		return;
	}
	this->day = day;
}

void Date::setMonth(int month)
{
	try {
		isValidDate(this->day, month, this->year);
	}
	catch (DateException& ex) {
		cout << "Error(" << ex.getErrorNumber() << "): " << ex.getError() << ".";
		return;
	}
	this->month = month;
}

void Date::setYear(int year)
{
	try {
		isValidDate(this->day, this->month, year);
	}
	catch (DateException& ex) {
		cout << "Error(" << ex.getErrorNumber() << "): " << ex.getError() << ".";
		return;
	}
	this->year = year;
}

int Date::getDay()
{
	return this->day;
}

int Date::getMonth()
{
	return this->month;
}

int Date::getYear()
{
	return this->year;
}

bool Date::isTillToday()
{
	Date t_date;
	time_t current_date = time(0);
	struct tm newtime;
	localtime_s(&newtime, &current_date);
	t_date.year = 1900 + newtime.tm_year;
	t_date.month = 1 + newtime.tm_mon;
	t_date.day = newtime.tm_mday;
	if (*this <= t_date)
		return true;
	else
		return false;
}

bool Date::operator==(Date& date)
{
	if (this->year == date.year && this->month == date.month && this->day == date.day) {
		return true;
	}
	return false;
}

bool Date::operator<(Date& date)
{
	if (this->year < date.year) {
		return true;
	}
	else if (this->year == date.year) {
		if (this->month < date.month) {
			return true;
		}
		else if (this->month = date.month) {
			if (this->day < date.day) {
				return true;
			}
		}
	}
	return false;
}

bool Date::operator<=(Date& date)
{
	if (*this < date || *this == date) {
		return true;
	}
	return false;
}

bool Date::operator>(Date& date)
{
	if (this->year > date.year) {
		return true;
	}
	else if (this->year == date.year) {
		if (this->month > date.month) {
			return true;
		}
		else if (this->month = date.month) {
			if (this->day > date.day) {
				return true;
			}
		}
	}
	return false;
}

bool Date::operator>=(Date& date)
{
	if (*this > date || *this == date) {
		return true;
	}
	return false;
}

Date& Date::operator==(string date)
{
	Date t_date(date);
	return t_date;
}


ostream& operator<<(ostream& out, Date& date)
{
	return out << "Date{ " << date.day << "." << date.month << "." << date.year << " }";
}

istream& operator>>(istream& in, Date& date)
{
	string t_date;
	in >> t_date;
	date = Date(t_date);
	return in;
	
}




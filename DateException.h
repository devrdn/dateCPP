#pragma once
#include <iostream>
#include <string>
using namespace std;
class DateException
{
	int error;
	string m_error;

public:
	DateException(int a);

	const int getErrorNumber() {
		return error;
	}

	const char* getError() {
		return m_error.c_str();
	}
};

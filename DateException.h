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

	const int getErrorNumber();

	const char* getError();
};

#include "DateException.h"

DateException::DateException(int a)
{
	error = a;
	switch (a) {
	case 1:
		m_error = "invalid day";
		break;
	case 2:
		m_error = "invalid month";
		break;
	case 3:
		m_error = "invalid year";
		break;
	case 4:
		m_error = "invalid date format";
		break;
	case 5:
		m_error = "nonexistent date";
		break;
	}
}

const int DateException::getErrorNumber()
{
	return error;
}

const char* DateException::getError()
{
	return m_error.c_str();
}

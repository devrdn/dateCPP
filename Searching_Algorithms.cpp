#include <iostream>
#include "Date.h"
int main()
{

	// Date
	Date d1(19, 01, 2022);
	Date d2(19, 01, 2022);
	Date d3("ff0.02.2022");
	cout << d1 << endl << d2 << endl << d3;
}

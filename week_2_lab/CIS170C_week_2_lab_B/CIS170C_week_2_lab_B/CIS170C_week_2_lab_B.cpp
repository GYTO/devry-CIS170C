// ---------------------------------------------------------------
// Programming Assignment:	LAB1A
// Developer:			    Roman Kovtun
// Date Written:			03/09/2018
// Purpose:					Calories Burned 
// ---------------------------------------------------------------


#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	double calPerMin = 3.9, burnedOnTreadmill;

	for (int i = 10; i <= 30; i = i + 5) {

		burnedOnTreadmill = i * calPerMin;

		cout << burnedOnTreadmill << " calories were burned after " << i << " minutes." << endl;
	}

	system("pause");
}


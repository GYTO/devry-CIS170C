// ---------------------------------------------------------------
// Programming Assignment:	LAB2A
// Developer:			    Roman Kovtun
// Date Written:			03/09/2018
// Purpose:					Determine Smallest Number
// ---------------------------------------------------------------

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	double num1, num2, smallestNum;

	cout << "Please enter a numeric value: ";
	cin >> num1;
	cout << "Please enter a numeric value: ";
	cin >> num2;

	if (num1 == num2) {
		cout << num1 << " is equal to " << num2 << endl;
	}
	else {
		if (num1 > num2) {
			smallestNum = num2;
		}
		else {
			smallestNum = num1;
		}
		cout << "The smalles value is " << smallestNum << endl;
	}

	system("pause");
}


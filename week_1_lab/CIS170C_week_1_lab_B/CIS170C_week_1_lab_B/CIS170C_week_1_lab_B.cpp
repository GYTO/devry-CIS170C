// ---------------------------------------------------
// Programming Assignment:  LAB1B
// Developer:				Roman Kovtun
// Date Written:			03/02/2018
// Purpose:					Average Program
// ---------------------------------------------------

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "Find the Average Program\n";

	double num1, num2, num3, average;
	cout << "Please enter number 1: ";
	cin >> num1;
	cout << "Please enter number 2: ";
	cin >> num2;
	cout << "Please enter number 3: ";
	cin >> num3;
	average = (num1 + num2 + num3) / 3;

	cout << "The avarage is: " << average << endl;

	system("pause");
}
// ---------------------------------------------------
// Programming Assignment:  LAB5
// Developer:				Roman Kovtun
// Date Written:			03/31/2018
// Purpose:					Password Test
// ---------------------------------------------------

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
	const int LENGTH = 101;
	char password[LENGTH];
	int Upper, Lower, Digit;

	do
	{
		cout << "Password requirements:\n";
		cout << "- The password should be at least 6 characters long\n";
		cout << "- The password should contain at least one uppercase and one lowercase letter\n";
		cout << "- The password should have at least one digit\n\n";

		Upper = Lower = Digit = 0;

		cout << "Enter a password: ";
		cin.getline(password, LENGTH);

		for (int i = 0; i < strlen(password); i++)
		{
			if (isdigit(password[i]))
			{
				Digit++;
			}
			if (isupper(password[i]))
			{
				Upper++;
			}
			if (islower(password[i]))
			{
				Lower++;
			}
		}

		if (Upper == 0 || Lower == 0 || Digit == 0 || strlen(password) < 6)
		{
			cout << "The password was invalid\n\n";
		} else {
			cout << "The password is valid\n\n";
		}
	} while (Upper == 0 || Lower == 0 || Digit == 0 || strlen(password) < 6);

	system("pause");
}


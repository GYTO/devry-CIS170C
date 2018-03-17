// ---------------------------------------------------
// Programming Assignment:  LAB3
// Developer:				Roman Kovtun
// Date Written:			03/16/2018
// Purpose:					Arrays
// ---------------------------------------------------

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
	int sum = 0, hiSalesProduct = 0, lowSalesProduct = 0;
	double index = 7;
	string salsa[] = {"mild", "medium", "hot", "sweet", "fruit", "verde", "zesty" };
	int soldJars[7];

	

	for (int i = 0; i < index; i++)
	{
		cout << "Jars sold last month of " << salsa[i] << ": ";
		cin >> soldJars[i];
		
	}

	cout << "\n\nSalsa Sales Report \n\n";

	cout << "Name ----- Jars Sold\n";
	cout << "--------------------\n";

	hiSalesProduct = lowSalesProduct = soldJars[0];

	for (int i = 0; i < index; i++)
	{
		//for (int j = 0; j, index; j++) {
			//soldJars[i] = salsa[j];
		//}

		cout << salsa[i] << " ----- " << soldJars[i] << "\n";
		sum += soldJars[i];

		if (soldJars[i] > hiSalesProduct)
		{
			hiSalesProduct = soldJars[i];

		}
		else if (soldJars[i] < lowSalesProduct)
		{
			lowSalesProduct = soldJars[i];
		}

	}

	cout << "\nTotal Sales: " << sum << endl;
	cout << "High Seller: " << hiSalesProduct << endl;
	cout << "Low Seller: " << lowSalesProduct << endl;
	
	system("pause");
}
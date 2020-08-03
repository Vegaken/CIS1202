/*
Kenji Hirai
CIS 1202
02/10/2019
Week 4 - Assignment 5 – Arrays and Memory
Property management propgram
 */

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


int getMenuItem();
void enterRents(int*, int);
void displayRents(int*, int);
int sumRents(int*, int);
void displayMemoryLocations(int*, int);
void selectionSort(int*, int);

int main()
{
	const int SIZE = 7;
	int rents[7] = { 1200,740,660,1000,550,920,1350 };
	int *ptr = rents;
	bool loop = true;

	while (loop)
	{
		int choice = getMenuItem();

		switch (choice)
		{
		case 1: enterRents(ptr, SIZE);
			break;
		case 2: displayRents(ptr, SIZE);
			break;
		case 3: selectionSort(ptr, SIZE);
			break;
		case 4: sumRents(ptr, SIZE);
			break;
		case 5: displayMemoryLocations(ptr, SIZE);
			break;
		case 6: cout << "You have chosen to exit the program!" << endl;
			loop = false;
			break;
		default: cout << "Incorrect menu selection, try again." << endl << endl;
			break;
		}
	}
	system("pause");
	return 0;
}

int getMenuItem()
{
	int choice = 0;

	cout << "\nSinclair Property Management Company" << endl << endl;
	cout << "Select from the following menu:" << endl << endl;
	cout << "1: Enter rent amounts" << endl;
	cout << "2: Display rents" << endl;
	cout << "3: Sort rent amounts" << endl;
	cout << "4: Total rents" << endl;
	cout << "5: Display rent array memory locations" << endl;
	cout << "6: Exit program" << endl << endl;
	cout << "Enter Selection: ";
	cin >> choice;

	return(choice);
}

void enterRents(int *ptr, int SIZE)
{
	cout << "\nEnter the rent amounts." << endl;

	for (int i = 0; i < SIZE; i++)
	{
		cout << "Rent" << (i + 1) << " : ";
		cin >> ptr[i];
	}
}

void displayRents(int *rent, int SIZE)
{
	cout << "\nDisplaying the rent values:" << endl << endl;

	for (int i = 0; i < SIZE; i++)
	{
		cout << "Rental property " << i + 1 << " : " << *(rent + i) << endl;
	}

}

int sumRents(int *ptr, int SIZE)
{
	int total = 0;
	for (int i = 0; i < SIZE; i++)
	{
		total = total + *(ptr + i);
	}
	cout << "Total rents = $ " << total << endl;
	return 0;
}

void displayMemoryLocations(int *ptr, int SIZE)
{
	cout << "\nDisplay rent array memory locations:" << endl << endl;
	
	for (int i = 0; i < SIZE; i++)
	{
		cout << "Memory address of cell " << i + 1 << " : " << (ptr + i) << endl;
	}
}

void selectionSort(int *rent, int SIZE)
{
	bool swap;
	int temp;

	do
	{
		swap = false;
		for (int count = 0; count < (SIZE - 1); count++)
		{
			if (rent[count] > rent[count + 1])
			{
				temp = rent[count];
				rent[count] = rent[count + 1];
				rent[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);


	for (int i = 0; i < SIZE; i++)
	{
		cout << "Rental property " << i + 1 << " : " << rent[i] << endl;
	}
}

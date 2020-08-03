/*
Kenji Hirai
CIS 1202
02/18/2019
Week 6 - Struct
 Assignment 7 – Customer Contact Application
*/

#include <iostream>
#include <string>

using namespace std;

int index = 0;

struct Address {
	string street;
	string city;
	string state;
	string zipcode;
};

struct Customer {
	string firstNm, lastNm;
	Address busAddr, homeAddr;
};

int displayMenu();
Customer getCustomer();
void showCustomer(Customer);
void allCustomers(Customer[]);
Address getAddress();
void findCust(Customer[], int);

int main()
{
	Customer cust[100];
	bool loop = true;
	while (loop)
	{
		int choice = displayMenu();

		switch (choice)
		{
		case 1:
			cust[index] = getCustomer();
			index++;
			break;
		case 2:
			allCustomers(cust);
			break;
		case 3:
			findCust(cust, index);
			break;
		case 4:
			cout << "Exit program!!" << endl;
			loop = false;
			break;
		default:
			cout << "Invald choice, please re-enter." << endl;
		}
		cout << endl;
	}
	system("pause");
	return 0;
}

int displayMenu()
{
	int choice = 0;

	cout << "Customer Contacts Menu" << endl << endl;
	cout << "Select from the menu below" << endl << endl;
	cout << " 1: Enter new customer" << endl;
	cout << " 2: Display all customers" << endl;
	cout << " 3: Display a particular customer" << endl;
	cout << " 4: Exit program" << endl;
	cout << " Enter selection: ";
	cin >> choice;
	cin.ignore();
	cout << endl;
	return choice;
}

Customer getCustomer()
{
	Customer c;

	cout << "Enter customer first name: ";
	getline(cin, c.firstNm);

	cout << "Enter customer last name: ";
	getline(cin, c.lastNm);

	cout << "Enter Business Address: " << endl;
	c.busAddr = getAddress();

	cout << "Enter Home Address: " << endl;
	c.homeAddr = getAddress();

	cout << endl;

	return c;
}

void showCustomer(Customer c) 
{
	cout << "First Name: " << c.firstNm << endl;
	cout << "Last Name: " << c.lastNm << endl;
	cout << "Business Address: " << c.busAddr.street << " , " << c.busAddr.city << " , " << c.busAddr.state << " , " << c.busAddr.zipcode << endl;
	cout << "Home Address: " << c.homeAddr.street << " , " << c.homeAddr.city << " , " << c.homeAddr.state << " , " << c.homeAddr.zipcode << endl;
}

void allCustomers(Customer cust[]) 
{
	for (int i = 0; i < index; i++) 
	{
		showCustomer(cust[i]);
		cout << endl;
	}
}


Address getAddress() 
{
	Address a;

	cout << "Enter Street: ";
	getline(cin, a.street);

	cout << "Enter City: ";
	getline(cin, a.city);

	cout << "Enter State: ";
	getline(cin, a.state);

	cout << "Enter Zip Code: ";
	getline(cin, a.zipcode);

	return a;
}

void findCust(Customer cust[], int size) 
{
	string firstName, lastName;

	cout << "Enter customer first name: ";
	getline(cin, firstName);

	cout << "Enter customer last name: ";
	getline(cin, lastName);

	cout << endl;

	for (int i = 0; i < size; i++) 
	{
		if (cust[i].firstNm == firstName && cust[i].lastNm == lastName) 
		{
			showCustomer(cust[i]);
			return;
		}
	}
	cout << "Customer not in list." << endl;
}
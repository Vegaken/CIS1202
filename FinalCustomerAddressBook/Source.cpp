/*
Kenji Hirai
April 29, 2019
CIS 1202_Final Project
Customer address book
*/

#include <iostream>
#include <iomanip>
#include "CustomerData.h"

using namespace std;

// Prototype function to display formatted customer data on the screen
void displayCustomer(CustomerData c);

int main() {
	
	// Declaring CustomerData object using default constructor
	CustomerData c1;

	// Using mutator functions to set all field values
	c1.setCustomerNumber(10001);
	c1.setMailingList(false);
	c1.setLastName("Blackwood");
	c1.setFirstName("Cory");
	c1.setAddress("83649 W Belmont Ave");
	c1.setCity("San Gabriel");
	c1.setState("CA");
	c1.setZip("91776");
	c1.setPhone("(626)572-1096");

	CustomerData c2;
	c2.setCustomerNumber(10002);
	c2.setMailingList(false);
	c2.setLastName("Dilello");
	c2.setFirstName("Lindsey");
	c2.setAddress("52777 Leaders Heights Rd");
	c2.setCity("Ontario");
	c2.setState("CA");
	c2.setZip("91761");
	c2.setPhone("(909)639-9887");

	CustomerData c3;
	c3.setCustomerNumber(10003);
	c3.setMailingList(true);
	c3.setLastName("Kitzman");
	c3.setFirstName("Kerry");
	c3.setAddress("2409 Alabama Rd");
	c3.setCity("RIverside");
	c3.setState("CA");
	c3.setZip("92501");
	c3.setPhone("(951)645-3605");

	//Declaring CustomerData object using full argument constructor
	CustomerData c4(10004, true, "Zane", "Sheridan", "429 Tiger Ln", "San Francisco", "CA", "94403", "(805)275-2943");
	CustomerData c5(10005, true, "Degonia", "Joesph", "2887 Knowlton St #5435", "Beverly Hills", "CA", "94710", "(310)499-3296");

	//Using displayCustomer function to test object creation
	displayCustomer(c1);
	displayCustomer(c2);
	displayCustomer(c3);
	displayCustomer(c4); 
	displayCustomer(c5);
	
	system("pause");
	return 0;
}

// Function definition
void displayCustomer(CustomerData c) {

	cout << setw(20) << left << "Customer Number: " << c.getCustomerNumber() << endl;
	cout << setw(20) << left << "Customer Name: " << c.getLastName();
	cout << ", " << c.getFirstName() << endl;
	cout << setw(20) << left << "Address: " << c.getAddress() << endl;
	cout << setw(20) << left << "" << c.getCity() << ", " << c.getState();
	cout << " " << c.getZip() << endl;
	cout << setw(20) << left << "Phone: " << c.getPhone() << endl;
	cout << setw(20) << left << "Mailing List: ";
	
	if (c.getMailingList() == 1) {

		cout << "Yes";
	}
	
	else {
		
		cout << "No";
	}
	
	cout << endl;
	cout << endl;
}
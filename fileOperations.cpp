/*
Kenji Hirai
CIS 1202
03/18/2019
File Operations
*/

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

const int DESC_SIZE = 40; 

struct Product 
{ long prodNum;  
  char prodName[DESC_SIZE];  
  double price;  
  int qty; 
};

int showMenu();
void modifyRecord(fstream &);
void displayRecord(fstream &);
void changeRecord(fstream &);


int main()
{
	Product record;
	long prodNum;

	fstream dataFile("inventory.dat", ios::in | ios::out | ios::binary);
	if (dataFile.fail())
	{
		dataFile.open("inventory.dat", ios::out);
		dataFile.close();
	}


	bool loop = true;
	while(loop)
	{ 
		int selection = showMenu();
	
		switch (selection)
		{
		case 1:
			displayRecord(dataFile);
			break;
		case 2:
			modifyRecord(dataFile);
			break;
		case 3:
			modifyRecord(dataFile);
			break;
		case 4: cout << "You have chosen to exit the program!" << endl;
			loop = false;
			break;
		default:
			cout << "Incorrect menu selection, Please enter 1 to 4" << endl;
		}
		cout << endl;	
	}
	system("pause");
	return 0;
}

int showMenu()
{
	int menuSelection = 0;

	cout << "1 - Display product inventory" << endl;
	cout << "2 - Display a particular product" << endl;
	cout << "3 - Modify a product" << endl;
	cout << "4 - Exit Program" << endl;
	cout << endl << "Enter your choice:";
	cin >> menuSelection;
	cout << endl;
	return menuSelection;
}


void displayRecord(fstream &record)
{	
	long prodNum;
	char prodName[DESC_SIZE];
	double price;
	int qty;

	fstream dataFile("inventory.dat", ios::in | ios::out | ios::binary);
	while (dataFile)
	{
		dataFile.read(reinterpret_cast<char*>(&record), sizeof(record));
		
		cout << "Record #" << (prodNum +1) << endl;
		cout << "Product Number: " << record.prodNum << endl;
		cout << "product Name:" << record.prodName << endl;
		cout << "Price: " << record.price << endl;
		cout << "Quantity: " << record.qty << endl;
		cout << endl;
	}
}

void modifyRecord(fstream &notused)
{
	fstream file("inventory.dat", ios::in | ios::out | ios::app | ios::binary);

	char shouldContinue;
	do {
		Product p;

		cout << "Record #" << endl;

		cout << "Product Number:" << endl;
		cin.getline(p.prodNum, DESC_SIZE);

		cout << "product Name:";
		cin.getline(p.prodName, DESC_SIZE);

		cout << "Price:" << endl;
		cin >> p.price;
		
		cout << "Quantity:";
		cin >> p.qty;

		file.write(reinterpret_cast<char *>(&p), sizeof(p));

		cout << "Enter more files(Y/N): ";
		cin >> shouldContinue;
		cin.ignore();

	} while (shouldContinue == 'Y' || shouldContinue == 'y');
}

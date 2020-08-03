#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void loadArrays(string address[], double dues[], int size);
void printTaxes(string address[], double dues[], int size);
void sortTaxes(string address[], double dues[], int size);
void lookUpTaxes(string address[], double dues[], int size);
void biggestTaxes(string address[], double dues[], int size);

int main() {

	const int NUM_PROPS = 7;
	string address[NUM_PROPS] = {
		"151 acorn", "161 acorn",
		"200 Main", "500 Arcad",
		"181 Acorn", "120 Xenia",
		"200 Acorn"
	};

	double dues[NUM_PROPS] = {
		500,1500,15000,25000,6000,1000,20000
	};

	int choice;
	cout << "\t County Auditors Property Tax Sort and Search\n";
	cout << "1: Display the Property Tax Data\n";
	cout << "2: Look up taxes for a particular address\n";
	cout << "3: Sort tax amounts into ascending order\n";
	cout << "4: Display property with largest tax due\n";
	cout << "5: Exit\n\n";;
	cin >> choice;

	loadArrays(address, dues, NUM_PROPS);

	printTaxes(address, dues, NUM_PROPS);
	sortTaxes(address, dues, NUM_PROPS);
	printTaxes(address, dues, NUM_PROPS);
	
	lookUpTaxes(address, dues, NUM_PROPS);
	biggestTaxes(address, dues, NUM_PROPS);

system("pause");
return 0;
}

void printTaxes(string address[], double dues[], int size) {
	cout << "------------------------" << endl;
	for (int i = 0; i < size; i++) {
		cout << address[i] << "\t $" << dues[i] << endl;
	}
	cout << "------------------------" << endl;
}

void sortTaxes(string address[], double dues[], int size) {

	bool swap;
	double tempVal;
	string tempAddr;

	do {
		swap = false;
		for (int count = 0; count < (size = -1); count++) {
			if (dues[count] > dues[count + 1]) {
				tempVal = dues[count];
				tempAddr = address[count];
				dues[count] = dues[count + 1];
				address[count] = address[count + 1];
				dues[count + 1] = tempVal;
				address[count + 1] = tempAddr;
				swap = true;
			}
		}

	} while (swap);
}

void biggestTaxes(string address[], double dues[], int size) {

	int startScan, minIndex;
	double minValue;
	string minAddress;

	for (startScan = 0; startScan < (size - 1); startScan++) {
		minIndex = startScan;
		minValue = dues[startScan];
		minAddress = address[startScan];

		for (int index = startScan + 1; index < size; index++) {
			if (dues[index] < minValue) {
				minValue = dues[index];
				minAddress = address[index];
				minIndex = index;
			}
		}
		dues[minIndex] = dues[startScan];
		address[minIndex] = address[startScan];
		dues[startScan] = minValue;
		address[startScan] = minAddress;
	}
}


void lookUpTaxes (string address[], double dues[], int size) {
	
	string queryString;
	cout << "Enter address to look up: ";
	getline(cin, queryString);
	
	for (int i = 0; i < size; i++) {
		if (address[i] == queryString) {
			cout << "The taxes for " << address[i] << " = $" << dues[i] << endl;
			return;
		}
	}

	cout << "The taxes for " << queryString << " are not found." << endl;
}



void loadArrays(string address[], double dues[], int size) {

	int choice;

	while (choice  != 5) {
		if (choice  == 1)
		{
			printTaxes (address, dues, size);
		}
		else if (choice  == 2)
		{
			lookUpTaxes (address, dues, size);
		}
		else if (choice  == 3)
		{
			sortTaxes(address, dues, size);
		}
		else if (choice  == 4)
		{
			biggestTaxes(address, dues, size);
		}    
		else 
			cout  << "invlaid choice ‐ try again\n\n";
	}
}
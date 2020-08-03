/*
Kenji Hirai
02/11/2019
CIS1202
Week 5 - String
Assignment 6 - C-String
*/

#include <iostream>
#include <cstring>

using namespace std;

int findW(char workOrderCode[], int codeLength);

long getCustNum(char workOrderCode[], int wIndex);

int getYear(char workOrderCode[], int wIndex);

long getOrderNum(char workOrderCode[], int startIndex, int codeLength);


int main()
{
	const int MAX_SIZE = 20;
	char workOrder[MAX_SIZE]; // = "91800w940770";
	
	cout << "Enter a three part work order code in the format: ";
	cout << "CustomerNumber Year OrderNumber " << endl << endl;

	cout << "The first 5-6 digits contain the work order number. " << endl;
	cout << "The 2 digits following the w represent the year." << endl;
	cout << "The remaining digits ( up to 5) represent the work order number. " << endl;
	cout << "Enter work order code: ";

	cin.getline(workOrder, MAX_SIZE);
	cout << "Input string: " << workOrder << endl << endl;

	int stringLength = strlen(workOrder);
	cout << "The length is: " << stringLength << endl;
	
	int wIndex = findW(workOrder, stringLength);
	cout << "The location of the w is: " << wIndex << endl;

	long customerNumber=getCustNum (workOrder, wIndex);
    cout << "The customer number is " << customerNumber << endl;

	int year = getYear(workOrder, wIndex);
	cout << "The year of the order is " << year << endl << endl;

	long workOrderNumber = getOrderNum (workOrder, wIndex +3,stringLength );
	cout << "The order number is: " << workOrderNumber << endl;

	system("pause");
	return 0;	
}

int findW(char workOrderCode[], int codeLength) {

	int result = 0;
	for (int i = 0; i < codeLength; i++) {
		if (workOrderCode[i] == 'w') {
			result = i ;
			break;
		}
	}
	return result;
}

long getCustNum(char workOrderCode[], int wIndex) {
	char tmp[7];
	strncpy_s(tmp, workOrderCode, wIndex);
	tmp[wIndex] = '\0';

	return atol(tmp);
}

int getYear(char workOrderCode[], int wIndex) {
	char tmp[3];
	for (int i = 0; i < 2; i++) {
		int codeIdx = wIndex + 1 + i;
		tmp[i] = workOrderCode[codeIdx];
	}
	tmp[2] = '\0';

	return atol(tmp);
}

long getOrderNum(char workOrderCode[], int startIndex, int codeLength) {
	
	return atol(workOrderCode+startIndex);
}

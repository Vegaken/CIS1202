#include "CustomerData.h"
using namespace std;

CustomerData::CustomerData() : PersonData() {
	customerNumber = 0;
	mailingList = false;
}

CustomerData::CustomerData(int cn, bool ml, string l, string f, string a, string c, string s, string z, string p) : PersonData(l, f, a, c, s, z, p) {

	customerNumber = cn;
	mailingList = ml;
}

void CustomerData::setCustomerNumber(int cn) {

	customerNumber = cn;
}

void CustomerData::setMailingList(bool ml) {

	mailingList = ml;
}

int CustomerData::getCustomerNumber() {

	return customerNumber;
}

bool CustomerData::getMailingList() {

	return mailingList;
}
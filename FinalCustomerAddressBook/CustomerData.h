#ifndef CUSTOMERDATA_H
#define CUSTOMERDATA_H
#include "PersonData.h"

using namespace std;

class CustomerData : public PersonData {

private:
	int customerNumber; 
	bool mailingList; 

public:
	CustomerData();
	CustomerData(int cn, bool ml, string l, string f, string a, string c, string s, string z, string p);

	void setCustomerNumber(int);
	void setMailingList(bool);

	int getCustomerNumber();
	bool getMailingList();
};
#endif

#ifndef PERSONDATA_H
#define PERSONDATA_H
#include <string>

using namespace std;

// The PersonData Class holds string values for
// information attributable to a person.

class PersonData {

private:
	string lastName, firstName, address, city, state, zip, phone;

public:
	PersonData();
	PersonData(string l, string f, string a, string c, string s, string z, string p);
	void setLastName(string l);
	void setFirstName(string f);
	void setAddress(string a);
	void setCity(string c);
	void setState(string s);
	void setZip(string z);
	void setPhone(string p);

	string getLastName();
	string getFirstName();
	string getAddress();
	string getCity();
	string getState();
	string getZip();
	string getPhone();
};

#endif
#pragma once
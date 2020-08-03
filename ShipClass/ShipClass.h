#ifndef SHIPCLASS_H
#define SHIPCLASS_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#pragma once

class ShipClass {
private:
	string name;
	int year;

public:
	ShipClass();
	ShipClass(string, int);
	~ShipClass();
	string getName();
	int getYear();
	void setName(string);
	void setYear(int);
	virtual void print();
};

ShipClass::ShipClass() {

}

ShipClass::ShipClass(string shipstr, int yearInt) {
	name = shipstr;
	year = yearInt;
}

ShipClass::~ShipClass() {

}


string ShipClass::getName() { return name; }

int ShipClass::getYear() { return year; }

void ShipClass::setName(string ship) { this->name = ship; }

void ShipClass::setYear(int year) { this->year =year; }

void ShipClass::print() {
	cout << "Ship Name: " << this->name << endl;
	cout << "Year Built: " << this->year << endl;
}

#endif
/*
Kenji Hirai
04/22/2019
CIS 1202
Program 12
Ship Class Program
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "ShipClass.h"
#include "CruiseShipClass.h"
#include "CargoShipClass.h"

using namespace std;

void getShip(ShipClass &);
void getCruiseShip(CruiseShip &);
void getCargoShip(CargoShip &);

int main() {
	cout << "Ship: " << endl;
	ShipClass ship;
	getShip(ship);
	ship.print();

	cout << "Cruise ship" << endl;
	CruiseShip CruiseShip;
	getCruiseShip(CruiseShip);
	CruiseShip.print();

	cout << "Cargo ship" << endl;
	CargoShip CargoShip;
	getCargoShip(CargoShip);
	CargoShip.print();

	cout << "Press any key to exit";
	getchar();


	system("pause");
	return 0;
}

void getShip(ShipClass &ship) {
	string setName;
	int setYear;

	cout << "Please Enter Ship Name: ";
	cin >> ship.setName;

	cout << "Please Enter Year Built: ";
	cin >> ship.setYear;
}

void getCruiseShip(CruiseShip &ship) {
	string setName;
	int setYear, setMaxPassenger;

	cout << "Please Enter Ship Name: ";
	cin >> ship.setName;

	cout << "Please Enter Year Built: ";
	cin >> ship.setYear;

	cout << "Please enter the maximum passenger capacity: ";
	cin >> ship.setMaxPassenger;
	cout << endl;
}

void getCargoShip(CargoShip &ship) {
	string setName;
	int setYear, setCapacity;
	
	cout << "Please Enter Ship Name: ";
	cin >> ship.setName;

	cout << "Please Enter Year Built: ";
	cin >> ship.setYear;

	cout << "Please enter cargo capacity in tonnage: ";
	cin >> ship.setCapacity;
	cout << endl;
}
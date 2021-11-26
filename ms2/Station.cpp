
/********************************************
	Name   :Heeyeon Han
	ID     : 154222194
	Email  : hhan34@myseneca.ca
	Section: OOP345ZAA
	Date: 2021/11/15
*********************************************/
//I confirm that the content of this file is created by me, with the exception of the parts provided to me by my professor.

#include <iostream>
#include <iomanip>

#include "Station.h"
#include "Utilities.h"

using namespace std;
namespace sdds {

	int Station::id = 0;
	size_t Station::width = 0;


	size_t Station::getNextSerialNumber() {
		return numOfSerial++;
	}

	size_t Station::getQuantity() const {
		return items;
	}

	const string& Station::getItemName() const {
		return handledItem;
	}


	void Station::updateQuantity() {
		

		if (items - 1 <= 1) {
			items = 0;
		}
		else {
			items--;
		}

	}

	void Station::display(ostream& ostream, bool check) const {
		if (!check)
			ostream << "[" << setfill('0') << setw(3) << right << stationId << "] "
			<< "Item: " << setw(width) << setfill(' ')
			<< left << handledItem << " [" << setfill('0')
			<< setw(6) << right << numOfSerial << "]" << endl;
		else
			ostream << "[" << setfill('0') << setw(3) << right << stationId << "] "
			<< "Item: " << setw(width) << setfill(' ') << left
			<< handledItem << " [" << setfill('0') << setw(6) << right << numOfSerial
			<< "]" << " Quantity: " << setw(width) << setfill(' ') << left
			<< items << " Description: " << description << endl;
	}


	Station::Station(const string& stringText) {
		
		bool check = false;
		size_t postion = 0;

		Utilities utilities;

		
		try
		{
			handledItem = utilities.extractToken(stringText, postion, check);

			if (width < utilities.getFieldWidth())
				width = utilities.getFieldWidth();

			numOfSerial = stoi(utilities.extractToken(stringText, postion, check));

			items = stoi(utilities.extractToken(stringText, postion, check));

			description = utilities.extractToken(stringText, postion, check);
		}
		catch (string& error)
		{
			cout << error;
		}
		
		id++;

		stationId = id;
	}



}

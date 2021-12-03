
/********************************************
	Name   :Heeyeon Han
	ID     : 154222194
	Email  : hhan34@myseneca.ca
	Section: OOP345ZAA
	Date: 2021/12/02
*********************************************/
//I confirm that the content of this file is created by me, with the exception of the parts provided to me by my professor.


#include <iostream>
#include <iomanip>

#include "Station.h"
#include "Utilities.h"

using namespace std;
namespace sdds {

	size_t Station::m_widthField = 1;
	int Station::id_generator = 0;

	Station::Station(const string& str) {
		Utilities utilities;
		size_t pos = 0;
		bool more = false;

		id = ++id_generator;
		item_handled = utilities.extractToken(str, pos, more);
		serial_num = stoi(utilities.extractToken(str, pos, more));
		curr_items = stoi(utilities.extractToken(str, pos, more));
		m_widthField = max(m_widthField, utilities.getFieldWidth());
		desc = utilities.extractToken(str, pos, more);
	}
	size_t Station::getNextSerialNumber() {
		return serial_num++;
	}

	size_t Station::getQuantity() const {
		return curr_items;
	}

	const string& Station::getItemName() const {
		return item_handled;
	}


	void Station::display(ostream& os, bool full) const {
		if (full)
		{
			os << "[" << setfill('0') << setw(3) << right << id << "] ";
			os << "Item: " << setw(m_widthField) << setfill(' ') << left << item_handled;
			os << " [" << setfill('0') << setw(6) << right << serial_num << "]";
			os << " Quantity: " << setw(m_widthField) << setfill(' ') << left << curr_items;
			os << " Description: " << desc << endl;

		}
		else
		{
			os << "[" << setfill('0') << setw(3) << right << id << "] ";
			os << "Item: " << setw(m_widthField) << setfill(' ') << left << item_handled;
			os << " [" << setfill('0') << setw(6) << right << serial_num << "]" << endl;
		}
	}
	void Station::updateQuantity() {
		curr_items--;
		if (curr_items < 0)
		{
			curr_items = 0;
		}
	}

}

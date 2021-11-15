
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

	size_t Station::m_widthField = 1;
	int Station::id_generator = 0;

	Station::Station(const string& str) {
		id_generator++;
		Utilities utilities;
		size_t pos = 0;
		bool more = false;
		
		try
		{
			item_handled = utilities.extractToken(str, pos, more);
			if (m_widthField < utilities.getFieldWidth())
			{
				m_widthField = utilities.getFieldWidth();
			}
			serial_num = stoi(utilities.extractToken(str, pos, more));
			curr_items = stoi(utilities.extractToken(str, pos, more));
			desc = utilities.extractToken(str, pos, more);
		}
		catch (string& error)
		{
			cout << error;
		}
		id = id_generator;
	}
	
	const string& Station::getItemName() const {
		return item_handled;
	}

	size_t Station::getNextSerialNumber() {
		return serial_num++;
	}

	size_t Station::getQuantity() const {
		return curr_items;
	}

	void Station::updateQuantity() {
		curr_items--;
		if (curr_items < 0)
		{
			curr_items = 0;
		}
	}

	void Station::display(ostream& os, bool full) const {
		if (full)
			os << "[" << setfill('0') << setw(3) << right << id << "] " 
			<< "Item: " << setw(m_widthField) << setfill(' ') << left 
			<< item_handled << " [" << setfill('0') << setw(6) << right << serial_num 
			<< "]" << " Quantity: " << setw(m_widthField) << setfill(' ') << left 
			<< curr_items << " Description: " << desc << endl;
		else
			os << "[" << setfill('0') << setw(3) << right << id << "] " 
			<< "Item: " << setw(m_widthField) << setfill(' ') 
			<< left << item_handled << " [" << setfill('0') 
			<< setw(6) << right << serial_num << "]" << endl;
	}
}

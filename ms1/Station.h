
/********************************************
	Name   :Heeyeon Han
	ID     : 154222194
	Email  : hhan34@myseneca.ca
	Section: OOP345ZAA
	Date: 2021/11/15
*********************************************/
//I confirm that the content of this file is created by me, with the exception of the parts provided to me by my professor.

#ifndef STATION_H
#define STATION_H

#include <string>

namespace sdds {
	class Station {
		int id = 0;
		std::string item_handled = "";
		std::string desc = "";
		size_t serial_num = 0;
		size_t curr_items = 0;
		static size_t m_widthField;
		static int id_generator;
	public:
		Station() {};
		Station(const std::string&);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};
}
#endif
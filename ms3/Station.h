
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
		int stationId = 0;
		size_t numOfSerial = 0;
		size_t items = 0;

		std::string handledItem = "	";
		std::string description = "	";
		
		static size_t width;
		static int id;

	public:

		Station() {};
		Station(const std::string&);
		void updateQuantity();
		void display(std::ostream& ostream, bool check) const;
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;

	};
}
#endif

/********************************************
	Name   :Heeyeon Han
	ID     : 154222194
	Email  : hhan34@myseneca.ca
	Section: OOP345ZAA
	Date: 2021/12/02
*********************************************/
//I confirm that the content of this file is created by me, with the exception of the parts provided to me by my professor.


#ifndef LINEMANAGER_H
#define LINEMANAGER_H
#include <functional>
#include <fstream>
#include <vector>
#include <algorithm>


#include "Workstation.h"

namespace sdds {
	class LineManager {
		size_t m_cntCustomerOrder;

		std::vector<Workstation*> activeLine;
		Workstation* m_firstStation = nullptr;
	public:
		void displayStations();
		void displayStationsSorted() const;
		LineManager(const std::string& file, const std::vector<Workstation*>& stations);
		void display(std::ostream& os) const;

		void linkStations();
		bool run(std::ostream& os);
	};
}
#endif
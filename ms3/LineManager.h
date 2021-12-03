
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

#include <vector>
#include <algorithm>
#include <functional>
#include <fstream>

#include "Workstation.h"

namespace sdds {
	class LineManager {
		std::vector<Workstation*> activeLine;
		size_t m_cntCustomerOrder;
		Workstation* m_firstStation = nullptr;
	public:
		LineManager(const std::string& file, const std::vector<Workstation*>& stations);
		void displayStations();
		void displayStationsSorted() const;
		void linkStations();
		void display(std::ostream& os) const;
		bool run(std::ostream& os);
	};
}
#endif
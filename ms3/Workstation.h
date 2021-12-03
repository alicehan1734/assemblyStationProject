
/********************************************
	Name   :Heeyeon Han
	ID     : 154222194
	Email  : hhan34@myseneca.ca
	Section: OOP345ZAA
	Date: 2021/12/02
*********************************************/
//I confirm that the content of this file is created by me, with the exception of the parts provided to me by my professor.


#ifndef WORKSTATION_H
#define WORKSTATION_H

#include <deque>

#include "CustomerOrder.h"

namespace sdds {
	
	inline std::deque<CustomerOrder>completed;
	inline std::deque<CustomerOrder>incomplete;
	inline std::deque<CustomerOrder>pending;


	class Workstation : public Station {
		Workstation* m_pNextStation = nullptr;
		std::deque<CustomerOrder> m_orders;


	public:
		Workstation(Workstation&&) = delete;
		Workstation& operator=(Workstation&&) = delete;
		Workstation(Workstation&) = delete;
		Workstation& operator=(Workstation&) = delete;
		void setNextStation(Workstation* station);
		const Workstation* getNextStation() const;
		void display(std::ostream& os) const;
		Workstation(std::string& str);
		bool attemptToMoveOrder();
		void fill(std::ostream& os);
		Workstation& operator+=(CustomerOrder&& newOrder);
	};
}
#endif
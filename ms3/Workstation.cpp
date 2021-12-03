
/********************************************
	Name   :Heeyeon Han
	ID     : 154222194
	Email  : hhan34@myseneca.ca
	Section: OOP345ZAA
	Date: 2021/12/02
*********************************************/
//I confirm that the content of this file is created by me, with the exception of the parts provided to me by my professor.


#include "Workstation.h"

using namespace std;

namespace sdds {
	Workstation::Workstation(std::string& str) : Station(str) {}

	Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
		m_orders.push_back(move(newOrder));
		return *this;
	}
	bool Workstation::attemptToMoveOrder() {
		bool checking = false;

		if (!m_orders.empty())
		{
			if (m_orders.front().isItemFilled(Station::getItemName()) || getQuantity() == 0)
			{
				if (m_pNextStation == nullptr)
				{
					if (m_orders.front().isFilled())
					{
						completed.push_back(move(m_orders.front()));
						m_orders.pop_front();
						checking = true;
					}
					else if (!m_orders.front().isFilled()) {
						incomplete.push_back(move(m_orders.front()));
						m_orders.pop_front();
						checking = true;
					}
				}
				else
				{
					*m_pNextStation += move(m_orders.front());
					m_orders.pop_front();
					checking = true;
				}
			}
		}
		return checking;
	}

	void Workstation::fill(std::ostream& os) {
		if (!m_orders.empty())
			m_orders.front().fillItem(*this, os);

	}
	void Workstation::display(std::ostream& os) const {
		if (m_pNextStation == nullptr)
			os << getItemName() << " --> End of Line" << endl;
		else 
			os << getItemName() << " --> " << getNextStation()->getItemName() << endl;

	}

	const Workstation* Workstation::getNextStation() const {
		return m_pNextStation;
	}




	void Workstation::setNextStation(Workstation* station) {
		m_pNextStation = station;
	}



}
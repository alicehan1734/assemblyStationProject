
/********************************************
	Name   :Heeyeon Han
	ID     : 154222194
	Email  : hhan34@myseneca.ca
	Section: OOP345ZAA
	Date: 2021/12/02
*********************************************/
//I confirm that the content of this file is created by me, with the exception of the parts provided to me by my professor.


#include "CustomerOrder.h"

using namespace std;
namespace sdds {

	size_t CustomerOrder::m_widthField = 0;

	CustomerOrder::CustomerOrder(const std::string str) {
		Utilities utilities;
		size_t temp = 0;
		bool ext = true;

		m_name = utilities.extractToken(str, temp, ext);
		m_product = utilities.extractToken(str, temp, ext);
		m_cntItem = 0;

		auto temp2 = temp;

		while (ext)
		{
			utilities.extractToken(str, temp, ext);
			m_cntItem++;
		}

		m_lstItem = new Item * [m_cntItem];

		ext = true;

		for (size_t i = 0; i < m_cntItem; i++)
		{
			m_lstItem[i] = new Item(utilities.extractToken(str, temp2, ext));
		}

		if (utilities.getFieldWidth() > m_widthField)
		{
			m_widthField = utilities.getFieldWidth();
		}
	}

	CustomerOrder::CustomerOrder(const CustomerOrder& obj){
		throw "The copy operator is not allowed here";
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& obj)noexcept {
		*this = move(obj);
	}

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& obj)noexcept {
		if (this != &obj)
		{
			for (size_t i = 0; i < m_cntItem; i++)
			{
				delete m_lstItem[i];
			}
			m_name = obj.m_name;
			obj.m_name = "";
			m_product = obj.m_product;
			obj.m_product = "";
			m_cntItem = obj.m_cntItem;
			obj.m_cntItem = 0;
			m_lstItem = obj.m_lstItem;
			obj.m_lstItem = nullptr;
		}
		return *this;
	}

	CustomerOrder::~CustomerOrder() {
		for (size_t i = 0; i < m_cntItem; i++)
		{
			delete m_lstItem[i];
			m_lstItem[i] = nullptr;
		}
      delete[] m_lstItem;
      m_lstItem = nullptr;
	}

	bool CustomerOrder::isFilled() const {
		bool isFill = true;
		for (size_t i = 0; i < m_cntItem; i++)
		{
			if (!m_lstItem[i]->m_isFilled)
			{
				isFill = false;
			}
		}
		return isFill;
	}

	bool CustomerOrder::isItemFilled(const std::string& itemName) const {
		bool isFill = true;
		for (size_t i = 0; i < m_cntItem; i++)
		{
			if (m_lstItem[i]->m_itemName == itemName)
			{
				isFill = m_lstItem[i]->m_isFilled;
			}
		}
		return isFill;
	}

	void CustomerOrder::fillItem(Station& station, std::ostream& os) {
		for (size_t i = 0; i < m_cntItem; i++)
		{
			if (station.getItemName() == m_lstItem[i]->m_itemName)
			{
				if (station.getQuantity() > 0)
				{
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					m_lstItem[i]->m_isFilled = true;
					station.updateQuantity();
					os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
				}
				else {
					os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
				}
			}
		}
	}

	void CustomerOrder::display(std::ostream& os) const {
		os << m_name << " - " << m_product << endl;
		for (size_t i = 0; i < m_cntItem; i++) {
			os << "[" << setw(6) << setfill('0') << right << m_lstItem[i]->m_serialNumber << "] " << setfill(' ') << setw(m_widthField) << left << m_lstItem[i]->m_itemName;

			if (m_lstItem[i]->m_isFilled) {
				os << " - FILLED" << std::endl;
			}
			else {
				os << " - TO BE FILLED" << std::endl;
			}
		}
	}
}
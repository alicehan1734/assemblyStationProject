
/********************************************
	Name   :Heeyeon Han
	ID     : 154222194
	Email  : hhan34@myseneca.ca
	Section: OOP345ZAA
	Date: 2021/11/25
*********************************************/
//I confirm that the content of this file is created by me, with the exception of the parts provided to me by my professor.

#ifndef CUSTOMERORDER_H
#define CUSTOMERORDER_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Station.h"
#include "Utilities.h"

namespace sdds {
	struct Item
	{
		std::string m_itemName;
		size_t m_serialNumber{ 0 };
		bool m_isFilled{ false };

		Item(const std::string& src) : m_itemName(src) {};
	};

	class CustomerOrder {
		std::string m_name{};
		std::string m_product{};
		size_t m_cntItem{ 0 };
		Item** m_lstItem{};
		static size_t m_widthField;
	public:
		CustomerOrder() {};
		CustomerOrder(const std::string str);
		CustomerOrder& operator=(const CustomerOrder& obj) = delete;
		CustomerOrder(const CustomerOrder& obj);
		CustomerOrder(CustomerOrder&& obj)noexcept;
		CustomerOrder& operator=(CustomerOrder&& obj)noexcept;
		~CustomerOrder();
		bool isFilled() const;
		bool isItemFilled(const std::string& itemName) const;
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;
	};
}
#endif
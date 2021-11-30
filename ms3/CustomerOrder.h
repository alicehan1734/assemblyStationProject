
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
#include "Station.h"
#include "Utilities.h"
#include "Utilities.h"

namespace sdds {
	struct Item
	{
		size_t m_serialNumber{ 0 };

		std::string m_itemName;
		
		bool m_isFilled{ false };

		Item(const std::string& src) : m_itemName(src) {
		
		};
	};

	class CustomerOrder {
		
		size_t m_cntItem{ 0 };
		Item** m_lstItem{};
		std::string m_name{};
		std::string m_product{};
		static size_t m_widthField;

	public:

		CustomerOrder() {};
		~CustomerOrder();

		void fillItem(Station& station, std::ostream& ostream);
		void display(std::ostream& ostream) const;

		CustomerOrder(const std::string& string);
		CustomerOrder(CustomerOrder&& object)noexcept;
		CustomerOrder(const CustomerOrder& object);

		CustomerOrder& operator=(const CustomerOrder& object) = delete;
		CustomerOrder& operator=(CustomerOrder&& object)noexcept;

		bool isFilled() const;
		bool isItemFilled(const std::string& itemName) const;

	};
}
#endif
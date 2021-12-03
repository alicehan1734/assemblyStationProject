
/********************************************
	Name   :Heeyeon Han
	ID     : 154222194
	Email  : hhan34@myseneca.ca
	Section: OOP345ZAA
	Date: 2021/12/02
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
		Item(const std::string& src) : m_itemName(src) {};

		std::string m_itemName;
		size_t m_serialNumber{ 0 };
		bool m_isFilled{ false };

	};

	class CustomerOrder {
		std::string m_name{};
		size_t m_cntItem{ 0 };

		std::string m_product{};
		Item** m_lstItem{};


		static size_t m_widthField;


	public:

		CustomerOrder(CustomerOrder&& obj)noexcept;
		CustomerOrder() {};
		
		CustomerOrder& operator=(const CustomerOrder& obj) = delete;

		CustomerOrder(const CustomerOrder& obj);
		CustomerOrder& operator=(CustomerOrder&& obj)noexcept;
		
		void fillItem(Station& station, std::ostream& os);
		~CustomerOrder();
		
		bool isFilled() const;
		CustomerOrder(const std::string str);

		void display(std::ostream& os) const;
		bool isItemFilled(const std::string& itemName) const;

	};
}
#endif
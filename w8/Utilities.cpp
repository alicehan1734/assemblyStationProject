// Workshop 8 - Smart Pointers
// 2019/11 - Cornel

/********************************************
	Name   :Heeyeon Han
	ID     : 154222194
	Email  : hhan34@myseneca.ca
	Section: OOP345ZAA
	Date: 2021/11/21
*********************************************/
//I confirm that the content of this file is created by me, with the exception of the parts provided to me by my professor.

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
				//size_t k;
		//size_t y;

		for (size_t i = 0; i <= desc.size()-1; i++)
		{
			for (size_t j = 0; j <= price.size()-1; j++)
			{

				if (desc[i].code == price[j].code)
				{
					Product* product = nullptr;

					product = new Product(desc[i].desc, price[j].price);

					product->validate();

					priceList += product;

					delete product;

					product = nullptr;

				}
				else {

				}

			}

		}
		return priceList;

	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers
		//size_t k;
		//size_t y;

		for (size_t i = 0; i <= desc.size()-1; i++)
		{

			for (size_t j = 0; j <= price.size()-1; j++)
			{

				if (desc[i].code == price[j].code)
				{

					std::unique_ptr<Product> product{ new Product(desc[i].desc, price[j].price) };

					product->validate();

					priceList += product;

				}
				else {

				}

			}

		}
		return priceList;
	}
}
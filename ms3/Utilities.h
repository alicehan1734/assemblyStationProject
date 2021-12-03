
/********************************************
	Name   :Heeyeon Han
	ID     : 154222194
	Email  : hhan34@myseneca.ca
	Section: OOP345ZAA
	Date: 2021/12/02
*********************************************/
//I confirm that the content of this file is created by me, with the exception of the parts provided to me by my professor.


#ifndef UTILITIES_H
#define UTILITIES_H
#include <string>
#include <algorithm>
#include <exception>      
#include <iostream>
#include <string>

namespace sdds {
	class Utilities {
		static char m_delimiter;

		size_t m_widthField = 1;
	public:
		static void setDelimiter(char newDelimiter);
		void setFieldWidth(size_t newWidth);
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
		size_t getFieldWidth() const;

		static char getDelimiter();
	};
}
#endif
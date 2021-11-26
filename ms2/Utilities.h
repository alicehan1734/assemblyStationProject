
/********************************************
	Name   :Heeyeon Han
	ID     : 154222194
	Email  : hhan34@myseneca.ca
	Section: OOP345ZAA
	Date: 2021/11/15
*********************************************/
//I confirm that the content of this file is created by me, with the exception of the parts provided to me by my professor.

#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>

namespace sdds {
	class Utilities {

		static char utils_delimiter;
		size_t utils_width = 0;

	public:

		void setFieldWidth(size_t fieldWidth);
		static void setDelimiter(char newDel);
		size_t getFieldWidth() const;
		static char getDelimiter();

		std::string extractToken(const std::string& stringText, size_t& position, bool& check);

	};
}
#endif
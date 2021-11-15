
/********************************************
	Name   :Heeyeon Han
	ID     : 154222194
	Email  : hhan34@myseneca.ca
	Section: OOP345ZAA
	Date: 2021/11/15
*********************************************/
//I confirm that the content of this file is created by me, with the exception of the parts provided to me by my professor.

#include <string>
#include <algorithm>

#include "Utilities.h"

using namespace std;
namespace sdds {

	char Utilities::m_delimiter = ' ';

	void Utilities::setFieldWidth(size_t newWidth) {
		m_widthField = newWidth;
	}

	size_t Utilities::getFieldWidth() const {
		return m_widthField;
	}

	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
		string ex_token = str.substr(next_pos);
		size_t pos = ex_token.find(m_delimiter);

		if (pos != string::npos)
		{
			ex_token = ex_token.substr(0, pos);
			next_pos += pos + 1;
			if (ex_token == "")
			{
				more = false;
				throw "There is not any token between delimiters";
			}
			more = true;
		}
		else {
			more = false;
		}

		if (ex_token.length() > m_widthField)
		{
			setFieldWidth(ex_token.length());
		}
		return ex_token;
	}

	void Utilities::setDelimiter(char newDelimiter) {
		m_delimiter = newDelimiter;
	}

	char Utilities::getDelimiter() {
		return m_delimiter;
	}
}

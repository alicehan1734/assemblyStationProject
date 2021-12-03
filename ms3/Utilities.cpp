
/********************************************
	Name   :Heeyeon Han
	ID     : 154222194
	Email  : hhan34@myseneca.ca
	Section: OOP345ZAA
	Date: 2021/12/02
*********************************************/
//I confirm that the content of this file is created by me, with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS

#include "Utilities.h"

using namespace std;
namespace sdds {

	char Utilities::m_delimiter;

	void Utilities::setFieldWidth(size_t newWidth) {
		m_widthField = newWidth;
	}

	size_t Utilities::getFieldWidth() const {
		return m_widthField;
	}

	void Utilities::setDelimiter(char newDelimiter) {
		m_delimiter = newDelimiter;
	}

	char Utilities::getDelimiter() {
		return m_delimiter;
	}
	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {

		string ex_token;
		size_t pos = str.find(m_delimiter, next_pos);

		if (pos == next_pos)
		{
			ex_token = {};
			more = false;
			next_pos += pos + 1;
			throw "There is not any token between delimiters" + next_pos;
		}
		else {
			ex_token = str.substr(next_pos, pos - next_pos);
			next_pos = pos + 1;
			m_widthField = max(m_widthField, ex_token.size());
			if (pos != string::npos)
			{
				more = true;
			}
			else {
				more = false;
			}
		}
		return ex_token;
	}


}

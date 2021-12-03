
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
	void Utilities::setDelimiter(char newDelimiter) {
		m_delimiter = newDelimiter;
	}
	size_t Utilities::getFieldWidth() const {
		return m_widthField;
	}



	std::string Utilities::extractToken(const std::string& str, size_t& nextLevel, bool& more) {

		string string;
		size_t pos = str.find(m_delimiter, nextLevel);

		if (pos == nextLevel)
		{
			string = {};
			more = false;
			nextLevel += pos + 1;
			throw "There is not any token between delimiters" + nextLevel;
		}
		else {
			string = str.substr(nextLevel, pos - nextLevel);
			nextLevel = pos + 1;
			m_widthField = max(m_widthField, string.size());
			if (pos != string::npos)
			{
				more = true;
			}
			else {
				more = false;
			}
		}
		return string;
	}

	char Utilities::getDelimiter() {
		return m_delimiter;
	}

}

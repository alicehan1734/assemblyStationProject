
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

	char Utilities::utils_delimiter = ' ';

	void Utilities::setFieldWidth(size_t fieldWidth) {
		utils_width = fieldWidth;
	}

	size_t Utilities::getFieldWidth() const {
		return utils_width;
	}

	std::string Utilities::extractToken(const std::string& stringText, size_t& position, bool& check) {
		string ex_token = stringText.substr(position);
		size_t pos = ex_token.find(utils_delimiter);

		if (pos != string::npos)
		{
			ex_token = ex_token.substr(0, pos);
			position += pos + 1;
			if (ex_token == "")
			{
				check = false;
				throw "There is not any token between delimiters";
			}
			check = true;

			if (ex_token.length() > utils_width)
				setFieldWidth(ex_token.length());
		}
		else {
			check = false;

			if (ex_token.length() > utils_width)
				setFieldWidth(ex_token.length());
		}

		return ex_token;
	}

	void Utilities::setDelimiter(char newDel) {
		utils_delimiter = newDel;
	}

	char Utilities::getDelimiter() {
		return utils_delimiter;
	}
}

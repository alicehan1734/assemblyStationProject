
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


	void Utilities::setDelimiter(char newDel) {
		utils_delimiter = newDel;
	}

	char Utilities::getDelimiter() {
		return utils_delimiter;
	}

	void Utilities::setFieldWidth(size_t fieldWidth) {
		utils_width = fieldWidth;
	}

	size_t Utilities::getFieldWidth() const {
		return utils_width;
	}

	std::string Utilities::extractToken(const std::string& stringText, size_t& position, bool& check) {

		size_t size_position = stringText.substr(position).find(utils_delimiter);
		string token = stringText.substr(position);

		if (size_position == string::npos)
		{
			check = false;

			if (token.length() > utils_width)
				setFieldWidth(token.length());
		}
		else {
			token = token.substr(0, size_position);

			position += size_position + 1;
			
			if (token == "")
			{
				check = false;
				throw "There is not any token between delimiters";
			}
			check = true;

			if (token.length() > utils_width)
				setFieldWidth(token.length());
		
		}

		return token;
	}

}

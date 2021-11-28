/********************************************
Name   :Heeyeon Han
ID : 154222194
Email : hhan34@myseneca.ca
Section : OOP345ZAA
Date : 2021 / 11 / 26
* ********************************************/
//I confirm that the content of this file is created by me, with the exception of the parts provided to me by my professor.

#ifndef W9_SECUREDATA_H
#define W9_SECUREDATA_H

#include <iostream>

namespace w9
{
	class Cryptor {

	public:
		char operator()(char in, char key) const { return in ^ key; }
	};

	void converter(char*, char, int, const Cryptor&);

	class SecureData {
		char* text;
		std::ostream* ofs;
		int nbytes;
		bool encoded;
		void code(char);
	public:
		SecureData(const char*, char, std::ostream*);
		SecureData(const SecureData&) = delete;
		SecureData& operator=(const SecureData&) = delete;
		~SecureData();
		void display(std::ostream&) const;
		void backup(const char*);
		void restore(const char*, char);
	};

	std::ostream& operator<<(std::ostream&, const SecureData&);
}
#endif
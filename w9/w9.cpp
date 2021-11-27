*******************************************
Name   :Heeyeon Han
ID : 154222194
Email : hhan34@myseneca.ca
Section : OOP345ZAA
Date : 2021 / 11 / 26
* ********************************************/
//I confirm that the content of this file is created by me, with the exception of the parts provided to me by my professor.
#include <iostream>
#include <fstream>
#include <string>
#include "SecureData.h"
#include "SecureData.h"

using namespace std;

int main(int argc, char** argv)
{
	cout << "Command Line: " << argv[0];
	for (int i = 1; i < argc; i++)
		cout << " " << argv[i];
	cout << endl << endl;

	if (argc != 4)
	{
		cerr << endl << "***Incorrect number of arguments***" << endl;
		return 1;
	}

	char key = argv[3][0];

	try {
		w9::SecureData sd(argv[1], key, &cout);
		sd.backup(argv[2]);

		sd.restore(argv[2], key);
		cout << sd << std::endl;

	}
	catch (const std::string& msg) {
		cout << msg << std::endl;
	}

	return 0;
}
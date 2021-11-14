
/********************************************
	Name   :Heeyeon Han
	ID     : 154222194
	Email  : hhan34@myseneca.ca
	Section: OOP345ZAA
	Date: 2021/11/14
*********************************************/
//I confirm that the content of this file is created by me, with the exception of the parts provided to me by my professor.

#ifndef SONGCOLLECTION_H
#define SONGCOLLECTION_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <fstream>
#include <string>
#include <iomanip>

namespace sdds {
	struct Song {
		std::string album{};
		std::string artist{};
		std::string title{};
		size_t song_year{};
		size_t song_length{};
		double m_price{};


	};

	class SongCollection {
		std::vector<Song> co;
	
	public:
		bool inCollection(std::string coName) const;
		std::list<Song> getSongsForArtist(std::string artistName) const;
		void display(std::ostream& ostream) const;
		void sort(std::string string);
		void cleanAlbum();
		SongCollection(const char* fileName);

	};

	std::ostream& operator<<(std::ostream& ostream, const Song& theSong);
}
#endif
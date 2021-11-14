
/********************************************
	Name   :Heeyeon Han
	ID     : 154222194
	Email  : hhan34@myseneca.ca
	Section: OOP345ZAA
	Date: 2021/11/14
*********************************************/
//I confirm that the content of this file is created by me, with the exception of the parts provided to me by my professor.
#include "SongCollection.h"
using namespace std;

namespace sdds {
	int total = 0;
	int hour, min, sec = 0;
	int meterSec = 3600;
	int second = 60;
	size_t SIZEOFCHARACTER = 25;
	size_t SIZEOFNUMBER = 5;


	SongCollection::SongCollection(const char* fileName) {
		ifstream file(fileName);

		if (file)
		{
			while (!file.eof())
			{

				//title
				string emptyString = "";
				getline(file, emptyString);
				string title = emptyString.substr(0, SIZEOFCHARACTER);;
				title.erase(0, title.find_first_not_of(" "));
				title.erase(title.find_last_not_of(" ") + 1);
				emptyString.erase(0, SIZEOFCHARACTER);

				//artist
				string artist = emptyString.substr(0, SIZEOFCHARACTER);
				artist.erase(0, artist.find_first_not_of(" "));
				artist.erase(artist.find_last_not_of(" ") + 1);
				emptyString.erase(0, SIZEOFCHARACTER);

				//album
				string album = emptyString.substr(0, SIZEOFCHARACTER);
				album.erase(0, album.find_first_not_of(" "));
				album.erase(album.find_last_not_of(" ") + 1);
				emptyString.erase(0, SIZEOFCHARACTER);

				//year 
				string year = emptyString.substr(0, SIZEOFNUMBER);
				year.erase(0, year.find_first_not_of(" "));
				year.erase(year.find_last_not_of(" ") + 1);
				emptyString.erase(0, SIZEOFNUMBER);

				//length
				string length = emptyString.substr(0, SIZEOFNUMBER);
				length.erase(0, length.find_first_not_of(" "));
				length.erase(length.find_last_not_of(" ") + 1);
				emptyString.erase(0, SIZEOFNUMBER);

				//price
				string price = emptyString;
				price.erase(0,price.find_first_not_of(" "));
				price.erase(price.find_last_not_of(" ") + 1);

				//Final song 
				Song song;
					if (year == "")
						song.song_year = 0;
					else
						song.song_year = stoi(year);

					song.artist = artist;
					song.title = title;
					song.album = album;
					song.m_price = stod(price);
					song.song_length = stoi(length);
					total = total + song.song_length;

					co.push_back(song);
			}

			file.close();

		}
		else 
			throw "FILE HAVE AN ISSUE!";

	}

	void SongCollection::display(ostream& ostream) const {

		for_each(co.begin(), co.end(), [&](const Song& theSong) {
			ostream << theSong << endl;
			});

		min = (total % meterSec) / second;
		sec = (total % meterSec) % second;
		hour = total / meterSec;

		ostream << setw(89) << setfill('-') << '\n' << setfill(' ') << "| " << right << setw(77) << "Total Listening Time: " << hour << ":" << min << ":" << sec << " |" << endl;
	}

	void SongCollection::sort(string string) {
		
		if (string == "title")
		{
			std::sort(co.begin(), co.end(), [](const Song& song, const Song& secondSong) {
				
				return song.title < secondSong.title; });
		}
		
		if (string == "album") {
			std::sort(co.begin(), co.end(), [](const Song& song, const Song& secondSong) {return song.album < secondSong.album; });
		}

		if (string == "length") {
			std::sort(co.begin(), co.end(), [](const Song& song, const Song& secondSong) {return song.song_length < secondSong.song_length; });
		}

	}

	bool SongCollection::inCollection(string naming) const {
		auto validation = find_if(co.begin(), co.end(), [&naming](const Song& song) {
			return song.artist == naming;
			});

		return validation != co.end();
	}


	void SongCollection::cleanAlbum() {

		for_each(co.begin(), co.end(), [](Song& theSong) {
			if (theSong.album == "[None]")
				theSong.album = " ";
			});
	}




	ostream& operator<<(ostream& ostream, const Song& theSong) {

		ostream << "| " << setw(20) << left << theSong.title << " | " << setw(15) << theSong.artist << " | " << setw(20) << theSong.album << " | " << setw(second/10);
		
		if (theSong.song_year > 0)
			ostream << right << setw(second / 10) << theSong.song_year;
		else 
			ostream << right << setw(second / 10) << " ";

		ostream << " | " << right << theSong.song_length / second << ":" << setw(2) << setfill('0') << theSong.song_length % second << setfill(' ') << " | " << theSong.m_price << " |";

		return ostream;
	}


	list<Song> SongCollection::getSongsForArtist(string naming) const {
		auto OFcount = count_if(co.begin(), co.end(), [&naming](const Song& theSong)
			{
				return theSong.artist == naming;
			});

		list<Song>collections(OFcount);

		copy_if(co.begin(), co.end(), collections.begin(), [&naming](const Song& theSong)
			{
				return theSong.artist == naming;
			});

		return collections;
	}

}
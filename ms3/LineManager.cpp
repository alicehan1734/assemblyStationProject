
/********************************************
	Name   :Heeyeon Han
	ID     : 154222194
	Email  : hhan34@myseneca.ca
	Section: OOP345ZAA
	Date: 2021/12/02
*********************************************/
//I confirm that the content of this file is created by me, with the exception of the parts provided to me by my professor.


#include "LineManager.h"

using namespace std;

namespace sdds {

	void LineManager::display(std::ostream& os) const {
		for (size_t i = 0; i < activeLine.size(); i++)
		{
			activeLine.at(i)->display(os);
		}
	}
	void LineManager::linkStations() {
		const Workstation* work = m_firstStation;
		size_t i = 0;

		do
		{
			activeLine[i++] = const_cast<Workstation*>(work);
			work = work->getNextStation();
		} while (work != nullptr);
	}

	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) {
		Utilities utilities;

		ifstream doc(file);

		if (!doc)
			throw string("Sorry, I cannot open the file");

		else {
			bool checking;

			Workstation* nowStation = nullptr;
			Workstation* before = nullptr;
			Workstation* next = nullptr;

			string checkingLine = "";
			string word = "";
			string curentWord = "";

			size_t pos = 0;


			while (getline(doc, checkingLine))
			{
				curentWord = utilities.extractToken(checkingLine, pos, checking);
				nowStation = *find_if(stations.begin(), stations.end(), [&](Workstation* stations) {
					return stations->getItemName() == curentWord; });
				activeLine.push_back(nowStation);
				
				if (checking)
				{
					word = utilities.extractToken(checkingLine, pos, checking);

					next = *find_if(stations.begin(), stations.end(), [&](Workstation* stations) {
					
						return stations->getItemName() == word;});


					nowStation->setNextStation(next);
				}
				else {

				}
			}
			for_each(stations.begin(), stations.end(), [&](Workstation* temp) {
				before = *find_if(stations.begin(), stations.end(), [&](Workstation* station) { return station->getNextStation() == before; });
				});
			m_firstStation = before;
		}
		doc.close();
		m_cntCustomerOrder = pending.size();
	}

	bool LineManager::run(std::ostream& os) {
		static size_t cccc = 1;
		bool checking = false;

		os << "Line Manager Iteration: " << cccc++ << endl;

		if (!pending.empty())
		{
			*m_firstStation += move(pending.front());
			pending.pop_front();
		}
		else {

		}

		for (size_t i = 0; i < activeLine.size(); i++)
		{
			activeLine[i]->fill(os);
		}

		for (size_t i = 0; i < activeLine.size(); i++)
		{
			activeLine[i]->attemptToMoveOrder();
		}

		if (completed.size() + incomplete.size() == m_cntCustomerOrder)
		{
			checking = true;
		}
		else {

		}
		
		return checking;
	}


}
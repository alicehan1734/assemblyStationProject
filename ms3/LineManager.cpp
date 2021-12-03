
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

		ifstream doc(file);
		Utilities utilities;

		if (!doc)
		{
			throw string("Sorry, I cannot open the file");
		}
		else {
			string eachLine = "";
			string currWord = "";
			string nextWord = "";
			Workstation* currStation = nullptr;
			Workstation* pastStation = nullptr;
			Workstation* nextStation = nullptr;
			size_t pos = 0;
			bool flag;

			while (getline(doc, eachLine))
			{
				currWord = utilities.extractToken(eachLine, pos, flag);
				currStation = *find_if(stations.begin(), stations.end(), [&](Workstation* stations) {
					return stations->getItemName() == currWord; });
				activeLine.push_back(currStation);
				if (flag)
				{
					nextWord = utilities.extractToken(eachLine, pos, flag);
					nextStation = *find_if(stations.begin(), stations.end(), [&](Workstation* stations) {
						return stations->getItemName() == nextWord;
						});
					currStation->setNextStation(nextStation);
				}
			}
			for_each(stations.begin(), stations.end(), [&](Workstation* temp) {
				pastStation = *find_if(stations.begin(), stations.end(), [&](Workstation* station) { return station->getNextStation() == pastStation; });
				});
			m_firstStation = pastStation;
		}
		doc.close();
		m_cntCustomerOrder = pending.size();
	}


	bool LineManager::run(std::ostream& os) {
		static size_t count = 1;
		bool flag = false;

		os << "Line Manager Iteration: " << count++ << endl;

		if (!pending.empty())
		{
			*m_firstStation += move(pending.front());
			pending.pop_front();
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
			flag = true;
		}
		
		return flag;
	}

	void LineManager::display(std::ostream& os) const {
		for (size_t i = 0; i < activeLine.size(); i++)
		{
			activeLine.at(i)->display(os);
		}
	}
}
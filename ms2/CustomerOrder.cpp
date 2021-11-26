
/********************************************
   Name   :Heeyeon Han
   ID     : 154222194
   Email  : hhan34@myseneca.ca
   Section: OOP345ZAA
   Date: 2021/11/25
*********************************************/
//I confirm that the content of this file is created by me, with the exception of the parts provided to me by my professor.

#include "CustomerOrder.h"

using namespace std;
namespace sdds {

    size_t CustomerOrder::m_widthField = 0;

    CustomerOrder::CustomerOrder(const std::string& string) {
        Utilities utilities;
        size_t sizeNum = 0;
        bool ext = true;

        m_name = utilities.extractToken(string, sizeNum, ext);
        m_product = utilities.extractToken(string, sizeNum, ext);
        m_cntItem = 0;

        auto temp2 = sizeNum;

        while (ext)
        {
            utilities.extractToken(string, sizeNum, ext);
            m_cntItem++;
        }

        m_lstItem = new Item * [m_cntItem];

        ext = true;

        for (size_t i = 0; i < m_cntItem; i++)
        {
            m_lstItem[i] = new Item(utilities.extractToken(string, temp2, ext));
        }

        if (utilities.getFieldWidth() > m_widthField)
            m_widthField = utilities.getFieldWidth();
    }



    CustomerOrder& CustomerOrder::operator=(CustomerOrder&& object)noexcept {
        if (this != &object)
        {
            for (size_t i = 0; i < m_cntItem; i++)
            {
                delete m_lstItem[i];
            }
            delete[] m_lstItem;
            m_name = object.m_name;
            object.m_name = "";
            m_product = object.m_product;
            object.m_product = "";
            m_cntItem = object.m_cntItem;
            object.m_cntItem = 0;
            m_lstItem = object.m_lstItem;
            object.m_lstItem = nullptr;
        }
        return *this;
    }

    CustomerOrder::CustomerOrder(const CustomerOrder& object) {
        throw "The copy operator is not allowed here";
    }

    CustomerOrder::CustomerOrder(CustomerOrder&& object)noexcept {
        *this = move(object);
    }

    CustomerOrder::~CustomerOrder() {
        for (size_t i = 0; i < m_cntItem; i++)
        {
            delete m_lstItem[i];
            m_lstItem[i] = nullptr;
        }
        delete[] m_lstItem;
        m_lstItem = nullptr;
    }

    bool CustomerOrder::isFilled() const {
        bool result = true;
        for (size_t i = 0; i < m_cntItem; i++)
        {
            if (!m_lstItem[i]->m_isFilled)
                result = false;
        }
        return result;
    }

    bool CustomerOrder::isItemFilled(const std::string& itemName) const {
        bool result = true;
        for (size_t i = 0; i < m_cntItem; i++)
        {
            if (m_lstItem[i]->m_itemName == itemName)
                result = m_lstItem[i]->m_isFilled;
        }
        return result;
    }

    void CustomerOrder::fillItem(Station& station, std::ostream& ostream) {
        for (size_t i = 0; i < m_cntItem; i++)
        {
            if (station.getItemName() == m_lstItem[i]->m_itemName)
            {
                if (station.getQuantity() > 0)
                {
                    m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
                    m_lstItem[i]->m_isFilled = true;
                    station.updateQuantity();
                    ostream << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
                }
                else 
                    ostream << "Unable to fill" << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
            }
        }
    }

    void CustomerOrder::display(std::ostream& ostream) const {

        ostream << m_name << " - " << m_product << endl;
        for (size_t i = 0; i < m_cntItem; i++) {
            ostream << "[" << setw(6) << setfill('0') << right << m_lstItem[i]->m_serialNumber << "] " << setfill(' ') << setw(m_widthField) << left << m_lstItem[i]->m_itemName;

            if (m_lstItem[i]->m_isFilled) 
                ostream << " - FILLED" << std::endl;
            else 
                ostream << " - TO BE FILLED" << std::endl;

        }

    }
}
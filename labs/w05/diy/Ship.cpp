// OOP244 Workshop 5: Operator Overloading
// File: Ship.cpp
// Version: 1.0
// Date: 2/21/2020
// Author: Pat Zdanko
// Description:
// Contains the description of the ship class
/////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "Ship.h"
#include <cstring>
#include <iostream>

using namespace std;

namespace sdds {
Ship::Ship()
{
    setEmpty();
}
Ship::Ship(const char* type, Engine* engines, int enginesNo)
{
    setEmpty();
    if (type && type[0] != '\0' && enginesNo > 0) {
        m_tsize = strlen(type);
        m_type = new char[m_tsize + 1];
        strcpy(m_type, type);

        m_engines = new Engine[enginesNo];
        for (int i = 0; i < enginesNo; i++) {
            m_engines[i] = engines[i];
        }
        m_enginesNo = enginesNo;
    }
}
Ship::~Ship()
{
    clearTypeMemory();
    clearEnginesMemory();
}
void Ship::clearTypeMemory()
{
    delete[] m_type;
    m_type = nullptr;
    m_tsize = 0;
}
void Ship::clearEnginesMemory()
{
    delete[] m_engines;
    m_engines = nullptr;
    m_enginesNo = 0;
}
void Ship::setEmpty()
{
    m_type = nullptr;
    m_tsize = 0;
    m_engines = nullptr;
    m_enginesNo = 0;
}
bool Ship::empty() const
{
    return (m_tsize == 0);
}
double Ship::calculatePower() const
{
    double powerSum = 0;
    for (int i = 0; i < m_enginesNo; i++) {
        powerSum += (m_engines[i].get() * 5);
    }
    return powerSum;
}
void Ship::display() const
{
    if (!empty()) {
        cout << m_type << "-";
        cout.setf(ios::fixed);
        cout.precision(2);
        cout.width(6);
        cout << calculatePower() << endl;
        for (int i = 0; i < m_enginesNo; i++) {
            m_engines[i].display();
        }
    } else {
        cout << "No available data" << endl;
    }
}
const Ship& Ship::operator+=(Engine e)
{
    if (!empty()) {
        Engine* tempEng = nullptr;
        int tempEngNo = m_enginesNo + 1;
        tempEng = new Engine[tempEngNo];
        for (int i = 0; i < m_enginesNo; i++) {
            tempEng[i] = m_engines[i];
        }
        tempEng[m_enginesNo] = e;
        //clears the old array
        clearEnginesMemory();
        //redefnes the member array to the temp array
        m_enginesNo = tempEngNo;
        m_engines = new Engine[m_enginesNo];
        for (int i = 0; i < m_enginesNo; i++) {
            m_engines[i] = tempEng[i];
        }
        //delete temp pointer
        delete[] tempEng;
        tempEng = nullptr;
    } else {
        cout << "The ship doesn't have a type! Engine cannot be added!" << endl;
    }
    return *this;
}
bool operator==(const Ship& ship1, const Ship& ship2)
{
    bool same = (ship1.calculatePower() == ship2.calculatePower());
    return same;
}
bool operator<(const Ship& ship, double standard)
{
    bool lessThan = (ship.calculatePower() < standard);
    return lessThan;
}
} // namespace sdds
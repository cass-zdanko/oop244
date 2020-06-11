// OOP244 Workshop 5: Operator Overloading
// File: Ship.cpp
// Version: 1.0
// Date: 2/13/2020
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
    if (type && type[0] != '\0' && strlen(type) < 7 && enginesNo > 0) {
        strcpy(m_type, type);
        for (int i = 0; i < enginesNo; i++) {
            m_engines[i] = engines[i];
        }
        m_enginesNo = enginesNo;
    }
}
Ship::~Ship() {}
void Ship::setEmpty()
{
    m_type[0] = '\0';
    m_enginesNo = 0;
}
bool Ship::empty() const
{
    return (m_type[0] == '\0');
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
        if (m_enginesNo < 10) {
            m_engines[m_enginesNo++] = e;
        } else {
            cout << "The ship has no more room! Engine cannot be added!" << endl;
        }
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
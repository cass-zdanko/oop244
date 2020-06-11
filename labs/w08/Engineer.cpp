// OOP244 Workshop 8: virtual functions
// File: Engineer.h
// Version: 1.0
// Date: 03/27/2020
// Author: Pat Zdanko
// Description:
// Implementation for the Engineer class
/////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

#include "Engineer.h"

namespace sdds {
Engineer::Engineer() {
    setEmpty();
}
Engineer::Engineer(double esalary, int ewhours, int level) {
    setEmpty();
    if (esalary > 0 && ewhours > 0 && level > 0) {
        m_ewhours = ewhours;
        m_level = level;
        setSalary(esalary);
    }
}
void Engineer::setEmpty() {
    m_esalary = 0;
    m_ewhours = 0;
    m_level = 0;
}
void Engineer::setSalary(double salary) {
    m_esalary = salary;
    if (m_level >= MAX_LEVEL) {
        m_esalary += 3000;
    }
}
void Engineer::bonus() {
    if (workHours() && m_level >= MAX_LEVEL) {
        m_esalary *= 1.10;
    } else {
        m_esalary *= 1.05;
    }
}
bool Engineer::workHours() {
    return (m_ewhours > MIN_HOURS);
}
ostream& Engineer::display(ostream& os) const {
    if (m_esalary > 0 && m_ewhours > 0) {
        os << "Engineer details" << endl;
        os << "level: " << m_level << endl;
        os << "Salary: ";
        os.setf(ios::fixed);
        os.precision(2);
        os << m_esalary << endl;
        os << "Working hours: " << m_ewhours << endl;
    } else {
        os << "Engineer is not initiated yet" << endl;
    }
    return os;
}
}
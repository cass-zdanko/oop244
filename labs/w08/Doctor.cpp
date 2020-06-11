// OOP244 Workshop 8: virtual functions
// File: Doctor.cpp
// Version: 1.0
// Date: 03/27/2020
// Author: Pat Zdanko
// Description:
// Implementation for the Doctor class
/////////////////////////////////////////////////////////////////
#include <cstring>
#include <iostream>

using namespace std;

#include "Doctor.h"

namespace sdds {
Doctor::Doctor() {
    setEmpty();
}
Doctor::Doctor(const char* type, double salary, int whours, bool specialist) {
    setEmpty();
    if (type && strlen(type) > 0 && salary > 0 && whours > 0) {
        strcpy(m_type, type);
        m_whours = whours;
        m_specialist = specialist;
        setSalary(salary);
    }
}
void Doctor::setEmpty() {
    strcpy(m_type, "");
    m_salary = 0;
    m_whours = 0;
    m_specialist = false;
}
void Doctor::setSalary(double salary) {
    m_salary = salary;
    if (m_specialist) {
        m_salary += 2000;
    }
}
void Doctor::bonus() {
    if (workHours()) {
        m_salary *= 1.10;
    } else {
        m_salary *= 1.05;
    }
}
bool Doctor::workHours() {
    return (m_whours > MIN_W_HOURS);
}
ostream& Doctor::display(ostream& os) const {
    if (strlen(m_type) > 0 && m_salary > 0 && m_whours > 0) {
        os << "Doctor details" << endl;
        os << "Doctor Type: " << m_type << endl;
        os << "Salary: ";
        os.setf(ios::fixed);
        os.precision(2);
        os << m_salary << endl;
        os << "Working Hours: " << m_whours << endl;
    } else {
        os << "Doctor is not initiated yet" << endl;
    }
    return os;
}
}
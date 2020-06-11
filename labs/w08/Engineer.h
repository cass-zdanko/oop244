// OOP244 Workshop 8: virtual functions
// File: Engineer.h
// Version: 1.0
// Date: 03/27/2020
// Author: Pat Zdanko
// Description:
// Header file for the Engineer class
/////////////////////////////////////////////////////////////////
#pragma once
#ifndef SDDS_ENGINEER_H__
#define SDDS_ENGINEER_H__

#include "Employee.h"

namespace sdds {
const int MIN_HOURS = 5;
const int MAX_LEVEL = 4;
class Engineer : public Employee {
private:
    double m_esalary;
    int m_ewhours;
    int m_level;

public:
    Engineer();
    Engineer(double esalary, int ewhours, int level);
    ~Engineer() {};
    void setEmpty();
    void setSalary(double salary);
    void bonus();
    bool workHours();
    ostream& display(ostream& os) const;
};
}

#endif // !SDDS_ENGINEER_H__
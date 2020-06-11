// OOP244 Workshop 8: virtual functions
// File: Doctor.h
// Version: 1.0
// Date: 03/27/2020
// Author: Pat Zdanko
// Description:
// Header file for the Doctor class
/////////////////////////////////////////////////////////////////
#pragma once
#ifndef SDDS_DOCTOR_H__
#define SDDS_DOCTOR_H__

#include "Employee.h"

namespace sdds {
const int MIN_W_HOURS = 6;
const int MAX_CHAR = 20;
class Doctor : public Employee {
private:
    char m_type[MAX_CHAR + 1];
    double m_salary;
    int m_whours;
    bool m_specialist;

public:
    Doctor();
    Doctor(const char* type, double salary, int whours, bool specialist = false);
    void setEmpty();
    void setSalary(double salary);
    void bonus();
    bool workHours();
    ostream& display(ostream& os) const;
};
}

#endif // !SDDS_DOCTOR_H__
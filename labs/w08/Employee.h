// OOP244 Workshop 8: virtual functions
// File: Employee.h
// Version: 1.0
// Date: 03/27/2020
// Author: Pat Zdanko
// Description:
// Base class for doctor and engineer class
/////////////////////////////////////////////////////////////////

#pragma once
#ifndef SDDS_EMPLOYEE_H__
#define SDDS_EMPLOYEE_H__

#include <iostream>
using namespace std;

namespace sdds {
class Employee {
public:
    virtual void setEmpty() = 0;
    virtual void setSalary(double salary) = 0;
    virtual void bonus() = 0;
    virtual bool workHours() = 0;
    virtual ostream& display(ostream& os) const = 0;
    virtual ~Employee() {}
};
}

#endif // !SDDS_EMPLOYEE_H__
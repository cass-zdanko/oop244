/* Citation and Sources...
Final Project Milestone 5
Module: Motorcycle
Filename: Motorcycle.h
Version 1.0
Author: Pat Zdanko
Student Id: 129430195
Revision History 
-----------------------------------------------------------
Date       Reason
2020/04/07 Initial Submission
----------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments. 
-----------------------------------------------------------*/
#pragma once
#ifndef SDDS_MOTORCYCLE_H__
#define SDDS_MOTORCYCLE_H__

#include "Vehicle.h"
#include <iostream>

namespace sdds {
class Motorcycle : public Vehicle {
private:
    bool m_sideCar;

public:
    Motorcycle();
    Motorcycle(const char* license, const char* makeModel);
    Motorcycle(const Motorcycle&) = delete;
    Motorcycle& operator=(const Motorcycle&) = delete;
    std::istream& read(std::istream& is);
    std::ostream& write(std::ostream& os) const;
};
}

#endif
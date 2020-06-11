/* Citation and Sources...
Final Project Milestone 5
Module: Car
Filename: Car.h
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
#ifndef SDDS_CAR_H__
#define SDDS_CAR_H__

#include "Vehicle.h"
#include <iostream>
using namespace std;

namespace sdds {
class Car : public Vehicle {
private:
    bool m_carWash;

public:
    Car();
    Car(const char* license, const char* makeModel);
    Car(const Car&) = delete;
    Car& operator=(const Car&) = delete;
    std::istream& read(std::istream& is);
    std::ostream& write(std::ostream& os) const;
};
}

#endif